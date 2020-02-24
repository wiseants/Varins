using HVision.Varins.Interfaces;
using HVision.Varins.Models;
using Prism.Interactivity.InteractionRequest;
using Prism.Regions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using HVision.Varins.Cores;
using Microsoft.Win32;
using HVision.Common.Tool;
using HVision.Varins.Modules;
using Microsoft.WindowsAPICodePack.Dialogs;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Results;
using HVision.Varins.Models.Grab;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models.Drawing;
using HVision.Common.Interface;
using Newtonsoft.Json;
using HVision.Varins.Interfaces.Drawing;
using HVision.Varins.JsonConverters;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Common;
using HVision.Common.Cores.Shapes;
using HVision.Matrox;

namespace HVision.Varins.ViewModels.Windows
{
    public partial class MainWindowViewModel
    {
		#region Public methods

		public void Loaded()
		{
			foreach (string name in Properties.Settings.Default.ImageNames)
			{
				GrabInfo grabInfo = _container.Resolve<GrabInfo>();
				grabInfo.Name = name;

				GrabInfoMap.Add(name, grabInfo);
			}

			for (int i = 0; i < Properties.Settings.Default.GrabberNames.Count; i++)
			{
				GrabberController controller = _container.Resolve<GrabberController>(
					new ResolverOverride[]
					{
						new ParameterOverride("grabber", _container.Resolve<IGrabber>(Properties.Settings.Default.GrabberNames[i]))
					});
				controller.GrabInfoMap = GrabInfoMap;

				GrabberControllerMap.Add(i, controller);
				controller.FinishedGrab += App.Locator.DisplayViewModel.ImageViewModel.FinishedGrab;
			}

			App.Locator.GrabViewModel.GrabberController = GrabberControllerMap[0];
		}

		public void Closed()
		{
			MilSystem.Instance().Release();
			MilApplication.Instance().Release();
		}

		public bool? OpenLoginWindow()
		{
			var loginWindowviewModel = 
				_container.Resolve<LoginWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.LOGIN_WINDOW));
			loginWindowviewModel.AccountInfoMap = AccountInfoMap;

			bool? result = OpenWindowEvent(this, UnityNameTool.ConvertViewName(Constant.LOGIN_WINDOW), loginWindowviewModel);
			if (result == true)
			{
				CurrentAccount = loginWindowviewModel.ConfirmedAccount;
			}

			return result;
		}

		public bool? OpenResultWindow(IInspectedResult inspectedResult)
		{
			var resultWindowviewModel =
				_container.Resolve<IResultWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.RESULT_WINDOW));
			resultWindowviewModel.InspectedResult = inspectedResult;

			bool? result = OpenWindowEvent(this, UnityNameTool.ConvertViewName(Constant.RESULT_WINDOW), resultWindowviewModel);

			return result;
		}

		public void Close()
		{
			OnCloseEvent(this, true);
		}

		public void NewRecipe()
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog
			{
				IsFolderPicker = true,
			};

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				Recipe newRecipe = _container.Resolve<Recipe>();
				newRecipe.Name = "Test";
				newRecipe.Path = dialog.FileName;

				foreach (string name in Properties.Settings.Default.DrawingNames)
				{
					DrawingController newController = _container.Resolve<DrawingController>(
					name,
					new ResolverOverride[]
					{
						new ParameterOverride("drawing", _container.Resolve<IDrawing>(name)),
					});

					newRecipe.DrawingControllerMap.Add(name, newController);
				}

				foreach (string name in Properties.Settings.Default.AlgorithmNames)
				{
					SpecController newController = _container.Resolve<SpecController>(
						new ResolverOverride[]
						{
						new ParameterOverride("spec", _container.Resolve<ISpec>(name))
						});

					newRecipe.SpecControllerMap.Add(name, newController);
				}

				CurrentRecipe = newRecipe;
			}
		}

		public void OpenRecipe()
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog
			{
				IsFolderPicker = false
			};

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				string fileName;
				fileName = dialog.FileName;

				CurrentRecipe = JsonTool<Recipe>.Import(fileName, new JsonSerializerSettings()
				{
					ContractResolver = _container.Resolve<ConverterContractResolver>()
				});
			}
		}

		public void CloseRecipe()
		{
			CurrentRecipe = null;
		}

		public void SaveRecipe()
		{
			JsonTool<Recipe>.Export(CurrentRecipe.FullPath, CurrentRecipe);
		}

		public void SaveAsRecipe()
		{

		}

		public void DoInspect()
		{
			if (CurrentRecipe == null)
			{
				return;
			}

			int id = 0;
			//아이디에 따른 검사 반복이 필요. 추후 수정 필요.
			IParameter parameter = CreateParameter(id);
			parameter.Id = DateTime.Now.ToString();

			IInspectedResult inspectedResult = _container.Resolve<IInspectedResult>();
			inspectedResult.Id = parameter.Id;
			inspectedResult.ResultType = ResultType.Ng;
			foreach (string name in Properties.Settings.Default.AlgorithmNames)
			{
				IAlgorithm algorithm = _container.Resolve<IAlgorithm>(name);
				if (algorithm.DoInspect(parameter, ref inspectedResult) == false)
				{
					break;
				}
			}

			IMessageInfo messageInfo = _container.Resolve<IMessageInfo>();
			messageInfo.Level = 1;
			messageInfo.Category = "검사";
			messageInfo.Description = inspectedResult.Description;
			App.Locator.MessageViewModel.MessageInfoList.Add(messageInfo);

			OpenResultWindow(inspectedResult);

			string filePath = String.Format(@"{0}\Result\{1}.json", FolderTool.WorkingFolderFullPath, DateTime.Now.ToString("yyyyMMdd-HHmmss"));
			JsonTool<IInspectedResult>.Export(filePath, inspectedResult);
		}

		#endregion

		#region Private methods

		private IParameter CreateParameter(int id)
		{
			Parameter parameter = _container.Resolve<Parameter>();

			var shapeControllers = CurrentRecipe.DrawingControllerMap.ToDictionary
				(
					x => x.Key,
					x => x.Value.ShapeControllerList.Select(y => y.Shape.Clone() as EditableShape)
				);
			parameter.EditableShapesMap = new Dictionary<string, IEnumerable<EditableShape>>(shapeControllers);

			GrabberController controller = GrabberControllerMap[id];
			if (controller == null)
			{
				return parameter;
			}

			parameter.GrabImageMap = new Dictionary<String, IGrabImage>();
			foreach (GrabInfo info in controller.GrabInfoMap.Values)
			{
				if (controller.Grabber.TryGrab(info, out IGrabImage grabImage) == true)
				{
					parameter.GrabImageMap.Add(info.Name, grabImage);
				}
			}

			parameter.SpecMap = new Dictionary<string, ISpec>(
				CurrentRecipe.SpecControllerMap.Select(x => x.Value.Spec).ToDictionary(x => x.Name));

			return parameter;
		}


		#endregion
	}
}

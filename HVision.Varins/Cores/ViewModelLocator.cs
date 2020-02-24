using HVision.Common.Tool;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.ServiceLocation;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins.Cores
{
	public class ViewModelLocator
	{
		#region Fields

		private readonly IUnityContainer _container = null;
		private readonly Dictionary<Type, object> _viewModelMap = new Dictionary<Type, object>();

		#endregion

		#region Constructors

		public ViewModelLocator(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		public IMainWindowViewModel MainWindowViewModel
		{
			get
			{
				return CreateViewModel<IMainWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.MAIN_WINDOW));
			}
		}

		public IMenuViewModel MenuViewModel
		{
			get
			{
				return CreateViewModel<IMenuViewModel>(UnityNameTool.ConvertViewModelName(Constant.MENU_PANE));
			}
		}

		public IDisplayViewModel DisplayViewModel
		{
			get
			{
				return CreateViewModel<IDisplayViewModel>(UnityNameTool.ConvertViewModelName(Constant.DISPLAY_PANE));
			}
		}

		public IInfoViewModel InfoViewModel
		{
			get
			{
				return CreateViewModel<IInfoViewModel>(UnityNameTool.ConvertViewModelName(Constant.INFO_PANE));
			}
		}

		public IMessageViewModel MessageViewModel
		{
			get
			{
				return CreateViewModel<IMessageViewModel>(UnityNameTool.ConvertViewModelName(Constant.MESSAGE_PANE));
			}
		}

		public IGrabViewModel GrabViewModel
		{
			get
			{
				return CreateViewModel<IGrabViewModel>(UnityNameTool.ConvertViewModelName(Constant.GRAB_PANE));
			}
		}

		public IDrawingViewModel DrawingViewModel
		{
			get
			{
				return CreateViewModel<IDrawingViewModel>(UnityNameTool.ConvertViewModelName(Constant.DRAWING_PANE));
			}
		}

		public ISpecListViewModel SpecListViewModel
		{
			get
			{
				return CreateViewModel<ISpecListViewModel>(UnityNameTool.ConvertViewModelName(Constant.SPECLIST_PANE));
			}
		}

		#endregion

		#region Private methods

		private T CreateViewModel<T>(string name)
		{
			Type type = typeof(T);

			if (_viewModelMap.TryGetValue(type, out object existedValue) == false)
			{
				existedValue = _container.Resolve<T>(name);
				_viewModelMap[type] = existedValue;
			}

			return (T)existedValue;
		}

		#endregion
	}
}

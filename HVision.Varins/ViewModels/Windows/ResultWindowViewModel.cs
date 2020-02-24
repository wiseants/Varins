using HVision.Common;
using HVision.Common.Interface;
using HVision.Varins.Interfaces.Results;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.ViewModels.Controls;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Shapes;

namespace HVision.Varins.ViewModels.Windows
{
	public class ResultWindowViewModel : BindableBase, IResultWindowViewModel, IWindowHandler
	{
		public event OpenWindowEventHandler OpenWindowEvent;
		public event CloseEventHandler OnCloseEvent;

		private readonly IUnityContainer _container = null;
		private IImageViewModel _resultViewModel = null;
		private IInspectedResult _inspectedResult = null;
		private ObservableCollection<IResultObject> _resultObjectList = null;
		private IResultObject _selectedResultObject = null;

		public ResultWindowViewModel(IUnityContainer container)
		{
			_container = container;

			ResultViewModel = container.Resolve<ResultViewModel>();
		}

		public IInspectedResult InspectedResult
		{
			get { return _inspectedResult; }
			set
			{
				SetProperty(ref _inspectedResult, value);

				ResultObjectList = new ObservableCollection<IResultObject>(_inspectedResult.ResultObjectMap.Values);
			}
		}

		public ObservableCollection<IResultObject> ResultObjectList
		{
			get { return _resultObjectList; }
			set
			{
				SetProperty(ref _resultObjectList, value);

				if (ResultObjectList.Count > 0)
				{
					SelectedResultObject = ResultObjectList.First();
				}
			}
		}

		public IResultObject SelectedResultObject
		{
			get { return _selectedResultObject; }
			set
			{
				SetProperty(ref _selectedResultObject, value);

				ResultViewModel.CurrentImage = SelectedResultObject.GrabImageMap.Values.First();
				ResultViewModel.ShapeList = new ObservableCollection<Shape>(SelectedResultObject.ShapeMap.Values);
			}
		}

		public IImageViewModel ResultViewModel
		{
			get { return _resultViewModel; }
			set { SetProperty(ref _resultViewModel, value); }
		}
	}
}

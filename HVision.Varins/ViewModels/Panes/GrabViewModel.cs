using HVision.Common.Mvvm;
using HVision.Common.Tool;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models.Grab;
using HVision.Varins.ViewModels.Controls;
using HVision.Varins.Views.Controls;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Microsoft.WindowsAPICodePack.Dialogs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace HVision.Varins.ViewModels.Panes
{
    public class GrabViewModel : BindableBase, IGrabViewModel
	{
		private readonly IUnityContainer _container = null;
		private int _selectedTabIndex = 0;
		private ObservableDictionary<string, GrabInfoView> _controls = new ObservableDictionary<string, GrabInfoView>();
		private ObservableDictionary<string, GrabInfoViewModel> _viewModels = new ObservableDictionary<string, GrabInfoViewModel>();
		private GrabberController _grabberController = null;

		public GrabViewModel(IUnityContainer container)
		{
			_container = container;
		}

		private void NewViewModel_StartedGrab(object sender, GrabInfo grabInfo)
		{
			if (GrabberController == null)
			{
				return;
			}

			GrabberController.Grabber.AsyncGrab(grabInfo);
		}

		public int SelectedTabIndex
		{
			get => _selectedTabIndex;
			set { SetProperty(ref _selectedTabIndex, value); }
		}

		public ObservableDictionary<string, GrabInfoView> TabItemMap
		{
			get => _controls;
			set { SetProperty(ref _controls, value); }
		}

		public ObservableDictionary<string, GrabInfoViewModel> ViewModels
		{
			get => _viewModels;
			set { SetProperty(ref _viewModels, value); }
		}

		public GrabberController GrabberController
		{
			get => _grabberController;
			set
			{
				SetProperty(ref _grabberController, value);

				if (_grabberController == null)
				{
					return;
				}

				foreach (var pair in _grabberController.GrabInfoMap)
				{
					GrabInfoView newControl = _container.Resolve<GrabInfoView>();
					GrabInfoViewModel newViewModel = _container.Resolve<GrabInfoViewModel>();
					newViewModel.Name = pair.Key;
					newViewModel.GrabInfo = pair.Value;
					newViewModel.StartedGrab += NewViewModel_StartedGrab;

					newControl.DataContext = newViewModel;

					TabItemMap.Add(pair.Key, newControl);
					ViewModels.Add(pair.Key, newViewModel);
				}
			}
		}
	}
}

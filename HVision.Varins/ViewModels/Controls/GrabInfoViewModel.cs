using HVision.Common.Mvvm;
using HVision.Varins.Models.Grab;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Microsoft.WindowsAPICodePack.Dialogs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows.Media.Imaging;

namespace HVision.Varins.ViewModels.Controls
{
	public class GrabInfoViewModel : BindableBase
	{
		public event Grabbing StartedGrab;

		private readonly IUnityContainer _container = null;
		private string _name = String.Empty;
		private GrabInfo _grabInfo = null;

		public GrabInfoViewModel(IUnityContainer container)
		{
			_container = container;

			_grabInfo = _container.Resolve<GrabInfo>();

			GrabCommand = new KentDelegateCommand(Grab);
		}

		public ICommand GrabCommand
		{
			get;
			set;
		}

		public string Name
		{
			get => _name;
			set { SetProperty(ref _name, value); }
		}

		public GrabInfo GrabInfo
		{
			get => _grabInfo;
			set { SetProperty(ref _grabInfo, value); }
		}

		public void Grab()
		{
			StartedGrab?.Invoke(this, GrabInfo);
		}
	}
}

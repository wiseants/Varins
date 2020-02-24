using HVision.Varins.Cores;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using HVision.Varins.ViewModels.Controls;
using Microsoft.Practices.Prism.Commands;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;

namespace HVision.Varins.ViewModels.Panes
{
	public class DisplayViewModel : BindableBase, IDisplayViewModel
    {
		private readonly IUnityContainer _container = null;
		private IImageViewModel _imageViewModel = null;

		public DisplayViewModel(IUnityContainer container)
        {
			_container = container;

			ImageViewModel = container.Resolve<ImageViewModel>();
		}

		public IImageViewModel ImageViewModel
		{
			get { return _imageViewModel; }
			set { SetProperty(ref _imageViewModel, value); }
		}
	}
}

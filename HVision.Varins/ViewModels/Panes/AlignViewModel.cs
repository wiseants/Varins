using HVision.Common.Tool;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.Prism.Commands;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Controls;
using System.Windows.Input;

namespace HVision.Varins.ViewModels.Panes
{
	public class AlignViewModel : BindableBase, IAlgorithmViewModel
    {
		private readonly IUnityContainer _container = null;
		private readonly IParameter _parameter = null;

		public AlignViewModel(IUnityContainer container)
		{
			_container = container;

			DrawCommand = new DelegateCommand(Draw);
		}

		public ICommand DrawCommand { get; set; }
		public IParameter Parameter { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

		private void Draw()
		{
		}
	}
}

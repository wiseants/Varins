using HVision.Varins.Cores;
using HVision.Varins.Interfaces;
using Microsoft.Practices.Prism.Commands;
using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Microsoft.Practices.Unity;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Common.Mvvm;
using HVision.Varins.Models;

namespace HVision.Varins.ViewModels.Panes
{
    public class InfoViewModel : BindableBase, IInfoViewModel
    {
		private readonly IUnityContainer _container = null;

        public InfoViewModel(IUnityContainer container)
        {
			_container = container;

			App.Locator.MainWindowViewModel.ChangedRecipe += (object sender, Recipe newRecipe, Recipe oldRecipe) => App.Locator.MainWindowViewModel.CurrentRecipe = newRecipe;
			InspectCommand = new KentDelegateCommand(Inspect, () => App.Locator.MainWindowViewModel.CurrentRecipe != null);
        }

		public ICommand InspectCommand
        {
            get;
            set;
        }

		public void Inspect()
        {
			App.Locator.MainWindowViewModel.DoInspect();
		}
    }
}

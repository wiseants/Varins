using HVision.Common.Mvvm;
using HVision.Common.Tool;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace HVision.Varins.ViewModels.Panes
{
	public class SpecListViewModel : BindableBase, ISpecListViewModel
	{
		#region Fields

		private readonly IUnityContainer _container = null;
		private int _selectedTabIndex = 0;
		private ObservableDictionary<string,UserControl> _controls = new ObservableDictionary<string, UserControl>();

		#endregion

		#region Constructors

		public SpecListViewModel(IUnityContainer container)
		{
			_container = container;

			App.Locator.MainWindowViewModel.ChangedRecipe += App_ChangedRecipe;
		}

		#endregion

		#region Properties

		public int SelectedTabIndex
		{
			get => _selectedTabIndex;
			set { SetProperty(ref _selectedTabIndex, value); }
		}

		public ObservableDictionary<string,UserControl> TabItemMap
		{
			get => _controls;
			set { SetProperty(ref _controls, value); }
		}

		#endregion

		#region Private methods

		private void App_ChangedRecipe(object sender, Recipe newRecipe, Recipe oldRecipe)
		{
			if (oldRecipe != null)
			{
				TabItemMap.Clear();
			}

			if (newRecipe != null)
			{
				foreach (var pair in newRecipe.SpecControllerMap)
				{
					UserControl newControl = _container.Resolve<UserControl>(pair.Key);
					newControl.DataContext = pair.Value;

					TabItemMap.Add(pair.Key, newControl);
				}
			}
		}

		#endregion
	}
}

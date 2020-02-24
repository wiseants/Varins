using HVision.Varins.Cores;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.Prism.Commands;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Prism.Interactivity.InteractionRequest;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace HVision.Varins.ViewModels.Panes
{
	public class MenuViewModel : BindableBase, IMenuViewModel
	{
		private IUnityContainer _container = null;
		public MenuViewModel(IUnityContainer container)
        {
			_container = container;

			ConfirmationRequest = new InteractionRequest<IConfirmation>();

			NewRecipeCommand = new DelegateCommand(NewRecipe);
			OpenRecipeCommand = new DelegateCommand(OpenRecipe);
			CloseRecipeCommand = new DelegateCommand(CloseRecipe);
			SaveRecipeCommand = new DelegateCommand(SaveRecipe);
			SaveAsRecipeCommand = new DelegateCommand(SaveAsRecipe);

			LoginCommand = new DelegateCommand(Login);
			AboutCommand = new DelegateCommand(About);
			ExitCommand = new DelegateCommand(Exit);
        }

		public InteractionRequest<IConfirmation> ConfirmationRequest { get; private set; }

		public ICommand NewRecipeCommand { get; set; }
		public ICommand OpenRecipeCommand { get; set; }
		public ICommand CloseRecipeCommand { get; set; }
		public ICommand SaveRecipeCommand { get; set; }
		public ICommand SaveAsRecipeCommand { get; set; }

		public ICommand LoginCommand { get; set; }
		public ICommand AboutCommand { get; set; }
		public ICommand ExitCommand { get; set; }

		public void NewRecipe()
		{
			App.Locator.MainWindowViewModel.NewRecipe();
		}
		public void OpenRecipe()
		{
			App.Locator.MainWindowViewModel.OpenRecipe();
		}
		public void CloseRecipe()
		{
			App.Locator.MainWindowViewModel.CloseRecipe();
		}
		public void SaveRecipe()
		{
			App.Locator.MainWindowViewModel.SaveRecipe();
		}
		public void SaveAsRecipe()
		{
			App.Locator.MainWindowViewModel.SaveAsRecipe();
		}

		public void Login()
		{
			App.Locator.MainWindowViewModel.OpenLoginWindow();
		}

		public void About()
        {
		}

		public void Exit()
		{
			App.Locator.MainWindowViewModel.Close();
		}
	}
}

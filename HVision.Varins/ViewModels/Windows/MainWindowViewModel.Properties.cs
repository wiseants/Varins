using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using HVision.Varins.Models.Grab;
using HVision.Varins.Modules;
using Prism.Interactivity.InteractionRequest;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;
using Microsoft.Practices.Unity;

namespace HVision.Varins.ViewModels.Windows
{
    public partial class MainWindowViewModel
    {
		#region Properties

		#region Fields

		#endregion

		#region ICommand properties
		public ICommand LoadedCommand
		{
			get;
			set;
		}

		public ICommand ClosedCommand
		{
			get;
			set;
		}

		#endregion

		public AccountInfo CurrentAccount
		{
			get => _currentAccount;
			set
			{
				if (_currentAccount == value)
				{
					return;
				}

				AccountInfo oldAccount = _currentAccount;
				SetProperty(ref _currentAccount, value);
				ChangedAccount?.Invoke(this, value, oldAccount);

				IMessageInfo messageInfo = _container.Resolve<IMessageInfo>();
				messageInfo.Level = 1;
				messageInfo.Category = "계정";
				messageInfo.Description = String.Format("{0} 로그인 성공.", _currentAccount.Id);
				App.Locator.MessageViewModel.MessageInfoList.Add(messageInfo);
			}
		}

		public Recipe CurrentRecipe
		{
			get => _currentRecipe;
			set
			{
				if (_currentRecipe == value)
				{
					return;
				}

				Recipe oldRecipe = _currentRecipe;
				SetProperty(ref _currentRecipe, value);
				ChangedRecipe?.Invoke(this, value, oldRecipe);
			}
		}

		public ObservableDictionary<int, GrabberController> GrabberControllerMap { get; } = new ObservableDictionary<int, GrabberController>();

		public ObservableDictionary<string, GrabInfo> GrabInfoMap { get; } = new ObservableDictionary<string, GrabInfo>();

		public ObservableDictionary<int, RoleInfo> RoleInfoMap { get; } = new ObservableDictionary<int, RoleInfo>()
		{
			{ 0, new RoleInfo() { Index = 0, Authorities = new List<string>() } },
			{ 1, new RoleInfo() { Index = 0, Authorities = new List<string>() { "Recipe", "Inspection" } } }
		};

		public ObservableDictionary<string, AccountInfo> AccountInfoMap { get; } = new ObservableDictionary<string, AccountInfo>();

		#endregion
	}
}

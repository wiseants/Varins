using HVision.Common;
using HVision.Common.Interface;
using HVision.Common.Mvvm;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using Microsoft.Practices.Prism.Commands;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace HVision.Varins.ViewModels.Windows
{
    public class LoginWindowViewModel : BindableBase, ILoginWindowViewModel, IWindowHandler
	{
		private readonly IUnityContainer _container = null;
		private string _id = String.Empty;
		private string _password = String.Empty;
		private AccountInfo _confirmedAccount = null;

		public LoginWindowViewModel(IUnityContainer container)
		{
			_container = container;

			CloseCommand = new DelegateCommand<bool?>(Close);
		}

		public string Id
		{
			get { return _id; }
			set { SetProperty(ref _id, value); }
		}

		public string Password
		{
			get { return _password; }
			set { SetProperty(ref _password, value); }
		}

		public AccountInfo ConfirmedAccount
		{
			get { return _confirmedAccount; }
			set { SetProperty(ref _confirmedAccount, value); }
		}

		public ObservableDictionary<string, AccountInfo> AccountInfoMap
		{
			get;
			set;
		}

		public ICommand CloseCommand
		{
			get;
			set;
		}

		#region Public methods
		public void Close(bool? confirmed)
		{
			if (confirmed == true)
			{
				if (AccountInfoMap.ContainsKey(Id) == true && Password == AccountInfoMap[Id].Password)
				{
					ConfirmedAccount = AccountInfoMap[Id];
				}
			}

			OnCloseEvent(this, confirmed);
		}

		#endregion

		#region IViewHandler members

		public event OpenWindowEventHandler OpenWindowEvent;
		public event CloseEventHandler OnCloseEvent;

		#endregion
	}
}

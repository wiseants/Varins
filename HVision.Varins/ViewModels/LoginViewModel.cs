using HVision.Varins.Interfaces;
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

namespace HVision.Varins.ViewModels
{
	public class LoginViewModel : BindableBase, IInteractionRequestAware
	{
		private IUnityContainer _container = null;
		public INotification _notification = null;
		public ILoginConfirmation _confirmation = null;
		private string _id = String.Empty;

		public LoginViewModel(IUnityContainer container)
		{
			_container = container;

			CloseCommand = new DelegateCommand<bool?>(Close);
		}

		public INotification Notification
		{
			get => _notification;
			set
			{
				SetProperty(ref _notification, value);

				if (_notification is ILoginConfirmation confirmation)
				{
					LoginConfirmation = confirmation;
				}
			}
		}

		public ILoginConfirmation LoginConfirmation
		{
			get { return _confirmation; }
			set { SetProperty(ref _confirmation, value); }
		}

		public ICommand CloseCommand
		{
			get;
			set;
		}

		public void Close(bool? confirmed)
		{
			_confirmation.Confirmed = confirmed == true;
			FinishInteraction();
		}

		#region IInteractionRequestAware members
		public Action FinishInteraction { get; set; }
		#endregion
	}
}

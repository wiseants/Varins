using HVision.Varins.Interfaces;
using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.Practices.Unity;
using HVision.Varins.Cores;
using System.Windows.Controls;
using Prism.Regions;
using HVision.Varins.Models;
using HVision.Common.Interface;
using HVision.Common;
using HVision.Matrox;
using System.Windows.Input;
using HVision.Common.Mvvm;
using Microsoft.Practices.Prism.Commands;
using Prism.Interactivity.InteractionRequest;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Common.Tool;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models.Grab;
using System.Collections.Specialized;

namespace HVision.Varins.ViewModels.Windows
{
    public partial class MainWindowViewModel : BindableBase, IMainWindowViewModel, IWindowHandler
    {
		#region Events

		public event ChangedRecipe ChangedRecipe;
		public event ChangedAccount ChangedAccount;

		#endregion

		#region Fields

		private readonly IUnityContainer _container = null;
		private Recipe _currentRecipe = null;
		private AccountInfo _currentAccount = null;

		#endregion

		#region Constructors

		public MainWindowViewModel(IUnityContainer container)
        {
			_container = container;

			LoadedCommand = new KentDelegateCommand(Loaded);
			ClosedCommand = new KentDelegateCommand(Closed);

			AccountInfoMap.Add("developer", new AccountInfo()
			{
				Id = "developer",
				Name = "Developer",
				Description = "모든 권한.",
				Password = "1234",
				RoleIndex = 1,
				RoleInfoMap = RoleInfoMap
			});

			AccountInfoMap.Add("user", new AccountInfo()
			{
				Id = "user",
				Name = "User",
				Description = "권한 없음.",
				Password = "1111",
				RoleIndex = 0,
				RoleInfoMap = RoleInfoMap
			});

			MilApplication.Instance().Alloc();
			MilSystem.Instance().Alloc();
		}

		#endregion

		#region IWindowHandler members

		public event OpenWindowEventHandler OpenWindowEvent;
		public event CloseEventHandler OnCloseEvent;

		#endregion
    }
}

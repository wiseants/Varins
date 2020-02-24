using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.ViewModels.Panes
{
	public class MessageViewModel : BindableBase, IMessageViewModel
	{
		private readonly IUnityContainer _container = null;

		public MessageViewModel(IUnityContainer container)
		{
			_container = container;
		}

		public ObservableCollection<IMessageInfo> MessageInfoList { get; } = new ObservableCollection<IMessageInfo>();
	}
}

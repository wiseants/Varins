using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IMessageViewModel
	{
		ObservableCollection<IMessageInfo> MessageInfoList { get; }
	}
}

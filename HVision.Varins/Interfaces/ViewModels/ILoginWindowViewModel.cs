using HVision.Common.Mvvm;
using HVision.Varins.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface ILoginWindowViewModel
	{
		AccountInfo ConfirmedAccount { get; set; }
		ObservableDictionary<string, AccountInfo> AccountInfoMap { get; set; }
	}
}

using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IGrabViewModel
	{
		GrabberController GrabberController { get; set; }
	}
}

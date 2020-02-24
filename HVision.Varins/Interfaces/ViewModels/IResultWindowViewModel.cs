using HVision.Varins.Interfaces.Results;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IResultWindowViewModel
	{
		IInspectedResult InspectedResult { get; set; }
	}
}

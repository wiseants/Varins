using HVision.Varins.Interfaces.Algorithms;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IAlgorithmViewModel
	{
		IParameter Parameter { get; set; }
	}
}

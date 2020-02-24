using HVision.Varins.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.ViewModels
{
    public interface IDisplayViewModel
	{
		IImageViewModel ImageViewModel { get; set; }
	}
}

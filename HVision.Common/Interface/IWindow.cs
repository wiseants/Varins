using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Common.Interface
{
	public interface IWindow : IView
	{
		Window Owner { get; set; }

		bool? ShowDialog();
	}
}

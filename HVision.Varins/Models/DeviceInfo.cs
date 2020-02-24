using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins.Models
{
	public class DeviceInfo : BindableBase
	{
		private Size _size;

		public DeviceInfo()
		{
			ImageSize = new Size(3776, 2684);
		}

		public Size ImageSize
		{
			get => _size;
			set { SetProperty(ref _size, value); }
		}
	}
}

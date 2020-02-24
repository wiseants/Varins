using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Grab
{
	public class GrabInfo : BindableBase, ICloneable
	{
		private readonly IUnityContainer _container = null;
		private string _name;
		private int _brightness;
		private int _exposureTime;

		public GrabInfo(IUnityContainer container)
		{
			_container = container;
		}

		public string Name
		{
			get => _name;
			set { SetProperty(ref _name, value); }
		}

		public int Brightness
		{
			get => _brightness;
			set { SetProperty(ref _brightness, value); }
		}

		public int ExposureTime
		{
			get => _exposureTime;
			set { SetProperty(ref _exposureTime, value); }
		}

		public object Clone()
		{
			return new GrabInfo(_container)
			{
				Name = Name,
				Brightness = Brightness,
				ExposureTime = ExposureTime
			};
		}
	}
}

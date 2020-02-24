using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Grab
{
	public class GrabImageInfo : BindableBase, ICloneable
	{
		private readonly IUnityContainer _container = null;
		private GrabInfo _grabInfo = null;
		private DateTime _createTime = DateTime.Now;

		public GrabImageInfo(IUnityContainer container)
		{
			_container = container;
		}

		public GrabInfo GrabInfo
		{
			get => _grabInfo;
			set { SetProperty(ref _grabInfo, value); }
		}

		public DateTime CreatedTime
		{
			get => _createTime;
			set { SetProperty(ref _createTime, value); }
		}

		public object Clone()
		{
			return new GrabImageInfo(_container)
			{
				GrabInfo = GrabInfo.Clone() as GrabInfo,
				CreatedTime = CreatedTime
			};
		}
	}
}

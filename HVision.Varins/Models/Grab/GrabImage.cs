using HVision.Matrox;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Grab;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace HVision.Varins.Models.Grab
{
	public class GrabImage : BindableBase, IGrabImage
	{
		#region Fields

		private readonly IUnityContainer _container = null;
		private GrabImageInfo _grabImageInfo = null;
		private Mat _matImage = null;
		private MilImage _milImage = new MilImage();

		#endregion

		#region Constructors

		public GrabImage(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		public GrabImageInfo GrabImageInfo
		{
			get => _grabImageInfo;
			set { SetProperty(ref _grabImageInfo, value); }
		}

		public BitmapSource BitmapImage
		{
			get
			{
				return OpenCvSharp.Extensions.BitmapSourceConverter.ToBitmapSource(MatImage);
			}
		}

		public Mat MatImage
		{
			get => _matImage;
			set { SetProperty(ref _matImage, value); }
		}

		public MilImage MilImage
		{
			get
			{
				if (_milImage.IsAllocated() == true)
				{
					_milImage.Free();
				}

				Cv2.ImEncode(".bmp", MatImage, out byte[] buffer);
				_milImage.CreateColor(MatImage.Width, MatImage.Height, buffer);

				return _milImage;
			}
		}

		#endregion

		#region IClonable members

		public object Clone()
		{
			IGrabImage clonedImage = _container.Resolve<IGrabImage>();
			clonedImage.GrabImageInfo = GrabImageInfo.Clone() as GrabImageInfo;
			clonedImage.MatImage = MatImage.Clone();

			return clonedImage;
		}

		#endregion

		#region IDisposable members

		public void Dispose()
		{
			_milImage.Dispose();
		}

		#endregion
	}
}

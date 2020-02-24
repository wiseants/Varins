using HVision.Varins.Models.Grab;
using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using HVision.Matrox;

namespace HVision.Varins.Interfaces.Grab
{
	public interface IGrabImage : ICloneable, IDisposable
	{
		GrabImageInfo GrabImageInfo { get; set; }
		Mat MatImage { get; set; }
		BitmapSource BitmapImage { get; }
		MilImage MilImage { get; }
	}
}

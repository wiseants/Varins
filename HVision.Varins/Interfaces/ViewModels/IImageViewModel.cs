using HVision.Common.Interface;
using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IImageViewModel : IDisposable
	{
		bool IsBinarized { get; set; }
		byte BinarizationThreshold { get; set; }
		string SelectedGrabName { get; set; }
		IGrabImage CurrentImage { get; set; }
		ObservableCollection<Shape> ShapeList { get; set; }
		void StartDrawing(string key, string shapeName);
		void FinishedGrab(object sender, IGrabImage grabImage);
	}
}

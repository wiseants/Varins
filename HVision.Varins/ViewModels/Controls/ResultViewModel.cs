using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace HVision.Varins.ViewModels.Controls
{
	public class ResultViewModel : BindableBase, IImageViewModel
	{
		#region Fields

		private readonly IUnityContainer _container = null;
		private ObservableCollection<Shape> _shapeList = new ObservableCollection<Shape>();
		private IGrabImage _currentImage = null;

		#endregion

		#region Constructors

		public ResultViewModel(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		public ObservableCollection<Shape> ShapeList
		{
			get => _shapeList;
			set { SetProperty(ref _shapeList, value); }
		}

		public IGrabImage CurrentImage
		{
			get => _currentImage;
			set { SetProperty(ref _currentImage, value); }
		}

		public bool IsBinarized
		{
			get;
			set;
		}

		public byte BinarizationThreshold
		{
			get;
			set;
		}

		public string SelectedGrabName
		{
			get;
			set;
		}

		public void FinishedGrab(object sender, IGrabImage grabImage)
		{
			
		}

		public void StartDrawing(string key, string shapeName)
		{

		}

		#region IDisposable members

		bool disposed = false;

		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}

		protected virtual void Dispose(bool disposing)
		{
			if (disposed == true)
			{
				return;
			}

			if (disposing == true)
			{
				// 매니지드 해제.
			}

			// 언매니지드 해제.

			disposed = true;
		}

		#endregion
	}
}

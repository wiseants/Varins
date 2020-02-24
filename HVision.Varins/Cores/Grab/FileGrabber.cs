using HVision.Common.Tool;
using HVision.Matrox;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models.Grab;
using Microsoft.Practices.Unity;
using Microsoft.WindowsAPICodePack.Dialogs;
using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace HVision.Varins.Cores.Grab
{
	public class FileGrabber : IGrabber
	{
		public event Grabbed FinishedGrab;

		private readonly IUnityContainer _container = null;

		public FileGrabber(IUnityContainer container)
		{
			_container = container;
		}

		public void AsyncGrab(GrabInfo info)
		{
			if (TryGrab(info, out IGrabImage grabImage) == true)
			{
			}
		}

		public bool TryGrab(GrabInfo info, out IGrabImage grabImage)
		{
			bool isGrabbed = false;
			grabImage = null;

			CommonOpenFileDialog dialog = new CommonOpenFileDialog
			{
				IsFolderPicker = false
			};

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				string fileName;
				fileName = dialog.FileName;

				grabImage = _container.Resolve<IGrabImage>();
				grabImage.GrabImageInfo = _container.Resolve<GrabImageInfo>();
				grabImage.GrabImageInfo.GrabInfo = info.Clone() as GrabInfo;

				grabImage.MatImage = new Mat(fileName);

				FinishedGrab?.Invoke(this, grabImage);
				isGrabbed = true;
			}

			return isGrabbed;
		}
	}
}

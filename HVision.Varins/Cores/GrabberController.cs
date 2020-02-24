using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models.Grab;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Cores
{
	public class GrabberController
	{
		#region Fields

		private readonly IUnityContainer _container = null;

		#endregion

		#region Events

		public event Grabbed FinishedGrab;

		#endregion

		#region Constructors

		public GrabberController(IUnityContainer container, IGrabber grabber)
		{
			_container = container;

			Grabber = grabber;
			if (Grabber != null)
			{
				Grabber.FinishedGrab += Grabber_FinishedGrab;
			}
		}

		#endregion

		#region Properties

		public int Id
		{
			get;
			set;
		}

		public IGrabber Grabber { get; } = null;

		public IDictionary<string, GrabInfo> GrabInfoMap
		{
			get;
			set;
		}

		public ConcurrentQueue<IGrabImage> GrabImageQueue { get; } = new ConcurrentQueue<IGrabImage>();

		#endregion

		#region Private methods

		private void Grabber_FinishedGrab(object sender, IGrabImage grabImage)
		{
			GrabImageQueue.Enqueue(grabImage);

			FinishedGrab?.Invoke(sender, grabImage);
		}

		#endregion
	}
}

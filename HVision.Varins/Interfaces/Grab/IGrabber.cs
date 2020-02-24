using HVision.Varins.Models.Grab;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.Grab
{
	public interface IGrabber
	{
		event Grabbed FinishedGrab;
		void AsyncGrab(GrabInfo info);
		bool TryGrab(GrabInfo info, out IGrabImage grabImage);
	}
}

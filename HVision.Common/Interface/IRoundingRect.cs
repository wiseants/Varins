using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Common.Interface
{
	public interface IRoundingRect : IExtentable, ICenterable
	{
		double RadiusX { get; set; }
		double RadiusY { get; set; }
	}
}

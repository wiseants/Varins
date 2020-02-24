using HVision.Common.Cores.ControlPoints;
using HVision.Common.Interface;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins.Cores.ControlPoints
{
	public class RadiusControlPoint : ControlPoint
	{
		public override void Dragged(object sender, object shape, Vector variation)
		{
			if (shape is IRoundingRect roudingRect)
			{
				roudingRect.RadiusX += variation.X;
				roudingRect.RadiusY += variation.Y;
			}
		}

		public override void ChangedShape(object sender, object shape)
		{
			if (shape is IRoundingRect centerableShape)
			{
				X = (centerableShape.X - centerableShape.Width / 2) + centerableShape.RadiusX;
				Y = (centerableShape.Y - centerableShape.Height / 2) + centerableShape.RadiusY;
			}
		}
	}
}

using HVision.Common.Cores.ControlPoints;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Varins.Cores.Shapes;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins.Cores.ControlPoints
{
	public class BottomControlPoint : ControlPoint
	{
		public override void Dragged(object sender, object shape, Vector variation)
		{
			if (shape is IRoundingRect rectObject)
			{
				rectObject.Height += variation.Y;
				rectObject.Y += variation.Y / 2;

				if (sender is EditableShapeController controller)
				{
					controller.OnPropertyChanged("Height");
					controller.OnPropertyChanged("Y");
				}
			}
		}

		public override void ChangedShape(object sender, object shape)
		{
			if (shape is IRoundingRect rectObject)
			{
				X = rectObject.X;
				Y = rectObject.Y + rectObject.Height / 2;
			}
		}
	}
}

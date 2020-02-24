using HVision.Common.Cores.ControlPoints;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Varins.Cores.Shapes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins.Cores.ControlPoints
{
	public class LeftControlPoint : ControlPoint
	{
		public override void Dragged(object sender, object shape, Vector variation)
		{
			if (shape is IRoundingRect rectObject)
			{
				rectObject.Width -= variation.X;
				rectObject.X += variation.X / 2;

				if (sender is EditableShapeController controller)
				{
					controller.OnPropertyChanged("Width");
					controller.OnPropertyChanged("X");
				}
			}
		}

		public override void ChangedShape(object sender, object shape)
		{
			if (shape is IRoundingRect rectObject)
			{
				X = rectObject.X - rectObject.Width / 2;
				Y = rectObject.Y;
			}
		}
	}
}

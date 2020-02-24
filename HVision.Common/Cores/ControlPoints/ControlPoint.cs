using HVision.Common.Interface;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace HVision.Common.Cores.ControlPoints
{
	public abstract class ControlPoint : Shape, IExtentable, ICenterable, IControlPoint, IFillContains
	{
		private double _x = 0.0;
		private double _y = 0.0;

		public ControlPoint()
		{
			Size = new Size(Constant.MOUSE_TOLERANCE_SIZE, Constant.MOUSE_TOLERANCE_SIZE);
			//Fill = new SolidColorBrush(Colors.Black);
			Stroke = new SolidColorBrush(Colors.Black);
		}

		protected override Geometry DefiningGeometry
		{
			get
			{
				return new RectangleGeometry(new Rect(0, 0, Width, Height), 0, 0);
			}
		}

		public Size Size
		{
			get => new Size(Width, Height);
			set
			{
				Width = value.Width;
				Height = value.Height;
			}
		}

		public double X
		{
			get => _x;
			set
			{
				if (_x == value)
				{
					return;
				}

				_x = value;
				Canvas.SetLeft(this, _x - Width / 2);
			}
		}

		public double Y
		{
			get => _y;
			set
			{
				if (_y == value)
				{
					return;
				}

				_y = value;
				Canvas.SetTop(this, _y - Height / 2);
			}
		}

		public new double Width
		{
			get => base.Width;
			set
			{
				base.Width = value > 0 ? value : 0;
			}
		}

		public new double Height
		{
			get => base.Height;
			set
			{
				base.Height = value > 0 ? value : 0;
			}
		}

		public bool FillContains(Point point)
		{
			Point basePoint = new Point(point.X - Canvas.GetLeft(this), point.Y - Canvas.GetTop(this));

			return RenderedGeometry.FillContains(basePoint);
		}

		public object Clone()
		{
			return MemberwiseClone();
		}

		public abstract void Dragged(object sender, object shape, Vector variation);
		public abstract void ChangedShape(object sender, object shape);
	}
}

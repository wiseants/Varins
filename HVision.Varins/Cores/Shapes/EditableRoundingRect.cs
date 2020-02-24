using HVision.Common.Cores.ControlPoints;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Varins.Cores.ControlPoints;
using HVision.Varins.ViewModels.Controls;
using HVision.Varins.Views.Controls;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Xml.Serialization;

namespace HVision.Varins.Cores.Shapes
{
	[JsonObject(MemberSerialization.OptIn)]
	public class EditableRoundingRect : EditableShape, IRoundingRect, IFillContains
	{
		#region Fields

		public static DependencyProperty RadiusXProperty = DependencyProperty.Register(
			"RadiusX", typeof(double), typeof(EditableRoundingRect), 
			new FrameworkPropertyMetadata(0.0, FrameworkPropertyMetadataOptions.AffectsRender | FrameworkPropertyMetadataOptions.AffectsMeasure));

		public static DependencyProperty RadiusYProperty = DependencyProperty.Register(
			"RadiusY", typeof(double), typeof(EditableRoundingRect), 
			new FrameworkPropertyMetadata(0.0, FrameworkPropertyMetadataOptions.AffectsRender | FrameworkPropertyMetadataOptions.AffectsMeasure));

		#endregion

		#region Contructors

		public EditableRoundingRect(IUnityContainer container)
			: base(container)
		{
			double size = App.DeviceInfo.ImageSize.Width / 100;
			Size controlPointSize = new Size(size, size);
			ControlPointList.Add(new LeftControlPoint() { X = X, Y = Y, Size = controlPointSize });
			ControlPointList.Add(new TopControlPoint() { X = X, Y = Y, Size = controlPointSize });
			ControlPointList.Add(new RightControlPoint() { X = X, Y = Y, Size = controlPointSize });
			ControlPointList.Add(new BottomControlPoint() { X = X, Y = Y, Size = controlPointSize });
			ControlPointList.Add(new RadiusControlPoint() { X = X, Y = Y, Size = controlPointSize });
		}

		#endregion

		#region Properties

		[JsonIgnore]
		protected override Geometry DefiningGeometry
		{
			get
			{
				return new RectangleGeometry(new Rect(0, 0, Width, Height), RadiusX, RadiusY);
			}
		}

		[JsonProperty]
		public double RadiusX
		{
			get
			{
				double radiusX = (double)GetValue(RadiusXProperty);
				return radiusX > Width / 2 ? Width / 2 : radiusX;
			}
			set
			{
				if (value <= 0)
				{
					value = 0;
				}

				SetCurrentValue(RadiusXProperty, value);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		[JsonProperty]
		public double RadiusY
		{
			get
			{
				double radiusY = (double)GetValue(RadiusYProperty);
				return radiusY > Height / 2 ? Height / 2 : radiusY;
			}
			set
			{
				if (value <= 0)
				{
					value = 0;
				}

				SetCurrentValue(RadiusYProperty, value);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		[JsonProperty]
		public override string ContainerName
		{
			get => Constant.ROUNDING_RECT_SHAPE;
		}

		#endregion

		#region Override methods

		public override object Clone()
		{
			EditableRoundingRect newRect = _container.Resolve<EditableRoundingRect>();
			newRect.Width = Width;
			newRect.Height = Height;
			newRect.X = X;
			newRect.Y = Y;
			newRect.RadiusX = RadiusX;
			newRect.RadiusY = RadiusY;
			newRect.StrokeThickness = StrokeThickness;
			newRect.Stroke = Stroke;

			return newRect;
		}

		public override bool FillContains(Point point)
		{
			bool isFilled = false;
			double margin = App.DeviceInfo.ImageSize.Width / 100;
			Point basePoint = new Point(point.X - Canvas.GetLeft(this), point.Y - Canvas.GetTop(this));

			RectangleGeometry innerGeometry = new RectangleGeometry();
			if (margin < Width && margin < Height)
			{
				innerGeometry.Rect = new Rect(margin, margin, Width - margin * 2, Height - margin * 2);
				innerGeometry.RadiusX = (RadiusX - margin) <= 0 ? 0 : RadiusX - margin;
				innerGeometry.RadiusY = (RadiusY - margin) <= 0 ? 0 : RadiusY - margin;
			}

			isFilled =
				RenderedGeometry.FillContains(basePoint, margin, ToleranceType.Absolute) == true &&
				innerGeometry.FillContains(basePoint) == false;

			return isFilled;
		}

		#endregion
	}
}

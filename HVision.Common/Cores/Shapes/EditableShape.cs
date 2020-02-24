using HVision.Common.Cores.ControlPoints;
using HVision.Common.Interface;
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
using System.Xml;

namespace HVision.Common.Cores.Shapes
{
	[JsonObject(MemberSerialization.OptIn)]
	public abstract class EditableShape : Shape, ICenterable, IFillContains, ICloneable
	{
		#region Fields

		public readonly double MIN_SCALE = 4;

		protected readonly IUnityContainer _container = null;

		public static DependencyProperty XProperty = DependencyProperty.Register(
			"X", typeof(double), typeof(EditableShape),
			new FrameworkPropertyMetadata(0.0, FrameworkPropertyMetadataOptions.AffectsRender | FrameworkPropertyMetadataOptions.AffectsMeasure));

		public static DependencyProperty YProperty = DependencyProperty.Register(
			"Y", typeof(double), typeof(EditableShape),
			new FrameworkPropertyMetadata(0.0, FrameworkPropertyMetadataOptions.AffectsRender | FrameworkPropertyMetadataOptions.AffectsMeasure));

		#endregion

		#region Contructors

		public EditableShape(IUnityContainer container)
		{
			_container = container;

			Width = Constant.MOUSE_TOLERANCE_SIZE * MIN_SCALE;
			Height = Constant.MOUSE_TOLERANCE_SIZE * MIN_SCALE;
		}

		#endregion

		#region Properties

		[JsonIgnore]
		public IList<IControlPoint> ControlPointList { get; } = new List<IControlPoint>();

		[JsonProperty]
		public double X
		{
			get
			{
				return (double)GetValue(XProperty);
			}
			set
			{
				SetCurrentValue(XProperty, value);
				Canvas.SetLeft(this, value - Width / 2);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		[JsonProperty]
		public double Y
		{
			get
			{
				return (double)GetValue(YProperty);
			}
			set
			{
				SetCurrentValue(YProperty, value);
				Canvas.SetTop(this, value - Height / 2);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		[JsonProperty]
		public new double Width
		{
			get
			{
				return base.Width;
			}
			set
			{
				double minWidth = 0;

				base.Width = value > minWidth ? value : minWidth;
				Canvas.SetLeft(this, X - value / 2);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		[JsonProperty]
		public new double Height
		{
			get
			{
				return (double)GetValue(HeightProperty);
			}
			set
			{
				double minHeight = 0;

				SetCurrentValue(HeightProperty, value > minHeight ? value : minHeight);
				Canvas.SetTop(this, Y - value / 2);

				foreach (var point in ControlPointList)
				{
					point.ChangedShape(this, this);
				}
			}
		}

		#endregion

		#region Public methods

		public abstract object Clone();

		public abstract string ContainerName { get; }

		public abstract bool FillContains(Point point);

		#endregion
	}
}

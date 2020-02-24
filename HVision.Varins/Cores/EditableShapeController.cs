using HVision.Common.Cores.ControlPoints;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using System.Windows.Shapes;

namespace HVision.Varins.Cores
{
	[JsonObject(MemberSerialization.OptIn)]
	public class EditableShapeController : ICloneable, INotifyPropertyChanged
	{
		#region Events

		public event PropertyChangedEventHandler PropertyChanged;

		#endregion

		#region Fields

		private readonly IUnityContainer _container = null;
		private readonly string _name = String.Empty;
		private bool _isSelected = false;
		private EditableShape _shape = null;
		private Point _startPoint;
		private ObservableCollection<Shape> _drawingShapes = new ObservableCollection<Shape>();

		#endregion

		#region Contructors

		public EditableShapeController(IUnityContainer container, EditableShape shape, Point startPoint)
		{
			_container = container;

			Shape = shape;
			Shape.StrokeThickness = 4;
			Shape.Stroke = new SolidColorBrush(Colors.LightGray);

			_startPoint = startPoint;
			X = startPoint.X;
			Y = startPoint.Y;
		}

		#endregion

		#region IEditableShape members

		[JsonProperty]
		public EditableShape Shape
		{
			get => _shape;
			set
			{
				_shape = value;

				DrawingShapes.Add(_shape);
				if (IsSelected == true)
				{
					DrawingShapes.AddRange(_shape.ControlPointList.Select(x => x as Shape));
				}

				OnPropertyChanged("Shape");
			}
		}

		public bool IsSelected
		{
			get => _isSelected;
			set
			{
				_isSelected = value;

				Shape.StrokeThickness = _isSelected == true ? 8 : 4;

				foreach (var controlPoint in Shape.ControlPointList)
				{
					controlPoint.Stroke = new SolidColorBrush(_isSelected == true ? Colors.LightGray : Colors.Transparent);
					controlPoint.Fill = new SolidColorBrush(_isSelected == true ? Colors.LightGray : Colors.Transparent);

					if (_isSelected == true)
					{
						DrawingShapes.Add(controlPoint as Shape);
					}
					else
					{
						DrawingShapes.Remove(controlPoint as Shape);
					}
				}

				OnPropertyChanged("IsSelected");
			}
		}

		[JsonProperty]
		public double X
		{
			get
			{
				return Shape.X;
			}
			set
			{
				Shape.X = value;

				OnPropertyChanged("X");
			}
		}

		[JsonProperty]
		public double Y
		{
			get
			{
				return Shape.Y;
			}
			set
			{
				Shape.Y = value;

				OnPropertyChanged("Y");
			}
		}

		[JsonProperty]
		public double Width
		{
			get
			{
				return Shape.Width;
			}
			set
			{
				Shape.Width = value;

				OnPropertyChanged("Width");
			}
		}

		[JsonProperty]
		public double Height
		{
			get
			{
				return Shape.Height;
			}
			set
			{
				Shape.Height = value;

				OnPropertyChanged("Height");
			}
		}

		public ObservableCollection<Shape> DrawingShapes
		{
			get => _drawingShapes;
			set
			{
				_drawingShapes = value;

				OnPropertyChanged("DrawingShapes");
			}
		}

		public string Name
		{
			get => Shape.ContainerName;
		}

		public void Drawing(Point draggedStartPoint, Point draggingPoint)
		{
			Vector offset = draggingPoint - _startPoint;

			X = _startPoint.X + offset.X / 2;
			Y = _startPoint.Y + offset.Y / 2;
			Width = Math.Abs(offset.X);
			Height = Math.Abs(offset.Y);
		}

		public void Moving(Point draggedStartPoint, Point draggingPoint)
		{
			Vector offset = draggingPoint - draggedStartPoint;

			X += offset.X;
			Y += offset.Y;
		}

		public void Resizing(IControlPoint controlPoint, Point draggedStartPoint, Point draggingPoint)
		{
			if (controlPoint == null)
			{
				return;
			}

			Vector offset = draggingPoint - draggedStartPoint;
			controlPoint.Dragged(this, Shape, offset);
		}

		public bool TryFillContains(Point point, out IControlPoint containedPoint)
		{
			bool isFillContains = false;

			var containedPoints = Shape.ControlPointList.Where(x => x.FillContains(point) == true);
			isFillContains = containedPoints.Count() > 0;
			containedPoint = isFillContains == true ? containedPoints.First() : null;

			return isFillContains || FillContains(point);
		}

		public bool FillContains(Point point)
		{
			return _shape.FillContains(point);
		}

		public void OnPropertyChanged(string name)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
		}

		public object Clone()
		{
			return MemberwiseClone();
		}

		#endregion
	}
}

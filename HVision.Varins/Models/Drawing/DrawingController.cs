using HVision.Common.Interface;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Drawing;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Shapes;

namespace HVision.Varins.Models.Drawing
{
	[JsonObject(MemberSerialization.OptIn)]
	public class DrawingController : BindableBase, ICloneable
	{
		public event NotifyCollectionChangedEventHandler DrawingShapesChanged;

		#region Fields

		private readonly IUnityContainer _container = null;
		private IDrawing _drawing = null;

		#endregion

		#region Constructors

		public DrawingController(IUnityContainer container, IDrawing drawing)
		{
			_container = container;
			Drawing = drawing;

			ShapeControllerList.CollectionChanged += ShapeControllerList_CollectionChanged;
		}

		#endregion

		#region Properties

		[JsonProperty]
		public IDrawing Drawing
		{
			get => _drawing;
			set { SetProperty(ref _drawing, value); }
		}

		public bool IsValid
		{
			get => ShapeControllerList.Count >= Drawing.MinCount;
			set { }
		}

		public bool CanDraw
		{
			get => ShapeControllerList.Count < Drawing.MaxCount;
		}

		public string CountDescription
		{
			get => Drawing.MinCount == Drawing.MaxCount ? 
				String.Format("{0}", Drawing.MinCount) : 
				String.Format("{0}~{1}", Drawing.MinCount, Drawing.MaxCount);
		}

		public string Description
		{
			get => Drawing?.Description;
		}

		public string EnableShapeDescription
		{
			get => String.Join(",", Drawing.EnableShapeNames);
		}

		[JsonProperty]
		public ObservableCollection<EditableShapeController> ShapeControllerList { get; } = new ObservableCollection<EditableShapeController>();

		#endregion

		#region Public methods

		public object Clone()
		{
			object cloneObject = MemberwiseClone();
			if (cloneObject is DrawingController cloneDrawingController)
			{
				cloneDrawingController.ShapeControllerList.AddRange(ShapeControllerList.Select(x => x.Clone() as EditableShapeController));
			}

			return cloneObject;
		}

		#endregion

		#region Private methods

		private void DrawingShapes_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			DrawingShapesChanged?.Invoke(sender, e);
		}

		private void ShapeControllerList_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			List<Shape> argsItems = new List<Shape>();

			if (e.NewItems != null)
			{
				foreach (EditableShapeController controller in e.NewItems)
				{
					controller.DrawingShapes.CollectionChanged += DrawingShapes_CollectionChanged;
					argsItems.AddRange(controller.DrawingShapes);
				}
			}

			if (e.OldItems != null)
			{
				foreach (EditableShapeController controller in e.OldItems)
				{
					controller.DrawingShapes.CollectionChanged -= DrawingShapes_CollectionChanged;
					argsItems.AddRange(controller.DrawingShapes);
				}
			}

			DrawingShapesChanged?.Invoke(sender, new NotifyCollectionChangedEventArgs(e.Action, argsItems));
		}

		#endregion
	}
}

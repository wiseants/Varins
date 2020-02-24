using HVision.Common.Interface;
using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Models.Drawing;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Shapes;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace HVision.Varins.Models
{
	[JsonObject(MemberSerialization.OptIn)]
	public class Recipe : BindableBase
	{
		public event NotifyCollectionChangedEventHandler DrawingShapesChanged;

		#region Fields

		private string _name = String.Empty;
		private string _path = String.Empty;
		private Size _imageSize;
		private ObservableDictionary<string, DrawingController> _drawingControllerMap = new ObservableDictionary<string, DrawingController>();
		private ObservableDictionary<string, SpecController> _specControllerMap = new ObservableDictionary<string, SpecController>();

		#endregion

		#region Events

		public event NotifyCollectionChangedEventHandler ShapeMapChanged = delegate { };

		#endregion

		#region Constructors

		public Recipe()
		{
			DrawingControllerMap.CollectionChanged += DrawingControllerMap_CollectionChanged;
		}

		#endregion

		#region Properteis

		[JsonProperty]
		public string Name
		{
			get { return _name; }
			set { SetProperty(ref _name, value); }
		}

		[JsonProperty]
		public string Path
		{
			get { return _path; }
			set { SetProperty(ref _path, value); }
		}

		[JsonProperty]
		public string FullPath
		{
			get => String.Format(@"{0}\{1}.json", Path, Name);
		}

		[JsonProperty]
		public ObservableDictionary<string, DrawingController> DrawingControllerMap
		{
			get { return _drawingControllerMap; }
			set { SetProperty(ref _drawingControllerMap, value); }
		}

		[JsonProperty]
		public ObservableDictionary<string, SpecController> SpecControllerMap
		{
			get => _specControllerMap;
			set { SetProperty(ref _specControllerMap, value); }
		}

		[JsonProperty]
		public Size ImageSize
		{
			get { return _imageSize; }
			set { SetProperty(ref _imageSize, value); }
		}

		#endregion

		#region Privae methods

		private void Item_DrawingShapesChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			DrawingShapesChanged?.Invoke(sender, e);
		}

		private void DrawingControllerMap_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			List<Shape> argsItems = new List<Shape>();

			if (e.NewItems != null)
			{
				foreach (KeyValuePair<string, DrawingController> pair in e.NewItems)
				{
					pair.Value.DrawingShapesChanged += Item_DrawingShapesChanged;
					argsItems.AddRange(pair.Value.ShapeControllerList.SelectMany(x => x.DrawingShapes));
				}
			}

			if (e.OldItems != null)
			{
				foreach (KeyValuePair<string, DrawingController> pair in e.OldItems)
				{
					pair.Value.DrawingShapesChanged -= Item_DrawingShapesChanged;
					argsItems.AddRange(pair.Value.ShapeControllerList.SelectMany(x => x.DrawingShapes));
				}
			}

			DrawingShapesChanged?.Invoke(sender, new NotifyCollectionChangedEventArgs(e.Action, argsItems));
		}

		#endregion
	}
}

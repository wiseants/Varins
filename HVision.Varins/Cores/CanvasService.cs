//https://stackoverflow.com/questions/26893518/how-to-bind-a-canvas-children-to-a-collection

using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Shapes;

namespace HVision.Varins.Cores
{
	/// <summary>
	/// 캔버스 컨트롤 바인딩 도구.
	/// </summary>
	public static class CanvasService
	{
		#region Fields

		private static Dictionary<INotifyCollectionChanged, Canvas> _references = new Dictionary<INotifyCollectionChanged, Canvas>();
		public static readonly DependencyProperty ChildrenProperty = DependencyProperty.RegisterAttached
			("Children",
			typeof(IEnumerable<Shape>),
			typeof(CanvasService),
			new UIPropertyMetadata(ChildrenChanged));

		#endregion

		#region Public methods

		public static IEnumerable<Shape> GetChildren(Canvas cv)
		{
			return cv.GetValue(ChildrenProperty) as IEnumerable<Shape>;
		}

		public static void SetChildren(Canvas cv, IEnumerable<Shape> children)
		{
			cv.SetValue(ChildrenProperty, children);
		}

		#endregion

		#region Private methods

		private static void ChildrenChanged(DependencyObject target, DependencyPropertyChangedEventArgs e)
		{
			var canvas = target as Canvas;
			RepopulateChildren(canvas);
			var be = canvas.GetBindingExpression(ChildrenProperty);
			if (be != null)
			{
				var elements = (be.ResolvedSourcePropertyName == null ? be.ResolvedSource : be.ResolvedSource.GetType().GetProperty(be.ResolvedSourcePropertyName).GetValue(be.ResolvedSource)) as INotifyCollectionChanged;
				if (elements != null)
				{
					var cv = _references.FirstOrDefault(i => i.Value == canvas);
					if (!cv.Equals(default(KeyValuePair<INotifyCollectionChanged, Canvas>)))
						_references.Remove(cv.Key);
					_references[elements] = canvas;
					elements.CollectionChanged -= CollectionChangedHandler;
					elements.CollectionChanged += CollectionChangedHandler;
				}
			}
			else _references.Clear();
		}
		private static void CollectionChangedHandler(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (_references.TryGetValue(sender as INotifyCollectionChanged, out Canvas cv))
			{
				switch (e.Action)
				{
					case NotifyCollectionChangedAction.Add:
						foreach (var item in e.NewItems) cv.Children.Add(item as UIElement);
						break;
					case NotifyCollectionChangedAction.Remove:
						foreach (var item in e.OldItems) cv.Children.Remove(item as UIElement);
						break;
					case NotifyCollectionChangedAction.Reset:
						RepopulateChildren(cv);
						break;
				}
			}
		}

		private static void RepopulateChildren(Canvas cv)
		{
			cv.Children.Clear();
			var elements = GetChildren(cv);
			foreach (UIElement elem in elements)
			{
				cv.Children.Add(elem);
			}
		}

		#endregion
	}
}

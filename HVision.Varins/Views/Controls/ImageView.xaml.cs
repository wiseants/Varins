using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace HVision.Varins.Views.Controls
{
	/// <summary>
	/// Interaction logic for ImageView.xaml
	/// </summary>
	public partial class ImageView : UserControl, IView
	{
		#region Fields

		private Point _lastMousePositionOnTarget;
		private bool _isDragging = false;
		private Point _draggedStartPoint;

		#endregion

		#region Constructors

		public ImageView()
		{
			InitializeComponent();
		}

		#endregion

		#region Private methods

		private void ScrollViewer_PreviewMouseWheel(object sender, MouseWheelEventArgs e)
		{
			_lastMousePositionOnTarget = Mouse.GetPosition(MainCanvas);
		}

		private void ScrollViewer_ScrollChanged(object sender, ScrollChangedEventArgs e)
		{
			if (e.ExtentHeightChange == 0 && e.ExtentWidthChange == 0)
			{
				return;
			}

			Point targetBefore = _lastMousePositionOnTarget;
			Point targetNow = Mouse.GetPosition(MainCanvas);
			double newOffsetX = scrMainViewer.HorizontalOffset - (targetNow.X - targetBefore.X) * (e.ExtentWidth / MainCanvas.Width);
			double newOffsetY = scrMainViewer.VerticalOffset - (targetNow.Y - targetBefore.Y) * (e.ExtentHeight / MainCanvas.Height);
			if (double.IsNaN(newOffsetX) || double.IsNaN(newOffsetY))
			{
				return;
			}

			scrMainViewer.ScrollToHorizontalOffset(newOffsetX);
			scrMainViewer.ScrollToVerticalOffset(newOffsetY);
		}

		#endregion

		private void MainCanvas_MouseWheel(object sender, MouseWheelEventArgs e)
		{
			double currentScale = Scaler.ScaleX;
			double newScale = e.Delta > 0 ? currentScale + 0.1 : currentScale - 0.1;
			if (newScale <= 0.1 || newScale > 3)
			{
				newScale = currentScale;
			}

			Scaler.ScaleX = newScale;
			Scaler.ScaleY = newScale;

			e.Handled = true;
		}

		private void MainCanvas_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
		{
			_isDragging = true;
			_draggedStartPoint = e.GetPosition(sender as IInputElement);
		}

		private void MainCanvas_MouseRightButtonUp(object sender, MouseButtonEventArgs e)
		{
			_isDragging = false;
		}

		private void MainCanvas_MouseMove(object sender, MouseEventArgs e)
		{
			if (_isDragging == false)
			{
				return;
			}

			Vector offset = e.GetPosition(sender as IInputElement) - _draggedStartPoint;
			Translater.X += offset.X * Scaler.ScaleX;
			Translater.Y += offset.Y * Scaler.ScaleY;

			_draggedStartPoint = e.GetPosition(sender as IInputElement);
		}
	}
}

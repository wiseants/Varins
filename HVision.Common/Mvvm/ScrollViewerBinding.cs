// https://stackoverflow.com/questions/2096143/two-way-binding-of-verticaloffset-property-on-scrollviewer

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace HVision.Common.Mvvm
{
	public static class ScrollViewerBinding
	{
		/// <summary>
		/// VerticalOffset attached property
		/// </summary>
		public static readonly DependencyProperty VerticalOffsetProperty = DependencyProperty.RegisterAttached(
			"VerticalOffset", typeof(double), typeof(ScrollViewerBinding), 
			new FrameworkPropertyMetadata(double.NaN, FrameworkPropertyMetadataOptions.BindsTwoWayByDefault, OnVerticalOffsetPropertyChanged));

		public static readonly DependencyProperty HorizontalOffsetProperty = DependencyProperty.RegisterAttached(
			"HorizontalOffset", typeof(double), typeof(ScrollViewerBinding),
			new FrameworkPropertyMetadata(double.NaN, FrameworkPropertyMetadataOptions.BindsTwoWayByDefault, OnHorizontalOffsetPropertyChanged));

		/// <summary>
		/// Just a flag that the binding has been applied.
		/// </summary>
		private static readonly DependencyProperty VerticalScrollBindingProperty = DependencyProperty.RegisterAttached(
			"VerticalScrollBinding", typeof(bool?), typeof(ScrollViewerBinding));

		private static readonly DependencyProperty HorizontalScrollBindingProperty = DependencyProperty.RegisterAttached(
			"HorizontalScrollBinding", typeof(bool?), typeof(ScrollViewerBinding));

		public static double GetVerticalOffset(DependencyObject depObj)
		{
			return (double)depObj.GetValue(VerticalOffsetProperty);
		}

		public static double GetHorizontalOffset(DependencyObject depObj)
		{
			return (double)depObj.GetValue(HorizontalOffsetProperty);
		}

		public static void SetVerticalOffset(DependencyObject depObj, double value)
		{
			depObj.SetValue(VerticalOffsetProperty, value);
		}

		public static void SetHorizontalOffset(DependencyObject depObj, double value)
		{
			depObj.SetValue(HorizontalOffsetProperty, value);
		}

		private static void OnVerticalOffsetPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			if (d is ScrollViewer scrollViewer)
			{
				BindVerticalOffset(scrollViewer);
				scrollViewer.ScrollToVerticalOffset((double)e.NewValue);
			}
		}

		private static void OnHorizontalOffsetPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			if (d is ScrollViewer scrollViewer)
			{
				BindHorizontalOffset(scrollViewer);
				scrollViewer.ScrollToHorizontalOffset((double)e.NewValue);
			}
		}

		public static void BindVerticalOffset(ScrollViewer scrollViewer)
		{
			if (scrollViewer.GetValue(VerticalScrollBindingProperty) != null)
				return;

			scrollViewer.SetValue(VerticalScrollBindingProperty, true);
			scrollViewer.ScrollChanged += (s, se) =>
			{
				if (se.VerticalChange == 0)
					return;
				SetVerticalOffset(scrollViewer, se.VerticalOffset);
			};
		}

		public static void BindHorizontalOffset(ScrollViewer scrollViewer)
		{
			if (scrollViewer.GetValue(HorizontalScrollBindingProperty) != null)
				return;

			scrollViewer.SetValue(HorizontalScrollBindingProperty, true);
			scrollViewer.ScrollChanged += (s, se) =>
			{
				if (se.HorizontalChange == 0)
					return;
				SetHorizontalOffset(scrollViewer, se.HorizontalOffset);
			};
		}
	}
}

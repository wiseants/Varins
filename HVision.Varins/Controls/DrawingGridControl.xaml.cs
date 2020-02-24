using HVision.Varins.Models.Drawing;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;

namespace HVision.Varins.Controls
{
	/// <summary>
	/// Interaction logic for DrawingListControl.xaml
	/// </summary>
	public partial class DrawingGridControl : UserControl
	{
		#region Fields

		public static DependencyProperty ItemsProperty =
			DependencyProperty.Register("Items", typeof(ObservableCollection<DrawingController>), typeof(DrawingGridControl));

		public static DependencyProperty SelectedItemProperty =
			DependencyProperty.Register("SelectedItem", typeof(DrawingController), typeof(DrawingGridControl));

		public static DependencyProperty SelectedIndexProperty =
			DependencyProperty.Register("SelectedIndex", typeof(int), typeof(DrawingGridControl));
		#endregion

		#region Constructors

		/// <summary>
		/// 기본 생성자.
		/// </summary>
		public DrawingGridControl()
		{
			InitializeComponent();
		}

		#endregion

		#region Properties

		/// <summary>
		/// 장비 정보 리스트.
		/// </summary>
		public ObservableCollection<DrawingController> Items
		{
			get
			{
				return (ObservableCollection<DrawingController>)GetValue(ItemsProperty);
			}
			set
			{
				SetValue(ItemsProperty, value);
			}
		}

		public DrawingController SelectedItem
		{
			get
			{
				return (DrawingController)GetValue(SelectedItemProperty);
			}
			set
			{
				SetValue(SelectedItemProperty, value);
			}
		}

		public int SelectedIndex
		{
			get
			{
				return (int)GetValue(SelectedIndexProperty);
			}
			set
			{
				SetValue(SelectedIndexProperty, value);
			}
		}

		#endregion
	}
}

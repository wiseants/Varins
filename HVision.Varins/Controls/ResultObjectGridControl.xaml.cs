using HVision.Varins.Interfaces.Results;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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

namespace HVision.Varins.Controls
{
	/// <summary>
	/// Interaction logic for ResultObjectGridControl.xaml
	/// </summary>
	public partial class ResultObjectGridControl : UserControl
	{
		#region Fields

		public static DependencyProperty ItemsProperty =
			DependencyProperty.Register("Items", typeof(ObservableCollection<IResultObject>), typeof(ResultObjectGridControl));

		public static DependencyProperty SelectedItemProperty =
			DependencyProperty.Register("SelectedItem", typeof(IResultObject), typeof(ResultObjectGridControl));

		public static DependencyProperty SelectedIndexProperty =
			DependencyProperty.Register("SelectedIndex", typeof(int), typeof(ResultObjectGridControl));

		#endregion

		#region Constructors

		public ResultObjectGridControl()
		{
			InitializeComponent();
		}

		#endregion

		#region Properties

		/// <summary>
		/// 장비 정보 리스트.
		/// </summary>
		public ObservableCollection<IResultObject> Items
		{
			get
			{
				return (ObservableCollection<IResultObject>)GetValue(ItemsProperty);
			}
			set
			{
				SetValue(ItemsProperty, value);
			}
		}

		public IResultObject SelectedItem
		{
			get
			{
				return (IResultObject)GetValue(SelectedItemProperty);
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

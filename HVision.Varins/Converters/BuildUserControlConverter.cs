using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Markup;
using Microsoft.Practices.Unity;

namespace HVision.Varins.Converters
{
	public class BuildUserControlConverter : MarkupExtension, IValueConverter
	{
		#region Fields

		private static BuildUserControlConverter _converter = null;

		#endregion

		#region Public methods

		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			UserControl createdUserControl = null;

			if (value == null)
			{
				return createdUserControl;
			}

			if (parameter is string name)
			{
				createdUserControl = App.Container.Resolve<UserControl>(name);
			}

			return createdUserControl;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}

		public override object ProvideValue(IServiceProvider serviceProvider)
		{
			if (_converter == null)
			{
				_converter = new BuildUserControlConverter();
			}

			return _converter;
		}

		#endregion
	}
}

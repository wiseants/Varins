using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using System.Windows.Markup;

namespace HVision.Varins.Converters
{
	public class IsCheckedToContentConverter : MarkupExtension, IValueConverter
	{
		#region Fields

		private static IsCheckedToContentConverter _converter = null;

		#endregion

		#region Public methods

		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				throw new ArgumentNullException("Parameter of converter is null.");
			}

			return (bool)value == true ? parameter as string : String.Empty;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				throw new ArgumentNullException("Parameter of converter is null.");
			}

			return value as string == parameter as string;
		}

		public override object ProvideValue(IServiceProvider serviceProvider)
		{
			if (_converter == null)
			{
				_converter = new IsCheckedToContentConverter();
			}

			return _converter;
		}

		#endregion
	}
}

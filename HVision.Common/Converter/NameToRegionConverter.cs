using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using HVision.Common.Tool;

namespace HVision.Common.Converter
{
	public class NameToRegionConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (value == null)
			{
				throw new ArgumentNullException("Parameter of converter is null.");
			}

			return UnityNameTool.ConvertRegionName((string)value);
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}

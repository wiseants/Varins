using System;

namespace HVision.Common.Tool
{
    public class UnityNameTool
	{
		public static string ConvertViewName(string name)
		{
			return String.Format("{0}View", name);
		}

		public static string ConvertViewModelName(string name)
		{
			return String.Format("{0}ViewModel", name);
		}

		public static string ConvertRegionName(string name)
		{
			return String.Format("{0}Region", name);
		}

		public static string ConvertSpecName(string name)
		{
			return String.Format("{0}Spec", name);
		}
	}
}

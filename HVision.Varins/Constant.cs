using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins
{
    public class Constant
    {
		#region Window names

		public static string MAIN_WINDOW { get => "Main"; }
		public static string LOGIN_WINDOW { get => "Login"; }
		public static string RESULT_WINDOW { get => "Result"; }
		#endregion

		#region Pane names

		public static string DISPLAY_PANE { get => "Display"; }
		public static string MESSAGE_PANE { get => "Message"; }
		public static string SPECLIST_PANE { get => "SpecList"; }
		public static string MENU_PANE { get => "Menu"; }
		public static string INFO_PANE { get => "Info"; }
		public static string GRAB_PANE { get => "Grab"; }
		public static string DRAWING_PANE { get => "Drawing"; }

		#endregion

		#region Control names
		public static string IMAGE_CONTROL { get => "Image"; }

		#endregion

		#region Shape names

		public static string ROUNDING_RECT_SHAPE { get => "RoundingRect"; }

		#endregion

		#region Value

		public static double MOUSE_TOLERANCE_SIZE = 5;

		#endregion
	}
}

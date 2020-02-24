using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Common
{
    public enum ResultType
    {
        None,
        Ok,
        Ng,
		Overkill
    }

    public enum ImageType
    {
        None,
        Vertical,
        Horizontal,
    }

	public enum ShapePointType
	{
		Left,
		Top,
		Right,
		Bottom,
		TopLeft,
		TopRigth,
		BottomLeft,
		BottomRight,
		RadiusX,
		RadiusY
	}

	public enum EditMode
	{
		Select,
		Drawing,
		Resizing,
		ShapeMoving,
		BackgroundMoving
	}
}

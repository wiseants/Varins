using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Common.Interface
{
    public interface IDrawingGridItem
    {
		string Name { get; }
		bool IsValid { get; set; }
		IList<string> EnableShapeNames { get; }
		string CountDescription { get; }
		string Description { get; }
	}
}

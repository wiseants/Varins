using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.Drawing
{
	public interface IDrawing
	{
		string Name { get; }
		int MinCount { get; }
		int MaxCount { get; }
		string Description { get; }
		IList<string> EnableShapeNames { get; }
	}
}

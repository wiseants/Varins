using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using System.Windows.Shapes;

namespace HVision.Common.Interface
{
	public interface IControlPoint : ICenterable, IFillContains, ICloneable
	{
		Brush Stroke { get; set; }
		Brush Fill { get; set; }
		void Dragged(object sender, object shape, Vector variation);
		void ChangedShape(object sender, object shape);
	}
}

using HVision.Common.Cores.Shapes;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models;
using HVision.Varins.Models.Drawing;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;

namespace HVision.Varins.Interfaces.Algorithms
{
	public interface IParameter
	{
		string Id { get; set; }
		IDictionary<string, IGrabImage> GrabImageMap { get; }
		IDictionary<string, IEnumerable<EditableShape>> EditableShapesMap { get; }
		IDictionary<string, ISpec> SpecMap { get; }
		IDeviceInfo DeviceInfo { get; }
	}
}

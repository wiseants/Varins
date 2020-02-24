using HVision.Common.Cores.Shapes;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models.Drawing;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace HVision.Varins.Models
{
	public class Parameter : IParameter
	{
		public string Id { get; set; }

		public IDictionary<string, IGrabImage> GrabImageMap { get; set; }
		public IDictionary<string, IEnumerable<EditableShape>> EditableShapesMap { get; set; }
		public IDictionary<string, ISpec> SpecMap { get; set; }
		public IDeviceInfo DeviceInfo { get; set; }
	}
}

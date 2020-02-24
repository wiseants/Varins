using HVision.Common;
using HVision.Common.Cores.Shapes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace HVision.Varins.Interfaces.Results
{
	public interface IInspectedResult
	{
		string Id { get; set; }
		string Description { get; set; }
		ResultType ResultType { get; set; }
		IDictionary<string, IResultObject> ResultObjectMap { get; set; }
	}
}

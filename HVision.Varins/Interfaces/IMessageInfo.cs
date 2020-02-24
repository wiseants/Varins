using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces
{
	public interface IMessageInfo
	{
		DateTime Time { get; }
		int Level { get; set; }
		string Category { get; set; }
		string Description { get; set; }
	}
}

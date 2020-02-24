using HVision.Varins.Interfaces.Results;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Interfaces.Algorithms
{
    public interface IAlgorithm
    {
        bool DoInspect(IParameter parameter, ref IInspectedResult inspectedResult);
    }
}

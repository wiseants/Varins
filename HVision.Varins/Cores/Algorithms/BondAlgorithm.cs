using HVision.Common;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.Results;
using HVision.Varins.Models.Spec;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Cores.Algorithms
{
	public class BondAlgorithm : IAlgorithm
	{
		private IUnityContainer _container = null;

		public BondAlgorithm(IUnityContainer container)
		{
			_container = container;
		}

		public bool DoInspect(IParameter parameter, ref IInspectedResult inspectedResult)
		{
			if (parameter.SpecMap["Bond"] is BondSpec spec)
			{
				inspectedResult.Description += String.Format("본드 이진화 값:{0} ", spec.BinarizationThreshold);
			}

			IResultObject resultObject = _container.Resolve<IResultObject>();
			resultObject.ResultType = ResultType.Ng;
			resultObject.Description = "본드 모르는 불량.";
			resultObject.GrabImageMap = new Dictionary<string, IGrabImage>()
			{
				{"Bond", parameter.GrabImageMap["Bond"] }
			};
			resultObject.ShapeMap = new Dictionary<string, EditableShape>()
			{
				{"Bond", parameter.EditableShapesMap["Bond"].First() }
			};

			inspectedResult.ResultObjectMap.Add("Bond", resultObject);

			foreach (var shape in parameter.EditableShapesMap["Bond"])
			{
				IRoundingRect rect = shape as IRoundingRect;
			}

			return true;
		}
	}
}

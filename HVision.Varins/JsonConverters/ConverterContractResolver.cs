using HVision.Common.Cores.Shapes;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Drawing;
using Microsoft.Practices.Unity;
using Newtonsoft.Json.Serialization;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.JsonConverters
{
	internal class ConverterContractResolver : DefaultContractResolver
	{
		private IUnityContainer _container = null;
		public ConverterContractResolver(IUnityContainer container)
		{
			_container = container;
		}

		protected override JsonContract CreateContract(Type objectType)
		{
			JsonContract contract = base.CreateContract(objectType);

			// this will only be called once and then cached
			if (objectType == typeof(EditableShape))
			{
				contract.Converter = _container.Resolve<EditableShapeConverter>();
			}
			else if (objectType == typeof(IDrawing))
			{
				contract.Converter = _container.Resolve<DrawingConverter>();
			}
			else if (objectType == typeof(ISpec))
			{
				contract.Converter = _container.Resolve<SpecConverter>();
			}

			return contract;
		}
	}
}

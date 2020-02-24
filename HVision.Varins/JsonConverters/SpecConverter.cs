using HVision.Varins.Interfaces.Algorithms;
using Microsoft.Practices.Unity;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.JsonConverters
{
	public class SpecConverter : JsonCreationConverter<ISpec>
	{
		public SpecConverter(IUnityContainer container)
			: base(container)
		{
		}

		protected override ISpec Create(Type objectType, JObject jObject)
		{
			return _container.Resolve<ISpec>(jObject["Name"].Value<string>());
		}
	}
}

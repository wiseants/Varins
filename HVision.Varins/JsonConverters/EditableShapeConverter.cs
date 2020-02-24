using HVision.Common.Cores.Shapes;
using Microsoft.Practices.Unity;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.JsonConverters
{
	public class EditableShapeConverter : JsonCreationConverter<EditableShape>
	{
		public EditableShapeConverter(IUnityContainer container)
			:base(container)
		{
		}

		protected override EditableShape Create(Type objectType, JObject jObject)
		{
			return _container.Resolve<EditableShape>(jObject["ContainerName"].Value<string>());
		}
	}
}

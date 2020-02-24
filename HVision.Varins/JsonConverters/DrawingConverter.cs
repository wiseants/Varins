using HVision.Common.Cores.Shapes;
using HVision.Varins.Interfaces.Drawing;
using Microsoft.Practices.Unity;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.JsonConverters
{
	public class DrawingConverter : JsonCreationConverter<IDrawing>
	{
		public DrawingConverter(IUnityContainer container)
			: base(container)
		{
		}

		protected override IDrawing Create(Type objectType, JObject jObject)
		{
			return _container.Resolve<IDrawing>(jObject["Name"].Value<string>());
		}
	}
}

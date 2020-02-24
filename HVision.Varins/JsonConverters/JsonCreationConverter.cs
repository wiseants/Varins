using HVision.Common.Interface;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.JsonConverters
{
	public abstract class JsonCreationConverter<T> : JsonConverter
	{
		protected IUnityContainer _container = null;
		public JsonCreationConverter(IUnityContainer container)
		{
			_container = container;
		}

		public override bool CanConvert(Type objectType)
		{
			return true;
		}

		public override object ReadJson(JsonReader reader,
										Type objectType,
										 object existingValue,
										 JsonSerializer serializer)
		{
			// Load JObject from stream
			JObject jObject = JObject.Load(reader);

			// Create target object based on JObject
			T target = Create(objectType, jObject);

			// Populate the object properties
			serializer.Populate(jObject.CreateReader(), target);

			return target;
		}

		public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
		{
			serializer.Serialize(writer, value);
		}
		protected bool FieldExists(string fieldName, JObject jObject)
		{
			return jObject[fieldName] != null;
		}


		protected abstract T Create(Type objectType, JObject jObject);
	}
}

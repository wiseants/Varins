using HVision.Common;
using HVision.Common.Cores.Shapes;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.Results;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace HVision.Varins.Models.Results
{
	[JsonObject(MemberSerialization.OptIn)]
	public class ResultObject : IResultObject
	{
		#region Fields

		private readonly IUnityContainer _container = null;

		#endregion

		#region Constructors

		public ResultObject(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		[JsonProperty]
		public string Id { get; set; }

		[JsonProperty]
		public string Description { get; set; }

		[JsonProperty]
		public ResultType ResultType { get; set; }

		[JsonIgnore]
		public IDictionary<string, IGrabImage> GrabImageMap { get; set; } = new Dictionary<string, IGrabImage>();

		[JsonProperty]
		public IDictionary<string, EditableShape> ShapeMap { get; set; } = new Dictionary<string, EditableShape>();

		#endregion
	}
}

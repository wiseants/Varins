using HVision.Common;
using HVision.Varins.Interfaces.Results;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Results
{
	[JsonObject(MemberSerialization.OptOut)]
	public class InspectedResult : IInspectedResult
	{
		#region Fields

		private readonly IUnityContainer _container = null;

		#endregion

		#region Constructors

		public InspectedResult(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		public string Id { get; set; }
		public string Description { get; set; }
		public ResultType ResultType { get; set; }
		public IDictionary<string, IResultObject> ResultObjectMap { get; set; } = new Dictionary<string, IResultObject>();

		#endregion
	}
}

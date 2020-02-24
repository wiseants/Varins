using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.ViewModels;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Cores
{
	[JsonObject(MemberSerialization.OptIn)]
	public class SpecController : BindableBase
	{
		private readonly IUnityContainer _container = null;

		public SpecController(IUnityContainer container, ISpec spec)
		{
			_container = container;
			Spec = spec;
		}

		[JsonProperty]
		public ISpec Spec { get; } = null;
	}
}

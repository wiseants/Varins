using Microsoft.Practices.Prism.Mvvm;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models
{
	[JsonObject(MemberSerialization.OptOut)]
	public class RoleInfo : BindableBase
	{
		#region Fields

		private int _index = -1;
		private IList<string> _authorityList = new List<string>();

		#endregion

		#region Properties

		[JsonProperty]
		public int Index
		{
			get => _index;
			set { SetProperty(ref _index, value); }
		}

		[JsonProperty]
		public IList<string> Authorities
		{
			get => _authorityList;
			set { SetProperty(ref _authorityList, value); }
		}

		#endregion
	}
}

using HVision.Common.Mvvm;
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
	public class AccountInfo : BindableBase
	{
		#region Fields

		private string _id = String.Empty;
		private string _password = String.Empty;
		private string _name = String.Empty;
		private string _description = String.Empty;
		private int _roleIndex = 0;
		private ObservableDictionary<int, RoleInfo> _roleInfoMap = new ObservableDictionary<int, RoleInfo>();

		#endregion

		#region Properties

		[JsonProperty]
		public string Id
		{
			get => _id;
			set { SetProperty(ref _id, value); }
		}

		[JsonProperty]
		public string Password
		{
			get => _password;
			set { SetProperty(ref _password, value); }
		}

		[JsonProperty]
		public string Name
		{
			get => _name;
			set { SetProperty(ref _name, value); }
		}

		[JsonProperty]
		public string Description
		{
			get => _description;
			set { SetProperty(ref _description, value); }
		}

		[JsonProperty]
		public int RoleIndex
		{
			get => _roleIndex;
			set { SetProperty(ref _roleIndex, value); }
		}

		[JsonIgnore]
		public RoleInfo Role
		{
			get
			{
				RoleInfo role = new RoleInfo();
				if (RoleInfoMap != null && RoleInfoMap.ContainsKey(RoleIndex) == true)
				{
					role = RoleInfoMap[RoleIndex];
				}

				return role;
			}
		}

		[JsonIgnore]
		public ObservableDictionary<int, RoleInfo> RoleInfoMap
		{
			get => _roleInfoMap;
			set { SetProperty(ref _roleInfoMap, value); }
		}

		#endregion
	}
}

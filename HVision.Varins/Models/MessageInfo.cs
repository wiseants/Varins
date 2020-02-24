using HVision.Varins.Interfaces;
using Microsoft.Practices.Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models
{
	public class MessageInfo : BindableBase, IMessageInfo
	{
		private readonly DateTime _time = DateTime.Now;
		private int _level = 0;
		private string _category = String.Empty;
		private string _description = String.Empty;

		public DateTime Time
		{
			get => _time;
		}

		public int Level
		{
			get => _level;
			set { SetProperty(ref _level, value); }
		}
		public string Category
		{
			get => _category;
			set { SetProperty(ref _category, value); }
		}

		public string Description
		{
			get => _description;
			set { SetProperty(ref _description, value); }
		}
	}
}

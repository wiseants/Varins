using HVision.Varins.Interfaces.Algorithms;
using Microsoft.Practices.Prism.Mvvm;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Spec
{
	[JsonObject(MemberSerialization.OptIn)]
	public class AlignSpec : BindableBase, ISpec
	{
		#region Fields

		private byte _binarizationThreshold = 0;

		#endregion

		#region Properties

		[JsonProperty]
		public string Name
		{
			get => "Align";
		}

		[JsonProperty]
		public byte BinarizationThreshold
		{
			get => _binarizationThreshold;
			set
			{
				SetProperty(ref _binarizationThreshold, value);

				App.Locator.DisplayViewModel.ImageViewModel.SelectedGrabName = Name;
				App.Locator.DisplayViewModel.ImageViewModel.BinarizationThreshold = _binarizationThreshold;
			}
		}

		#endregion
	}
}

using HVision.Common.Interface;
using HVision.Varins.Interfaces.Drawing;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Drawing
{
	public class AlignDrawing : BindableBase, IDrawing
	{
		#region Fields

		private readonly IUnityContainer _container = null;

		#endregion

		#region Constructors

		public AlignDrawing(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		public string Name
		{
			get => "Align";
		}

		public int MinCount
		{
			get => 4;
		}

		public int MaxCount
		{
			get => 4;
		}

		public IList<string> EnableShapeNames
		{
			get => new List<string>()
			{
				Constant.ROUNDING_RECT_SHAPE
			};
		}

		public string Description
		{
			get => "부품을 바른 위치에 정렬 시키기 위한 위한 그리기입니다.";
		}

		#endregion
	}
}

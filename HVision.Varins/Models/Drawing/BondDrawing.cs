using HVision.Varins.Interfaces.Drawing;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins.Models.Drawing
{
	public class BondDrawing : BindableBase, IDrawing
	{
		#region Fields

		private readonly IUnityContainer _container = null;

		#endregion

		#region Constructors

		public BondDrawing(IUnityContainer container)
		{
			_container = container;
		}

		#endregion

		#region Properties

		public string Name
		{
			get => "Bond";
		}

		public int MinCount
		{
			get => 2;
		}

		public int MaxCount
		{
			get => 2;
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
			get => "본드의 위치를 표시하는 그리기입니다.";
		}

		#endregion
	}
}

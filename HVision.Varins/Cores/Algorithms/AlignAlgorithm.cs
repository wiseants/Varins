using HVision.Common;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Common.Tool;
using HVision.Matrox;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.Results;
using HVision.Varins.Models.Spec;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace HVision.Varins.Cores.Algorithm
{
	public class AlignAlgorithm : IAlgorithm
    {
		private IUnityContainer _container = null;

		public AlignAlgorithm(IUnityContainer container)
		{
			_container = container;
		}

		public bool DoInspect(IParameter parameter, ref IInspectedResult inspectedResult)
        {
			if (parameter.SpecMap["Align"] is AlignSpec spec)
			{
				inspectedResult.Description += String.Format("정렬 이진화 값:{0} ", spec.BinarizationThreshold);
			}

			MilImage milImage = new MilImage();
			milImage.Alloc(MBandSize.Gray, 3776, 2684);
			milImage.Load(@"D:\HVModel\NANOS\00_0.bmp");
			Stopwatch watch = new Stopwatch();
			watch.Start();

			//for (int i = 0; i < 1000; i++)
			//{
			//	MilFilter.Median(milImage, milImage, 0, 0);
			//}

			List<MilImage> imageList = new List<MilImage>();
			for (int i = 0; i < 500; i++)
			{
				MilImage newImage = new MilImage();
				newImage.Alloc(MBandSize.Gray, 3776, 2684);
				newImage.CopyFrom(milImage, true);

				imageList.Add(newImage);
			}

			watch.Stop();

			IMessageInfo messageInfo = _container.Resolve<IMessageInfo>();
			messageInfo.Level = 1;
			messageInfo.Category = "측정";
			messageInfo.Description = String.Format("{0} ms", watch.ElapsedMilliseconds);
			App.Locator.MessageViewModel.MessageInfoList.Add(messageInfo);

			IResultObject resultObject = _container.Resolve<IResultObject>();
			resultObject.ResultType = ResultType.Ok;
			resultObject.Description = "정렬 정상.";
			resultObject.GrabImageMap = new Dictionary<string, IGrabImage>()
			{
				{"Align", parameter.GrabImageMap["Align"] }
			};
			resultObject.ShapeMap = new Dictionary<string, EditableShape>()
			{
				{"Align", parameter.EditableShapesMap["Align"].First() }
			};

			inspectedResult.ResultObjectMap.Add("Align", resultObject);

			foreach (var shape in parameter.EditableShapesMap["Align"])
			{
				IRoundingRect rect = shape as IRoundingRect;
			}

			return true;
        }
    }
}

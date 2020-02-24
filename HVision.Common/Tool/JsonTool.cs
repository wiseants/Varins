using Microsoft.Practices.Unity;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Common.Tool
{
	public class JsonTool<T>
	{
		public static void Export(string fileFullpath, object target)
		{
			string folderPath = Directory.GetParent(fileFullpath).FullName;
			if (Directory.Exists(folderPath) == false)
			{
				Directory.CreateDirectory(folderPath);
			}

			string writeString = JsonConvert.SerializeObject(target);
			if (String.IsNullOrEmpty(writeString) == false)
			{
				File.WriteAllText(fileFullpath, writeString);
			}
		}

		public static T Import(string fileName, JsonSerializerSettings settings = null)
		{
			T result = default(T);
			if (File.Exists(fileName) == false)
			{
				return result;
			}

			try
			{
				string readString = File.ReadAllText(fileName);
				if (String.IsNullOrEmpty(readString) == false)
				{
					result = JsonConvert.DeserializeObject<T>(readString, settings);
				}
			}
			catch (Exception ex)
			{
				// log
			}

			return result;
		}
	}
}

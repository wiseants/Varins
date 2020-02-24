using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Models;
using HVision.Varins.Modules;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace HVision.Varins.Interfaces.ViewModels
{
	public interface IMainWindowViewModel
	{
		event ChangedRecipe ChangedRecipe;
		event ChangedAccount ChangedAccount;

		Recipe CurrentRecipe { get; set; }
		AccountInfo CurrentAccount { get; set; }
		ObservableDictionary<int, GrabberController> GrabberControllerMap { get; }

		bool? OpenLoginWindow();
        void Close();
		void NewRecipe();
		void OpenRecipe();
		void CloseRecipe();
		void SaveRecipe();
		void SaveAsRecipe();
		void DoInspect();
	}
}

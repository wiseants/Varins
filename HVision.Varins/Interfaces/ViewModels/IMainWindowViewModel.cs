using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Models;

namespace HVision.Varins.Interfaces.ViewModels
{
    public interface IMainWindowViewModel
	{
        #region Fields

        event ChangedRecipe ChangedRecipe;
		event ChangedAccount ChangedAccount;

        #endregion

        #region Properties

        Recipe CurrentRecipe { get; set; }
		AccountInfo CurrentAccount { get; set; }
		ObservableDictionary<int, GrabberController> GrabberControllerMap { get; }

        #endregion

        #region Public methods

        bool? OpenLoginWindow();
        void Close();
		void NewRecipe();
		void OpenRecipe();
		void CloseRecipe();
		void SaveRecipe();
		void SaveAsRecipe();
		void DoInspect();

        #endregion
    }
}

using HVision.Varins.Cores;
using HVision.Varins.Models;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Globalization;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Varins
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
		#region Fields

		//public static event ChangedRecipe ChangedRecipe;
		//public static readonly string RECIPE_RESOURCE_KEY = "Recipe";
		public static readonly string LOCATOR_RESOURCE_KEY = "Locator";

		private static Bootstrapper _bootstrapper = null;

		#endregion

		#region Public methods

		public static Cores.ViewModelLocator Locator
		{
			get
			{
				return Current.Resources[LOCATOR_RESOURCE_KEY] as Cores.ViewModelLocator;
			}
		}

		//public static Recipe CurrentRecipe
		//{
		//	get
		//	{
		//		return Current.Resources[RECIPE_RESOURCE_KEY] as Recipe;
		//	}
		//	set
		//	{
		//		Recipe oldRecipe = null;

		//		if (Current.Resources.Contains(RECIPE_RESOURCE_KEY) == true)
		//		{
		//			oldRecipe = Current.Resources[RECIPE_RESOURCE_KEY] as Recipe;
		//			Current.Resources.Remove(RECIPE_RESOURCE_KEY);
		//		}

		//		Current.Resources.Add(RECIPE_RESOURCE_KEY, value);

		//		ChangedRecipe?.Invoke(null, value, oldRecipe);
		//	}
		//}

		public static DeviceInfo DeviceInfo { get; } = new DeviceInfo();

		public static IUnityContainer Container
		{
			get => _bootstrapper?.Container;
		}

		#endregion

		#region Override methods

		protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

			ViewModelLocationProvider.SetDefaultViewTypeToViewModelTypeResolver((viewType) =>
			{
				var viewName = viewType.FullName;
				var viewModelName = String.Format(CultureInfo.InvariantCulture, "{0}Model", viewName);
				return Type.GetType(viewModelName);
			});

			_bootstrapper = new Bootstrapper();
			_bootstrapper.Run();
        }

		#endregion
	}
}

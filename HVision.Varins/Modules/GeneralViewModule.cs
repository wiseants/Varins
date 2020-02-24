using HVision.Varins.Views;
using Microsoft.Practices.Prism.Mvvm;
using Prism.Modularity;
using Prism.Regions;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HVision.Varins.Models;
using HVision.Common.Tool;

namespace HVision.Varins.Modules
{
    public class GeneralViewModule : IModule
    {
        private readonly IRegionViewRegistry _regionViewRegistry;
		private readonly IUnityContainer _container = null;


		public GeneralViewModule(IUnityContainer container, IRegionViewRegistry registry)
        {
			_container = container;
			_regionViewRegistry = registry;
        }

        public void Initialize()
        {
			_regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.MENU_PANE), 
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.MENU_PANE)));
            _regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.INFO_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.INFO_PANE)));
            _regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.DISPLAY_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.DISPLAY_PANE)));
            _regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.MESSAGE_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.MESSAGE_PANE)));
			_regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.IMAGE_CONTROL),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.IMAGE_CONTROL)));
			_regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.GRAB_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.GRAB_PANE)));
			_regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.DRAWING_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.DRAWING_PANE)));
			_regionViewRegistry.RegisterViewWithRegion(
				UnityNameTool.ConvertRegionName(Constant.SPECLIST_PANE),
				() => _container.Resolve<IView>(UnityNameTool.ConvertViewName(Constant.SPECLIST_PANE)));
		}
	}
}

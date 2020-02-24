using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Common.Tool;
using HVision.Varins.Cores;
using HVision.Varins.Cores.Algorithm;
using HVision.Varins.Cores.Algorithms;
using HVision.Varins.Cores.Grab;
using HVision.Varins.Cores.Shapes;
using HVision.Varins.Interfaces;
using HVision.Varins.Interfaces.Algorithms;
using HVision.Varins.Interfaces.Drawing;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.Results;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using HVision.Varins.Models.Drawing;
using HVision.Varins.Models.Grab;
using HVision.Varins.Models.Results;
using HVision.Varins.Models.Spec;
using HVision.Varins.Modules;
using HVision.Varins.ViewModels.Controls;
using HVision.Varins.ViewModels.Panes;
using HVision.Varins.ViewModels.Windows;
using HVision.Varins.Views.Controls;
using HVision.Varins.Views.Panes;
using HVision.Varins.Views.Windows;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using Prism.Modularity;
using Prism.Unity;
using System;
using System.Windows;
using System.Windows.Controls;

namespace HVision.Varins
{
	public class Bootstrapper : UnityBootstrapper
    {

        protected override DependencyObject CreateShell()
        {
            BuildContainer(Container);
			//App.VarinsMain = Container.Resolve<VarinsMain>();

			App.Current.Resources = new ResourceDictionary
			{
				{ App.LOCATOR_RESOURCE_KEY, Container.TryResolve<Cores.ViewModelLocator>() }
			};

			return Container.TryResolve<MainWindow>();
        }

        protected override void InitializeShell()
        {
			Application.Current.MainWindow.Show();
		}

		protected override void ConfigureModuleCatalog()
        {
            base.ConfigureModuleCatalog();

            ModuleCatalog moduleCatalog = (ModuleCatalog)ModuleCatalog;
            moduleCatalog.AddModule(typeof(GeneralViewModule));
        }

        private bool BuildContainer(IUnityContainer container)
        {
            bool isResult = false;

            try
            {
				// 메인뷰.
				container.RegisterType<IView, MainWindow>(UnityNameTool.ConvertViewName(Constant.MAIN_WINDOW));
				container.RegisterType<IMainWindowViewModel, MainWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.MAIN_WINDOW));

				// 메뉴뷰.
				container.RegisterType<IView, MenuView>(UnityNameTool.ConvertViewName(Constant.MENU_PANE));
                container.RegisterType<IMenuViewModel, MenuViewModel>(UnityNameTool.ConvertViewModelName(Constant.MENU_PANE));

                // 메인뷰.
                container.RegisterType<IView, DisplayView>(UnityNameTool.ConvertViewName(Constant.DISPLAY_PANE));
                container.RegisterType<IDisplayViewModel, DisplayViewModel>(UnityNameTool.ConvertViewModelName(Constant.DISPLAY_PANE));

                // 로그뷰.
                container.RegisterType<IView, MessageView>(UnityNameTool.ConvertViewName(Constant.MESSAGE_PANE));
                container.RegisterType<IMessageViewModel, MessageViewModel>(UnityNameTool.ConvertViewModelName(Constant.MESSAGE_PANE));

                // 정보뷰.
                container.RegisterType<IView, InfoView>(UnityNameTool.ConvertViewName(Constant.INFO_PANE));
                container.RegisterType<IInfoViewModel, InfoViewModel>(UnityNameTool.ConvertViewModelName(Constant.INFO_PANE));

				// 그랩뷰.
				container.RegisterType<IView, GrabView>(UnityNameTool.ConvertViewName(Constant.GRAB_PANE));
				container.RegisterType<IGrabViewModel, GrabViewModel>(UnityNameTool.ConvertViewModelName(Constant.GRAB_PANE));

				// 드로잉뷰.
				container.RegisterType<IView, DrawingView>(UnityNameTool.ConvertViewName(Constant.DRAWING_PANE));
				container.RegisterType<IDrawingViewModel, DrawingViewModel>(UnityNameTool.ConvertViewModelName(Constant.DRAWING_PANE));

				// 스펙뷰.
				container.RegisterType<IView, SpecListView>(UnityNameTool.ConvertViewName(Constant.SPECLIST_PANE));
				container.RegisterType<ISpecListViewModel, SpecListViewModel>(UnityNameTool.ConvertViewModelName(Constant.SPECLIST_PANE));

				// 로그인 윈도우.
				container.RegisterType<IWindow, LoginWindow>(UnityNameTool.ConvertViewName(Constant.LOGIN_WINDOW));
				container.RegisterType<ILoginWindowViewModel, LoginWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.LOGIN_WINDOW));

				// 결과 윈도우.
				container.RegisterType<IWindow, ResultWindow>(UnityNameTool.ConvertViewName(Constant.RESULT_WINDOW));
				container.RegisterType<IResultWindowViewModel, ResultWindowViewModel>(UnityNameTool.ConvertViewModelName(Constant.RESULT_WINDOW));

				container.RegisterType<IView, ImageView>(UnityNameTool.ConvertViewName(Constant.IMAGE_CONTROL));

				// 모양.
				container.RegisterType<UserControl, RoundingRectView>(Constant.ROUNDING_RECT_SHAPE);
				container.RegisterType<EditableShape, EditableRoundingRect>(Constant.ROUNDING_RECT_SHAPE);

				// 그랩 정보..
				container.RegisterType<UserControl, GrabInfoView>();
				container.RegisterType<BindableBase, GrabInfoViewModel>();
				container.RegisterType<IGrabImage, GrabImage>();

				// 그래버.
				container.RegisterType<IGrabber, FileGrabber>("File");

				// 파라미터.
				container.RegisterType<IParameter, Parameter>();

				// 검사 결과.
				container.RegisterType<IResultObject, ResultObject>();
				container.RegisterType<IInspectedResult, InspectedResult>();

				// 드로잉.
				container.RegisterType<IDrawing, AlignDrawing>("Align");
				container.RegisterType<IDrawing, BondDrawing>("Bond");

				// 메세지.
				container.RegisterType<IMessageInfo, MessageInfo>();

				string name = "Align";
				container.RegisterType<IAlgorithm, AlignAlgorithm>(name);
				container.RegisterType<ISpec, AlignSpec>(name);
				container.RegisterType<UserControl, AlignSpecView>(name);

				name = "Bond";
				container.RegisterType<IAlgorithm, BondAlgorithm>(name);
				container.RegisterType<ISpec, BondSpec>(name);
				container.RegisterType<UserControl, BondSpecView>(name);

				isResult = true;
            }
            catch(Exception ex)
            {
                // exception.
            }

            return isResult;
        }
    }
}

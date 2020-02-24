using HVision.Common.Extension;
using HVision.Common.Interface;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace HVision.Common.Mvvm
{
    /// <summary>
    /// 기본 뷰 동작 핸들링이 가능한 기본 윈도우 클래스.
    /// </summary>
    public abstract class HandleableWindow : Window, IWindow, IView
	{
		#region Properties

		public IUnityContainer Container { get; set; }

		#endregion

		public HandleableWindow(IUnityContainer container)
		{
			Container = container;

			DataContextChanged += (sender, e) =>
			{
				if (e.NewValue is IWindowHandler viewModel)
				{
					DelegateBinding(viewModel);
				}
			};
		}

		private void DelegateBinding(IWindowHandler handler)
        {
            if (handler == null)
            {
                return;
            }

            // 윈도우 닫기 이벤트 핸들러 바인딩.
            handler.OnCloseEvent += (sender, result) =>
            {
                DialogResult = result;

                Close();
            };

			handler.OpenWindowEvent += (sender, windowName, viewModel) =>
			{
				var window = Container.Resolve<IWindow>(windowName);
				window.DataContext = viewModel;
				window.Owner = this;

				return window.ShowDialog();
			};
		}
	}
}

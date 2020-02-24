using HVision.Common.Mvvm;
using Microsoft.Practices.Unity;

namespace HVision.Varins.Views.Windows
{
	/// <summary>
	/// Interaction logic for ResultWindow.xaml
	/// </summary>
	public partial class ResultWindow : HandleableWindow
	{
		public ResultWindow(IUnityContainer container) : base(container)
		{
			InitializeComponent();
		}
	}
}

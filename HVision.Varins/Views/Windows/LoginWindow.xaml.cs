using HVision.Common.Mvvm;
using Microsoft.Practices.Unity;

namespace HVision.Varins.Views.Windows
{
	/// <summary>
	/// Interaction logic for LoginWindow.xaml
	/// </summary>
	public partial class LoginWindow : HandleableWindow
	{
		public LoginWindow(IUnityContainer container) : base(container)
		{
			InitializeComponent();
		}
	}
}

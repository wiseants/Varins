using HVision.Varins.Models;
using System;
using System.Windows;
using System.Windows.Controls;

namespace HVision.Varins.Behaviors
{
	/// <summary>
	/// 컨트롤 활성화/비활성화 비헤이비어.
	/// </summary>
	public static class CheckAuthorityBehavior
	{
		#region Fields

		public static readonly DependencyProperty AuthorityNameProperty = DependencyProperty.RegisterAttached(
			"AuthorityName",
			typeof(string), typeof(CheckAuthorityBehavior),
			new PropertyMetadata(String.Empty, OnAccountChanged));

		public static readonly DependencyProperty AccountProperty = DependencyProperty.RegisterAttached(
			"Account",
			typeof(AccountInfo), typeof(CheckAuthorityBehavior),
			new PropertyMetadata(null, OnAccountChanged));

		#endregion

		#region Public methods

		public static string GetAuthorityName(DependencyObject obj)
		{
			return (string)obj.GetValue(AuthorityNameProperty);
		}

		public static void SetAuthorityName(DependencyObject obj, string value)
		{
			obj.SetValue(AuthorityNameProperty, value);
		}

		public static AccountInfo GetAccount(DependencyObject obj)
		{
			return (AccountInfo)obj.GetValue(AccountProperty);
		}

		public static void SetAccount(DependencyObject obj, AccountInfo value)
		{
			obj.SetValue(AccountProperty, value);
		}

		#endregion

		#region Private methods

		private static void OnAccountChanged(object sender, DependencyPropertyChangedEventArgs e)
		{
			if (sender is Control control)
			{
				bool isEnabled = false;
				AccountInfo account = GetAccount(control);
				if (account != null && account.Role != null)
				{
					isEnabled = account.Role.Authorities.Contains(GetAuthorityName(control));
				}

				control.IsEnabled = isEnabled;
			}
		}

		#endregion
	}
}

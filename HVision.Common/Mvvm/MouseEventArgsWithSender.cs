﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace HVision.Common.Mvvm
{
	public class MouseEventArgsWithSender
	{
		#region Properties

		public object Sender
		{
			get;
			set;
		}

		public Point Position
		{
			get
			{
				return Args.GetPosition(Sender as IInputElement);
			}
		}

		public MouseEventArgs Args
		{
			get;
			set;
		}

		#endregion
	}
}

using HVision.Common.Interface;
using HVision.Common.Mvvm;
using HVision.Common.Tool;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Drawing;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using HVision.Varins.Models.Drawing;
using HVision.Varins.ViewModels.Controls;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace HVision.Varins.ViewModels.Panes
{
    public class DrawingViewModel : BindableBase, IDrawingViewModel
    {
		#region Fields

		private readonly IUnityContainer _container = null;
		private ObservableCollection<UserControl> _controls = new ObservableCollection<UserControl>();
		private ObservableCollection<DrawingController> _drawingControllerList = new ObservableCollection<DrawingController>();
		private DrawingController _selectedController = null;
		private int _selectedIndex = -1;

		#endregion

		#region Constructors

		public DrawingViewModel(IUnityContainer container)
		{
			_container = container;

			DrawCommand = new KentDelegateCommand(Draw, () => SelectedController != null && SelectedController.CanDraw == true);

			App.Locator.MainWindowViewModel.ChangedRecipe += App_ChangedRecipe; ;
		}

		#endregion

		#region Properties

		public ICommand DrawCommand
		{
			get;
			set;
		}

		public ObservableCollection<UserControl> Controls
		{
			get { return _controls; }
			set { SetProperty(ref _controls, value); }
		}

		public ObservableCollection<DrawingController> DrawingControllerList
		{
			get { return _drawingControllerList; }
			set { SetProperty(ref _drawingControllerList, value); }
		}

		public DrawingController SelectedController
		{
			get { return _selectedController; }
			set
			{
				if (_selectedController != null)
				{
					_selectedController.ShapeControllerList.CollectionChanged -= ShapeControllerList_CollectionChanged;
					Controls.Clear();
				}

				SetProperty(ref _selectedController, value);

				if (_selectedController != null)
				{
					_selectedController.ShapeControllerList.CollectionChanged += ShapeControllerList_CollectionChanged;
					foreach (EditableShapeController controller in _selectedController.ShapeControllerList)
					{
						UserControl newControl = _container.Resolve<UserControl>(controller.Name);
						newControl.DataContext = controller;

						Controls.Add(newControl);
					}
				}
			}
		}

		private void ShapeControllerList_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			Controls.Clear();

			foreach (EditableShapeController controller in _selectedController.ShapeControllerList)
			{
				UserControl newControl = _container.Resolve<UserControl>(UnityNameTool.ConvertViewName(controller.Name));
				newControl.DataContext = controller;

				Controls.Add(newControl);
			}
		}

		public int SelectedIndex
		{
			get { return _selectedIndex; }
			set
			{
				SetProperty(ref _selectedIndex, value);

				if (DrawingControllerList == null || App.Locator.MainWindowViewModel.CurrentRecipe == null)
				{
					return;
				}

				if (_selectedIndex >= 0 && _selectedIndex < DrawingControllerList.Count)
				{
					string selectedIndexName = DrawingControllerList[_selectedIndex].Drawing.Name;
					SelectedController = App.Locator.MainWindowViewModel.CurrentRecipe.DrawingControllerMap[selectedIndexName];
				}
			}
		}

		#endregion

		#region Public methods

		public void Draw()
		{
			if (SelectedController == null)
			{
				return;
			}

			IDrawing draiwing = SelectedController.Drawing;
			App.Locator.DisplayViewModel.ImageViewModel.StartDrawing(draiwing.Name, draiwing.EnableShapeNames.First());
		}

		#endregion

		#region Private methods

		private void App_ChangedRecipe(object sender, Recipe newRecipe, Recipe oldRecipe)
		{
			if (oldRecipe != null)
			{
				oldRecipe.DrawingControllerMap.CollectionChanged -= DrawingControllerMap_CollectionChanged;
				DrawingControllerList.Clear();
				SelectedController = null;
			}

			if (newRecipe != null)
			{
				newRecipe.DrawingControllerMap.CollectionChanged += DrawingControllerMap_CollectionChanged;
				DrawingControllerList = new ObservableCollection<DrawingController>(newRecipe.DrawingControllerMap.Values);
			}
		}

		private void DrawingControllerMap_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			DrawingControllerList = new ObservableCollection<DrawingController>(App.Locator.MainWindowViewModel.CurrentRecipe.DrawingControllerMap.Values);
		}

		#endregion
	}
}

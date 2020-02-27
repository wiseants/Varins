using HVision.Common;
using HVision.Common.Cores.Shapes;
using HVision.Common.Interface;
using HVision.Common.Mvvm;
using HVision.Varins.Cores;
using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Interfaces.ViewModels;
using HVision.Varins.Models;
using HVision.Varins.Models.Grab;
using Microsoft.Practices.Prism.Mvvm;
using Microsoft.Practices.Unity;
using OpenCvSharp;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Windows.Input;
using System.Windows.Shapes;

namespace HVision.Varins.ViewModels.Controls
{
    public class ImageViewModel : BindableBase, IImageViewModel
	{
		#region Fields

		private readonly IUnityContainer _container = null;
		private EditMode _dragMode = EditMode.Select;
		private bool _isDragging = false;
		private EditableShapeController _selectedShape = null;
		private string _selectedGrabName = null;
		private System.Windows.Point _draggedStartPoint;
		private ObservableCollection<Shape> _shapeList = new ObservableCollection<Shape>();
		private ObservableCollection<IGrabImage> _grabImageList = new ObservableCollection<IGrabImage>();
		private IGrabImage _currentImage = null;
		private IGrabImage _binarizedImage = null;
		private bool _isBinarized = false;
		private byte _binarizationThreshold = 0;

		#endregion

		#region Constructors

		public ImageViewModel(IUnityContainer container)
		{
			_container = container;

			MouseMoveCommand = new KentDelegateCommand<MouseEventArgsWithSender>(MouseMove);
			MouseLeftButtonUpCommand = new KentDelegateCommand<MouseButtonEventArgsWithSender>(MouseLeftButtonUp);
			MouseLeftButtonDownCommand = new KentDelegateCommand<MouseButtonEventArgsWithSender>(MouseLeftButtonDown);
			DeleteCommand = new KentDelegateCommand<KeyboardEventArgs>(Delete);

			_grabImageList.CollectionChanged += GrabImageList_CollectionChanged;

			App.Locator.MainWindowViewModel.ChangedRecipe += App_ChangedRecipe;
		}

		#endregion

		#region Properties

		public ICommand MouseMoveCommand
		{
			get;
			set;
		}

		public ICommand MouseLeftButtonUpCommand
		{
			get;
			set;
		}

		public ICommand MouseLeftButtonDownCommand
		{
			get;
			set;
		}

		public ICommand DeleteCommand
		{
			get;
			set;
		}

		public bool IsBinarized
		{
			get => _isBinarized;
			set
			{
				if (_isBinarized == value)
				{
					return;
				}

				SetProperty(ref _isBinarized, value);

				OnPropertyChanged("CurrentImage");
			}
		}

		public byte BinarizationThreshold
		{
			get => _binarizationThreshold;
			set
			{
				if (_binarizationThreshold == value)
				{
					return;
				}

				SetProperty(ref _binarizationThreshold, value);

				OnPropertyChanged("CurrentImage");
			}
		}

		public ObservableCollection<Shape> ShapeList
		{
			get => _shapeList;
			set { SetProperty(ref _shapeList, value); }
		}

		public IGrabImage CurrentImage
		{
			get
			{
				IGrabImage returnGrabImage = _currentImage;

				if (returnGrabImage != null && IsBinarized == true)
				{
					if (_binarizedImage != null)
					{
						_binarizedImage.Dispose();
					}

					_binarizedImage = _container.Resolve<IGrabImage>();
					_binarizedImage.GrabImageInfo = _currentImage.GrabImageInfo.Clone() as GrabImageInfo;

					Mat binaryImage = new Mat(_currentImage.MatImage.Size(), MatType.CV_8UC1);
					Cv2.CvtColor(_currentImage.MatImage, binaryImage, ColorConversionCodes.BGRA2GRAY);
					Cv2.Threshold(binaryImage, binaryImage, BinarizationThreshold, 255, type: ThresholdTypes.Binary);

					_binarizedImage.MatImage = binaryImage;
					returnGrabImage = _binarizedImage;
				}

				return returnGrabImage;
			}
			set
			{
				SetProperty(ref _currentImage, value);
			}
		}

		public IEnumerable<string> EnableGrabNames
		{
			get
			{
				return new HashSet<string>(_grabImageList.Select(x => x.GrabImageInfo.GrabInfo.Name));
			}
		}

		public string SelectedGrabName
		{
			get => _selectedGrabName;
			set
			{
				SetProperty(ref _selectedGrabName, value);

				var grabImages = _grabImageList.Where(x => x.GrabImageInfo.GrabInfo.Name == _selectedGrabName);
				if (grabImages.Count() <= 0)
				{
					return;
				}

				CurrentImage = grabImages.Last();
			}
		}

		public EditableShapeController SelectedShape
		{
			get => _selectedShape;
			set
			{
				if (_selectedShape == value)
				{
					return;
				}

				if (_selectedShape != null)
				{
					_selectedShape.IsSelected = false;
				}

				SetProperty(ref _selectedShape, value);

				if (_selectedShape != null)
				{
					_selectedShape.IsSelected = true;
				}

				OnPropertyChanged("ShapeList");
			}
		}

		public IControlPoint SelectedControlPoint
		{
			get;
			set;
		}

		public string Key
		{
			get;
			set;
		}

		public string ShapeContainerName
		{
			get;
			set;
		}

		#endregion

		#region Public methods

		public void StartDrawing(string key, string shapeName)
		{
			_dragMode = EditMode.Drawing;
			Key = key;
			ShapeContainerName = shapeName;
		}

		public void FinishedGrab(object sender, IGrabImage grabImage)
		{
			_grabImageList.Add(grabImage);

			OnPropertyChanged("EnableGrabNames");
		}

		public void Dispose()
		{
			_binarizedImage.Dispose();
		}

		#endregion

		#region Private methods

		private void MouseMove(MouseEventArgsWithSender e)
		{
			if (_isDragging == false)
			{
				return;
			}

			if (SelectedShape != null && _dragMode == EditMode.Drawing)
			{
				SelectedShape.Drawing(_draggedStartPoint, e.Position);
			}
			else if (SelectedShape != null && _dragMode == EditMode.ShapeMoving)
			{
				SelectedShape.Moving(_draggedStartPoint, e.Position);
			}
			else if (SelectedShape != null && _dragMode == EditMode.Resizing)
			{
				SelectedShape.Resizing(SelectedControlPoint, _draggedStartPoint, e.Position);
			}

			_draggedStartPoint = e.Position;
		}

		private void MouseLeftButtonDown(MouseButtonEventArgsWithSender e)
		{
			if (App.Locator.MainWindowViewModel.CurrentRecipe == null)
			{
				return;
			}

			SelectedShape = null;
			_isDragging = true;
			_draggedStartPoint = e.Position;

			if (_dragMode == EditMode.Drawing &&
				String.IsNullOrEmpty(Key) == false &&
				String.IsNullOrEmpty(ShapeContainerName) == false)
			{
				SelectedShape = _container.Resolve<EditableShapeController>(
					ShapeContainerName,
					new ResolverOverride[]
					{
						new ParameterOverride("shape", _container.Resolve<EditableShape>(ShapeContainerName)),
						new ParameterOverride("startPoint", _draggedStartPoint),
					});

				AddEditableShape(Key, SelectedShape);

				Key = String.Empty;
				ShapeContainerName = String.Empty;
			}
			else
			{
				foreach (var shape in App.Locator.MainWindowViewModel.CurrentRecipe.DrawingControllerMap.Values.SelectMany(x => x.ShapeControllerList))
				{
					if (shape.TryFillContains(e.Position, out IControlPoint containedPoint) == true)
					{
						SelectedShape = shape;
						SelectedControlPoint = containedPoint;
						_dragMode = containedPoint == null ? EditMode.ShapeMoving : _dragMode = EditMode.Resizing;
					}
				}
			}
		}

		private void MouseLeftButtonUp(MouseButtonEventArgsWithSender e)
		{
			_isDragging = false;
			_dragMode = EditMode.Select;
		}

		private void Delete(KeyboardEventArgs e)
		{

		}

		private void AddEditableShape(string key, EditableShapeController newShape)
		{
			App.Locator.MainWindowViewModel.CurrentRecipe.DrawingControllerMap[key].ShapeControllerList.Add(newShape);

			OnPropertyChanged("ShapeList");
		}

		private void RemoveEditableShape(string key)
		{
			App.Locator.MainWindowViewModel.CurrentRecipe.DrawingControllerMap.Remove(key);

			OnPropertyChanged("ShapeList");
		}

		private void CurrentRecipe_DrawingShapesChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			if (e.Action == NotifyCollectionChangedAction.Add)
			{
				foreach (Shape shape in e.NewItems)
				{
					ShapeList.Add(shape);
				}
			}
			else if (e.Action == NotifyCollectionChangedAction.Remove)
			{
				foreach (Shape shape in e.OldItems)
				{
					ShapeList.Remove(shape);
				}
			}
		}

		private void App_ChangedRecipe(object sender, Recipe newRecipe, Recipe oldRecipe)
		{
			if (oldRecipe != null)
			{
				oldRecipe.DrawingShapesChanged -= CurrentRecipe_DrawingShapesChanged;
				ShapeList.Clear();
			}

			if (newRecipe != null)
			{
				newRecipe.DrawingShapesChanged += CurrentRecipe_DrawingShapesChanged;
				ShapeList.AddRange(newRecipe.DrawingControllerMap.Values.SelectMany(x => x.ShapeControllerList).SelectMany(x => x.DrawingShapes));
			}
		}

		private void GrabImageList_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
		{
			SelectedGrabName = _grabImageList.Last().GrabImageInfo.GrabInfo.Name;
		}

		#endregion
	}
}

/************************************************************************/
/*
*
* Filename     :  MdispD3D.h
* Revision     :  10.10.0614
* Content      :  This file contains the defines and prototypes necessary 
*                 to run the MIL examples using 3D visualization displays.
*
* DISCLAIMER   :  THE FUNCTIONS DECLARED IN THIS FILE ARE NOT OFFICIALLY
*                 PART OF MIL AND ARE INCLUDED IN THE UNIQUE GOAL OF 
*                 RUNNING MIL EXAMPLES. 
*                 THESE FUNCTIONS CAN BE DEPRECATED, OR THEIR PROTOTYPES
*                 MODIFIED IN A FUTURE MIL RELEASE OR IN A PROCESSING PACK.
*
* Copyright � Matrox Electronic Systems Ltd., 1992-2015.
* All Rights Reserved
*************************************************************************/

/*
HOW TO COMPILE A PROJECT USING MDISPD3D
---------------------------------------

Include
-------

  To be able to use the C API of MdispD3D.dll, you must include MdispD3D.h in
  your project. This file can be found in %MIL_PATH%\..\Include.

Library
-------

  To be able to call the DLL functions, your project must link with the import
  library MdispD3D.lib. This file can be found in %MIL_PATH%\..\Lib.

DLL
---

  The actual compiled code is inside MdispD3D.dll, which is part of the
  installation of MIL. This file can be found in %MIL_PATH%.

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

MDISPD3D API
------------

--------------------------------------------------------------------------------
MIL_DISP_D3D_HANDLE

  This is an opaque type used to call functions on the D3D display object.

--------------------------------------------------------------------------------
MIL_DISP_D3D_HANDLE MdepthD3DAlloc(
   MIL_ID MilDepthImage,
   MIL_ID MilIntensityImage,
   MIL_INT DisplaySizeX,
   MIL_INT DisplaySizeY,
   MIL_DOUBLE ScaleX,
   MIL_DOUBLE ScaleY,
   MIL_DOUBLE ScaleZ,
   MIL_DOUBLE MinZ,
   MIL_DOUBLE MaxZ,
   MIL_DOUBLE MaximumDistanceZ,
   MIL_WINDOW_HANDLE WindowHandle
)

Description
-----------

  This function allocates an object that can display in 3D a depth map buffer.
  Each gray level in the depth map is translated to a proportional height in
  the 3D display. If an intensity buffer is provided, then the color of the
  given vertex in the 3D display will match the one in the intensity buffer,
  i.e. the intensity buffer can be seen as a texture mapped on the surface
  generated by the depth map buffer. If no intensity buffer is provided, then
  the vertex gray level will be proportional to its height, i.e. the depth map
  itself is mapped as a texture onto the surface.

Parameters
----------

MilDepthImage

  MIL_ID of the depth map buffer. It must be a 16 bits unsigned buffer
  (monochrome).

MilIntensityImage

  MIL_ID of the intensity buffer. It must be a 8 bits unsigned buffer, or it can
  be M_NULL if DepthBuffer is to be used as IntensityBuffer as well. It can
  be monochrome or color.

DisplaySizeX

  Width in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

DisplaySizeY

  Height in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

ScaleX

  The number of world units per pixel along the image X axis.
  It can be set to M_DEFAULT to get the scale from the calibration associated
  with MilDepthImage.

ScaleY

  The number of world units per pixel along the image Y axis.
  It can be set to M_DEFAULT to get the scale from the calibration associated
  with MilDepthImage.

ScaleZ

  The number of world units per gray level value. This value can be negative to
  flip the object upside down.
  It can be set to M_DEFAULT to get the scale from the calibration associated
  with MilDepthImage.
  
MinZ

   The minimum Z of a vertex that will be visible in the 3d scene.
   It can be set to M_DEFAULT to use the minimum Z value of the selected
   depth map buffer.

MaxZ

   The maximum Z of a vertex that will be visible in the 3d scene.
   It can be set to M_DEFAULT to use the maximum Z value of the selected 
   depth map buffer.

MaximumDistanceZ

   The maximum Z distance between two consecutive vertex for them to be
   considered as linked in the scene. This can be used to remove
   tall vertical surfaces where sharp elevations are.

WindowHandle

  Optional handle of a window that will be used to display. If 0, a new 
  framed window will be created.

Return value
------------

  An opaque handle to the D3D display object is returned if the allocation was
  successful, or M_NULL in case of failure. Use MdispD3DFree to free.

--------------------------------------------------------------------------------
void MdepthD3DSetImages(
   MIL_DISP_D3D_HANDLE DisplayID,
   MIL_ID MilDepthImage, 
   MIL_INT MilIntensityImage
)

Description
-----------

   This function resets the depth and the intensity images set to the 3D
   display. The scene is completely re rendered using the new images. 

Parameters
----------

DisplayID

   The D3D display handle returned by MdepthD3DAlloc().

MilDepthImage

   MIL_ID of the depth map buffer. It must be a 16 bits unsigned buffer
   (monochrome).

MilIntensityImage

   MIL_ID of the intensity buffer. It must be a 8 bits unsigned buffer, or it can
   be M_NULL if DepthBuffer is to be used as IntensityBuffer as well. It can
   be monochrome or color.

--------------------------------------------------------------------------------
MIL_DISP_D3D_HANDLE McalD3DAlloc(
   const MIL_ID* MilImageArrayPtr, 
   MIL_INT NumberOfImages,
   MIL_INT DisplaySizeX, 
   MIL_INT DisplaySizeY,
   MIL_WINDOW_HANDLE WindowHandle
)

Description
-----------

  This function allocates an object that can display in 3D images and the
  coordinate systems that are involved in their calibration.
  A grid is drawn on the z=0 plane of the absolute coordinate system.
  The images are rendered on their relative coordinate systems that are themselves
  positioned and oriented in the absolute coordinate system.
  Arrows are rendered at the origin of all coordinate systems.

Parameters
----------

MilImageArrayPtr

  Array of MIL_ID of the calibrated images. They must be associated to 
  3D calibration objects (M_TSAI_BASED or M_ROBOTIC_CALIBRATION).

NumberOfImages

  Number of images in MilImageArrayPtr.
  
DisplaySizeX

  Width in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

DisplaySizeY

  Height in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

WindowHandle

  Optional handle of a window that will be used to display. If 0, a new 
  framed window will be created.

Return value
------------

  An opaque handle to the D3D display object is returned if the allocation was
  successful, or M_NULL in case of failure. Use MdispD3DFree to free.

--------------------------------------------------------------------------------
MIL_DISP_D3D_HANDLE MstereoD3DAlloc(
   const MIL_ID* MilImageArrayPtr, 
   const double* XPixelArrayPtr, 
   const double* YPixelArrayPtr, 
   MIL_INT NumberOfImages, 
   MIL_INT NumPoints, 
   MIL_INT CommonCoordinateSystem,
   MIL_INT DisplaySizeX, 
   MIL_INT DisplaySizeY,
   MIL_WINDOW_HANDLE WindowHandle
)
   
Description
-----------

  This function allocates an object that can display multiple images
  in 3D along with lines starting at some image points, passing through
  the optical center of cameras that have grabbed the images (as used
  for 3D stereo triangulation).
  A grid is drawn on the z=0 plane of the absolute coordinate system.
  The images are rendered at some distance from the focal point
  (simulating the CCD plane).
  Arrows are rendered at the origin of all coordinate systems.

Parameters
----------

MilImageArrayPtr

  Array of MIL_ID of the calibrated images. They must be associated to 
  3D calibration objects (M_TSAI_BASED or M_ROBOTIC_CALIBRATION).

XPixelArrayPtr
YPixelArrayPtr
NumberOfImages
NumPoints
CommonCoordinateSystem
  
  Information about the points in each image that are used for 3D stereo
  triangulation. See documentation of M3dmapTriangulate() for more 
  information.
  
DisplaySizeX

  Width in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

DisplaySizeY

  Height in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

WindowHandle

  Optional handle of a window that will be used to display. If 0, a new 
  framed window will be created.

Return value
------------

  An opaque handle to the D3D display object is returned if the allocation was
  successful, or M_NULL in case of failure. Use MdispD3DFree to free.

--------------------------------------------------------------------------------
MIL_DISP_D3D_HANDLE MdepthSysD3DAlloc(
   const MIL_ID* Mil3dmapContextArrayPtr,
   const MIL_ID* MilLastImageArrayPtr,
   const MIL_ID* Mil3dmapResultArrayPtr,
   const MIL_ID* MilDepthMapArrayPtr,
   const MIL_ID* MilIntensityArrayPtr,
   MIL_INT NbSystem,
   MIL_INT DisplaySizeX,
   MIL_INT DisplaySizeY,
   MIL_DOUBLE MaxDistanceZ,
   MIL_WINDOW_HANDLE WindowHandle
)

Description
-----------

  This function allocates an object that can display all the component
  in a sheet of light 3d reconstruction system. It can display the following:
   - Depth maps where each gray level is translated to a proportional height.
     It is possible to change the color lut of the surface to be either
      - Grayscale
      - Pseudo-colored
      - Intensity (the color of the surface will map to the intensity image provided)
   - Depth map volume of visualisation.
   - Calibrated 3dmap context information.
      - The coordinate systems of the 3dmap context
      - The position of the sheet of light plane (the sheet of light, displayed
        as a red plane, can be replaced with the last image that was grabbed if
        provided)
      - The frustrum of the camera with the base on the sheet of light plane to 
        provide insight on the visible area that can be seen by each camera.

Parameters
----------

Mil3dmapContextArrayPtr

  Array of MIL_ID of 3dmap contexts. 

MilLastImageArrayPtr

  Array of MIL_ID of the last images from which the laser line was extracted 
  for each system. It must be a 8 bits unsigned buffer, or it can be M_NULL. 
  Can be M_NULL.

Mil3dmapResultArrayPtr

  Array of MIL_ID of 3dmap results. Is used to display the last laser line extracted.
  Can be M_NULL.

MilDepthMapArrayPtr

  Array of MIL_ID of depth map buffer. Must be a 16 bit unsigned buffer (monochrome)
  with a uniform calibration.
  Can be M_NULL.

MilIntensityArrayPtr

  Array of MIL_ID of the intensity buffer. They must be 8 bits unsigned buffers, or it can
  be M_NULL if the depth buffer is to be used as intensity image as well. It can
  be monochrome or color.

NbSystem

  The number of camera/sheet of light systems.

DisplaySizeX

  Width in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

DisplaySizeY

  Height in pixels of the DirectX window to open. Ignored if WindowHandle is 0.

MaxDistanceZ

   The maximum Z distance between two consecutive vertex for them to be
   considered as linked in the scene. This can be used to remove
   tall vertical surfaces where sharp elevations are.

WindowHandle

  Optional handle of a window that will be used to display. If 0, a new 
  framed window will be created.

Return value
------------

  An opaque handle to the D3D display object is returned if the allocation was
  successful, or M_NULL in case of failure. Use MdispD3DFree to free the allocated
  handle.

--------------------------------------------------------------------------------
void MdepthSysD3DSetSystems(
   MIL_DISP_D3D_HANDLE DisplayID,
   const MIL_ID* Mil3dmapContextArrayPtr,
   const MIL_ID* MilLastImageArrayPtr,
   const MIL_ID* Mil3dmapResultArrayPtr,
   const MIL_ID* MilDepthMapArrayPtr,
   const MIL_ID* MilIntensityArrayPtr,
   MIL_INT NbSystem,
   MIL_DOUBLE MaxDistanceZ
)


Description
-----------

   This function resets the all the information associated to a depth system
   display but keep the virtual camera information intact.

Parameters
----------

DisplayID

   The D3D display handle returned by MdepthD3DAlloc().

Mil3dmapContextArrayPtr
MilLastImageArrayPtr
Mil3dmapResultArrayPtr
MilDepthMapArrayPtr
MilIntensityArrayPtr
NbSystem
MaxDistanceZ

   See MdepthSysD3DAlloc for a description of those parameters.

--------------------------------------------------------------------------------
void MdepthSysD3DCopySystems(
   MIL_DISP_D3D_HANDLE DisplayID,
   const MIL_ID*  Mil3dmapContextArrayPtr,
   const MIL_ID*  MilLastImageArrayPtr,
   const MIL_ID*  Mil3dmapPtCldCntrPtr,   
   const MIL_INT* PtCldLabelsArrayPtr,
   const MIL_ID*  MilDepthMapArrayPtr,
   const MIL_ID*  MilIntensityArrayPtr,
   MIL_INT        NbSystem   
)

Description
-----------

   This function copies to the internal display object the MIL
   objects to display in the next call to MdepthSysD3DSetSystems
   (using M_NULL for objects already copied).
   It does not modify the currently displayed objects.   
   This function is not mandatory but can be convenient in some
   given application.

Parameters
----------

DisplayID

   The D3D display handle returned by MdepthSysD3DAlloc().

Mil3dmapContextArrayPtr
MilLastImageArrayPtr
Mil3dmapPtCldCntrPtr
MilDepthMapArrayPtr
MilIntensityArrayPtr
NbSystem

   See MdepthSysD3DAlloc for a description of those parameters.
--------------------------------------------------------------------------------
void MdispD3DShow(
  MIL_DISP_D3D_HANDLE DisplayID
)

Description
-----------

  This function shows the D3D display on screen.

Parameters
----------

DisplayID

  The D3D display handle returned by MdispD3DAlloc().

--------------------------------------------------------------------------------
void MdispD3DHide(
  MIL_DISP_D3D_HANDLE DisplayID
)

Description
-----------

  This function hides the D3D display on screen.

Parameters
----------

DisplayID

  The D3D display handle returned by MdispD3DAlloc().

--------------------------------------------------------------------------------
void MdispD3DPrintHelp(
  MIL_DISP_D3D_HANDLE DisplayID
)

Description
-----------

  This function prints a help message in the console with all keyboard and mouse
  controls supported by the D3D display.

Parameters
----------

DisplayID

  The D3D display handle returned by MdispD3DAlloc().

--------------------------------------------------------------------------------
void MdispD3DFree(
  MIL_DISP_D3D_HANDLE DisplayID
)

Description
-----------

  This function frees the D3D display object allocated by MdispD3DAlloc().

Parameters
----------

DisplayID

  The D3D display handle returned by MdispD3DAlloc().

*/

// Define type for display handle //
typedef void* MIL_DISP_D3D_HANDLE;

#ifdef __cplusplus
extern "C"
   {
#endif

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MdepthD3DAlloc
   //!
   //! \brief Initialize display to render a depth map. 
   //!        Must call Show() function to display in screen.
   //!
   //! \param MilDepthImage [in]    : MIL_ID of depth image.
   //! \param MilIntensityImage [in]: MIL_ID of intensity image (optional, can be M_NULL).
   //! \param DisplaySizeX [in]   : Window width (ignored if WindowHandle != 0)
   //! \param DisplaySizeY [in]   : Window height (ignored if WindowHandle != 0)
   //! \param ScaleX [in]         : The scaling use in x to generate mesh coordinate.
   //! \param ScaleY [in]         : The scaling use in y to generate mesh coordinate.
   //! \param ScaleZ [in]         : The scaling use in z to generate mesh coordinate.
   //!                              In (world unit)/(grey level). 
   //!
   //!                              1)if lower grey level in depth buffer are maximum height 
   //!                                 (ScaleZ<0)
   //!                              2)if lower grey level in depth buffer are minimum height 
   //!                                 (ScaleZ>0)
   //! \param MinZ [in]           : The minimum z visible in the display.
   //! \param MaxZ [in]           : The maximum z visible in the display.
   //! \param MaxDistanceZ [in]   : The maximum z distance to link two 3d points in the display.
   //! \param WindowHandle [in]   : The window into which display. 
   //!                              Optional, can be 0 (will create a new framed window).
   //!
   ////////////////////////////////////////////////////////////////////////////////
   MIL_DISP_D3D_HANDLE MdepthD3DAlloc(MIL_ID MilDepthImage, MIL_ID MilIntensityImage,
                                      MIL_INT DisplaySizeX, MIL_INT DisplaySizeY,
                                      MIL_DOUBLE ScaleX, MIL_DOUBLE ScaleY, MIL_DOUBLE ScaleZ,
                                      MIL_DOUBLE MinZ, MIL_DOUBLE MaxZ, MIL_DOUBLE MaxDistanceZ,
                                      MIL_WINDOW_HANDLE WindowHandle);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MdepthD3DSetImages
   //!
   //! \brief Reset the depth and intensity image buffers in the display.
   //!
   //! \param DisplayID        [in] : ID of the D3D display.
   //! \param MilDepthImage    [in] : MIL_ID of the depth image.
   //! \param MilIntensityImage[in] : MIL_ID of intensity image (optional, can be M_NULL).
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdepthD3DSetImages(MIL_DISP_D3D_HANDLE DisplayID,
                           MIL_ID MilDepthImage, 
                           MIL_INT MilIntensityImage);

   // Old name (for BW compatibility)
   MIL_DISP_D3D_HANDLE MdispD3DAlloc(MIL_ID MilDepthImage, MIL_ID MilIntensityImage,
                                     MIL_INT DisplaySizeX, MIL_INT DisplaySizeY,
                                     MIL_DOUBLE ScaleX, MIL_DOUBLE ScaleY, MIL_DOUBLE ScaleZ);


   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : McalD3DAlloc
   //!
   //! \brief Initialize display to render a calibrated image along with 
   //!        the coordinate systems positions. 
   //!        Must call Show() function to display in screen.
   //!
   //! \param MilImageArrayPtr [in] : Array of calibrated images.
   //! \param NumberOfImages [in] : Number of calibrated images.
   //! \param DisplaySizeX [in]   : Window width (ignored if WindowHandle != 0)
   //! \param DisplaySizeY [in]   : Window height (ignored if WindowHandle != 0)
   //! \param WindowHandle [in]   : The window into which display. 
   //!                              Optional, can be 0 (will create a new framed window).
   //!
   ////////////////////////////////////////////////////////////////////////////////
   MIL_DISP_D3D_HANDLE McalD3DAlloc(const MIL_ID* MilImageArrayPtr, 
                                    MIL_INT NumberOfImages,
                                    MIL_INT DisplaySizeX, MIL_INT DisplaySizeY,
                                    MIL_WINDOW_HANDLE WindowHandle);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : McalD3DSetImages
   //!
   //! \brief Initialize display to render a calibrated image along with 
   //!        the coordinate systems positions. 
   //!        Must call Show() function to display in screen.
   //!
   //! \param DisplayID        [in] : ID of the D3D display.
   //! \param MilImageArrayPtr [in] : Array of calibrated images.
   //! \param NumberOfImages   [in] : Number of calibrated images.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void McalD3DSetImages(MIL_DISP_D3D_HANDLE DisplayID,
                         const MIL_ID* MilImageArrayPtr, 
                         MIL_INT NumberOfImages);
   

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MdepthSysD3DAlloc
   //!
   //! \brief Initialize display to render a calibrated image along with 
   //!        the coordinate systems positions. 
   //!        Must call Show() function to display in screen.
   //!
   //! \param Mil3dmapContextArrayPtr  [in] : Array of 3dmap contexts.
   //! \param MilLastImageArrayPtr     [in] : Array containing the last images from which a 
   //!                                        sheet of light line was extracted. Optional,
   //!                                        M_NULL can be passed.
   //! \param Mil3dmapPtCldCntrPtr     [in] : Array of the 3dmap results. Optional, M_NULL
   //!                                        can be passed if not used.
   //! \param PtCldLabelsArrayPtr      [in] : Array of the point cloud labels to use.
   //!                                        Optional M_NULL if and only if Mil3dmapPtCldCntrPtr
   //!                                        is also M_NULL.
   //! \param MilDepthMapArrayPtr      [in] : Array of depth maps. A depth map can be passed
   //!                                        multiple times if it corresponds to multiple 
   //!                                        camera laser systems. Optional, can be M_NULL
   //!                                        if not used.
   //! \param MilIntensityArrayPtr     [in] : Array of images representing the intensity of 
   //!                                        the pixels of the depth map. Optional, can be M_NULL
   //!                                        if not used.
   //! \param NbSystem                 [in] : Number of calibrated systems.
   //! \param DisplaySizeX             [in] : Window width (ignored if WindowHandle != 0)
   //! \param DisplaySizeY             [in] : Window height (ignored if WindowHandle != 0)
   //! \param MaxDistanceZ             [in] : The maximum z distance to link two 3d points in the display.
   //! \param WindowHandle             [in] : The window into which display. 
   //!                                        Optional, can be 0 (will create a new framed window).
   //!
   ////////////////////////////////////////////////////////////////////////////////
   MIL_DISP_D3D_HANDLE MdepthSysD3DAlloc(const MIL_ID*  Mil3dmapContextArrayPtr,
                                         const MIL_ID*  MilLastImageArrayPtr,
                                         const MIL_ID*  Mil3dmapPtCldCntrPtr,
                                         const MIL_INT* PtCldLabelsArrayPtr,
                                         const MIL_ID*  MilDepthMapArrayPtr,
                                         const MIL_ID*  MilIntensityArrayPtr,
                                         MIL_INT NbSystem,
                                         MIL_INT DisplaySizeX, MIL_INT DisplaySizeY,
                                         MIL_DOUBLE MaxDistanceZ,
                                         MIL_WINDOW_HANDLE WindowHandle);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MdepthSysD3DCopySystems
   //!
   //! \brief Copies all the needed data for the next 3d display refresh.
   //!        This function is optional and exists as a convenience to 
   //!        have more flexibility over some applicative use.
   //!           
   //! \param DisplayID                [in] : ID of the D3D display.
   //! \param Mil3dmapContextArrayPtr  [in] : Array of 3dmap contexts.
   //! \param MilLastImageArrayPtr     [in] : Array containing the last images from which a 
   //!                                        sheet of light line was extracted. Optional,
   //!                                        M_NULL can be passed.
   //! \param Mil3dmapPtCldCntrPtr     [in] : Array of the 3dmap results. Optional, M_NULL
   //!                                        can be passed if not used.
   //! \param PtCldLabelsArrayPtr      [in] : Determine which point cloud in the corresponding
   //!                                        entry in Mil3dmapPtCldCntrPtr to use.
   //! \param MilDepthMapArrayPtr      [in] : Array of depth maps. A depth map can be passed
   //!                                        multiple times if it corresponds to multiple 
   //!                                        camera laser systems. Optional, M_NULL can 
   //!                                        be passed if not used.
   //! \param MilIntensityArrayPtr     [in] : Array of images representing the intensity of 
   //!                                        the pixels of the depth map. Optional, can be M_NULL
   //!                                        if not used.
   //! \param NbSystem                 [in] : Number of calibrated systems.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdepthSysD3DCopySystems(MIL_DISP_D3D_HANDLE DisplayID,
                                const MIL_ID*  Mil3dmapContextArrayPtr,
                                const MIL_ID*  MilLastImageArrayPtr,
                                const MIL_ID*  Mil3dmapPtCldCntrPtr,
                                const MIL_INT* PtCldLabelsArrayPtr,
                                const MIL_ID*  MilDepthMapArrayPtr,
                                const MIL_ID*  MilIntensityArrayPtr,
                                MIL_INT        NbSystem);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MdepthSysD3DSetSystems
   //!
   //! \brief Initialize display to render a sheet of light 3d reconstruction
   //!        system.  
   //!        Must call Show() function to display in screen.
   //!        MdepthSysD3DCopySystems can be called to optionally copy the 
   //!        MIL objects to display. Pass M_NULL when objects are already
   //!        copied.
   //!
   //! \param DisplayID                [in] : ID of the D3D display.
   //! \param Mil3dmapContextArrayPtr  [in] : Array of 3dmap contexts.
   //! \param MilLastImageArrayPtr     [in] : Array containing the last images from which a 
   //!                                        sheet of light line was extracted. Optional,
   //!                                        M_NULL can be passed.
   //! \param Mil3dmapPtCldCntrPtr     [in] : Array of the 3dmap results. Optional, M_NULL
   //!                                        can be passed if not used.
   //! \param PtCldLabelsArrayPtr      [in] : Determine which point cloud in the corresponding
   //!                                        entry in Mil3dmapPtCldCntrPtr to use. Optional,
   //!                                        M_NULL can be passed if not used.
   //! \param MilDepthMapArrayPtr      [in] : Array of depth maps. A depth map can be passed
   //!                                        multiple times if it corresponds to multiple 
   //!                                        camera laser systems. Optional, M_NULL can 
   //!                                        be passed if not used.
   //! \param MilIntensityArrayPtr     [in] : Array of images representing the intensity of 
   //!                                        the pixels of the depth map. Optional, can be M_NULL
   //!                                        if not used.
   //! \param NbSystem                 [in] : Number of calibrated systems.
   //! \param MaxDistanceZ             [in] : The maximum z distance to link two 3d points in the display.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdepthSysD3DSetSystems(MIL_DISP_D3D_HANDLE DisplayID,
                               const MIL_ID*  Mil3dmapContextArrayPtr,
                               const MIL_ID*  MilLastImageArrayPtr,
                               const MIL_ID*  Mil3dmapPtCldCntrPtr,
                               const MIL_INT* PtCldLabelsArrayPtr,
                               const MIL_ID*  MilDepthMapArrayPtr,
                               const MIL_ID*  MilIntensityArrayPtr,
                               MIL_INT        NbSystem,
                               MIL_DOUBLE     MaxDistanceZ);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Name         : MstereoD3DAlloc
   //!
   //! \brief Initialize display. Must call Show() function to display in screen.
   //!
   //! For the first 6 parameters, see the documentations of M3dmapTriangulate.
   //! \param MilImageArrayPtr [in] : Array of MilID of calibrated images.
   //! \param XPixelArrayPtr [in] : X coordinates of points in image for stereo
   //! \param YPixelArrayPtr [in] : Y coordinates of points in image for stereo
   //! \param NumberOfImages [in] : Number of images
   //! \param NumPoints [in]      : Number of points in each image
   //! \param CommonCoordinateSystem [in] : Coordinate system shared by all images
   //!
   //! \param DisplaySizeX [in]   : Window width (ignored if WindowHandle != 0)
   //! \param DisplaySizeY [in]   : Window height (ignored if WindowHandle != 0)
   //! \param WindowHandle [in]   : The window into which display. 
   //!                              Optional, can be 0 (will create a new framed window).
   //!
   ////////////////////////////////////////////////////////////////////////////////
   MIL_DISP_D3D_HANDLE MstereoD3DAlloc(const MIL_ID* MilImageArrayPtr, 
                                       const double* XPixelArrayPtr, 
                                       const double* YPixelArrayPtr, 
                                       MIL_INT NumberOfImages, MIL_INT NumPoints, 
                                       MIL_INT CommonCoordinateSystem,
                                       MIL_INT DisplaySizeX, MIL_INT DisplaySizeY,
                                       MIL_WINDOW_HANDLE WindowHandle);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DShow
   //!  Access       : public
   //!
   //! \brief Show Display on screen.
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdispD3DShow(MIL_DISP_D3D_HANDLE DisplayID);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DHide
   //!  Access       : public
   //!
   //! \brief Hide Display on screen.
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdispD3DHide(MIL_DISP_D3D_HANDLE DisplayID);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DPrintHelp
   //!  Access       : public
   //!
   //! \brief Print help message in console.
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //!
   ////////////////////////////////////////////////////////////////////////////////
   void MdispD3DPrintHelp(MIL_DISP_D3D_HANDLE DisplayID);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DFree
   //!  Access       : public
   //!
   //! \brief Release all allocation for this display ID.
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //!
   ////////////////////////////////////////////////////////////////////////////////   
   void MdispD3DFree(MIL_DISP_D3D_HANDLE DisplayID);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DControl
   //!  Access       : public
   //!
   //! \brief Controls some parameters of the 3D display
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //! \param ControlType [in]  : Parameter to change in the 3d display
   //! \param ControlValue [in] : Parameter value
   //!                            M_ROTATE :                   M_TRUE
   //!                                                         M_FALSE
   //!                            M_POINT  :                   M_ENABLE
   //!                                                         M_DISABLE   
   //!                            M_LUT    :                   M_GRAYSCALE
   //!                                                         M_COLOR
   //!                                                         M_INTENSITY    
   //!                            M_VOLUME :                   M_NONE
   //!                                                         M_TRANSPARENT
   //!                                                         M_OPAQUE 
   //!                            M_CAMERA :                   M_ENABLE
   //!                                                         M_DISABLE
   //!                            M_IMAGE :                    M_ENABLE
   //!                                                         M_DISABLE
   //!
   ////////////////////////////////////////////////////////////////////////////////   
   bool MdispD3DControl(MIL_DISP_D3D_HANDLE DisplayID, MIL_INT64 ControlType, MIL_DOUBLE ControlValue);

   ////////////////////////////////////////////////////////////////////////////////
   //!  Class        :  
   //!  Name         : MdispD3DInquire
   //!  Access       : public
   //!
   //! \brief Inquires some parameters of the 3D display
   //!
   //! \param DisplayID [in]    : ID of the D3D display.
   //! \param Index [in]        : Index (if required) of the object parameter to inquire
   //!                            Can be M_GENERAL or Value (0 to NbSystem)
   //! \param InquireType [in]  : Parameter to inquire in the 3d display
   //! \param UserDataPtr [in]  : Parameter value
   //!                            M_ROTATE :                   M_TRUE
   //!                                                         M_FALSE
   //!                            M_POINT  :                   M_ENABLE
   //!                                                         M_DISABLE   
   //!                            M_LUT    :                   M_GRAYSCALE
   //!                                                         M_COLOR
   //!                                                         M_INTENSITY    
   //!                            M_VOLUME :                   M_NONE
   //!                                                         M_TRANSPARENT
   //!                                                         M_OPAQUE 
   //!                            M_CAMERA :                   M_ENABLE
   //!                                                         M_DISABLE
   //!                            M_IMAGE :                    M_ENABLE
   //!                                                         M_DISABLE
   //!
   //!                            M_SUBSAMPLE_X
   //!                            M_SUBSAMPLE_Y:               Values
   //!
   ////////////////////////////////////////////////////////////////////////////////   
   MIL_INT MdispD3DInquire(MIL_DISP_D3D_HANDLE DisplayID, MIL_INT Index, MIL_INT64 InquireType, MIL_DOUBLE* UserDataPtr);
#ifdef __cplusplus
   }
#endif
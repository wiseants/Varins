using HVision.Matrox;
using OpenCvSharp;
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Windows;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace HVision.Varins.Cores
{
	/// <summary>
	/// 이미지 변환기 클래스.
	/// </summary>
	public class GrabImageConverter
	{
		/// <summary>
		/// bate array ==> BitmapSource 변환기.
		/// </summary>
		/// <param name="array">버퍼.</param>
		/// <param name="width">폭.</param>
		/// <param name="height">높이.</param>
		/// <returns></returns>
		public static BitmapSource BufferToBitmapSource(byte[] array, int width, int height, System.Windows.Media.PixelFormat format)
		{
			WriteableBitmap bitmap = new WriteableBitmap(width, height, 96, 96, format, null);
			if (array != null && array.Count() > 0)
			{
				bitmap.WritePixels(new Int32Rect(0, 0, width, height), array, width * (format.BitsPerPixel / 8), 0);
			}

			return bitmap;
		}

		/// <summary>
		/// BitmaSource ==> byte array 변환기.
		/// </summary>
		/// <param name="bitmapSource">비트맵 소스.</param>
		/// <returns></returns>
		public static byte[] BitmapSourceToBuffer(BitmapSource bitmapSource)
		{
			if (bitmapSource == null)
			{
				return null;
			}
			
			int stride = bitmapSource.PixelWidth * (bitmapSource.Format.BitsPerPixel / 8);
			byte[] byteArray = new byte[bitmapSource.PixelHeight * stride];

			bitmapSource.CopyPixels(byteArray, stride, 0);

			return byteArray;
		}

		/// <summary>
		/// bate array ==> Mat 변환기.
		/// </summary>
		/// <param name="array">버퍼.</param>
		/// <param name="width">폭.</param>
		/// <param name="height">높이.</param>
		/// <returns></returns>
		public static Mat BufferToMatImage(byte[] buffer, int width, int heigth)
		{
			if (buffer == null || buffer.Length <= 0)
			{
				return null;
			}

			return Mat.FromImageData(buffer, ImreadModes.Color);
			//Mat grayscaleMat = Mat.FromImageData(buffer, ImreadModes.GrayScale);
			//Mat alt = Cv2.ImDecode(imageData, ImreadModes.GrayScale);
		}

		/// <summary>
		/// Mat ==> byte array 변환기.
		/// </summary>
		/// <param name="matImage">매트릭스</param>
		/// <returns></returns>
		public static byte[] MatToBuffer(Mat matImage)
		{
			byte[] buffer = null;

			if (matImage == null)
			{
				return buffer;
			}

			Cv2.ImEncode(".bmp", matImage, out buffer);

			return buffer;
		}

		/// <summary>
		/// bate array ==> MilImage 변환기.
		/// </summary>
		/// <param name="array">버퍼.</param>
		/// <param name="width">폭.</param>
		/// <param name="height">높이.</param>
		/// <returns></returns>
		public static MilImage BufferToMilImage(byte[] buffer, int width, int heigth)
		{
			MilImage newMilImage = new MilImage();
			newMilImage.CreateColor(width, heigth, buffer);

			return newMilImage;
		}

		/// <summary>
		/// MilImage ==> byte array 변환기.
		/// </summary>
		/// <param name="matImage">MIL 이미지.</param>
		/// <returns></returns>
		public static byte[] MilImageToBuffer(MilImage milImage, System.Windows.Media.PixelFormat Format)
		{
			byte[] buffer = new byte[milImage.GetBufferSize()];

			milImage.GetColor((Format.BitsPerPixel / 8), buffer);

			System.Drawing.Size imageSize = (System.Drawing.Size)milImage.GetImageSize();

			return buffer;
		}
	}
}

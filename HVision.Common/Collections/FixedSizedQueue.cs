// https://stackoverflow.com/questions/5852863/fixed-size-queue-which-automatically-dequeues-old-values-upon-new-enques

using System.Collections.Concurrent;

namespace HVision.Common.Collections
{
	/// <summary>
	/// 고정된 개수의 원소를 가지는 동기화큐.
	/// 고정된 개수를 넘어가는 경우 자동으로 빠진다.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	public class FixedSizedQueue<T>
	{
		#region Fields

		private ConcurrentQueue<T> _queue = new ConcurrentQueue<T>();
		private readonly object _lockObject = new object();

		#endregion

		#region Properties

		/// <summary>
		/// 큐 최대 개수.
		/// </summary>
		public int Limit { get; set; }

		#endregion

		#region Public methods

		/// <summary>
		/// 큐에 입력.
		/// </summary>
		/// <param name="obj"></param>
		public void Enqueue(T obj)
		{
			_queue.Enqueue(obj);
			lock (_lockObject)
			{
				while (_queue.Count > Limit && _queue.TryDequeue(out T overflow));
			}
		}

		#endregion
	}
}

#pragma once

namespace HVision
{
	namespace Matrox
	{
		public ref struct MModelOffsetInfo
		{
		private:
			ModelOffsetInfo * m_pModelOffsetInfo = nullptr;

		protected:
			!MModelOffsetInfo();

		public:
			MModelOffsetInfo();
			~MModelOffsetInfo();

			ModelOffsetInfo * GetUInstance();
		};
	}
}
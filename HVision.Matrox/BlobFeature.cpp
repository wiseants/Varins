#include "stdafx.h"
#include "MBlobBox.h"

using namespace HVision::Matrox;

void BlobFeature::Init()
{
	double milVersion;
	::MappInquire(M_VERSION, &milVersion);

	if (long(milVersion) > 6 && milVersion < 7.5)
	{
		FERET_X = 4;
		FIRST_POINT_X = 10;
		FIRST_POINT_Y = 11;
		CHAIN_Y = 66;
	}
}
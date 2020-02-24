#include "stdafx.h"
#include "Enumerator.h"

using namespace HVision::Matrox;


MBandSize::MBandSize(EBandSize bandSize)
{
	_bandSize = bandSize;
}

EBandSize MBandSize::GetEBandSize()
{
	return _bandSize;
}
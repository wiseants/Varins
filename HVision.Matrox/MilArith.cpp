#include "stdafx.h"
#include "MilArith.h"

using namespace HVision::Matrox;

void MilArith::MilArith::Add(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Add(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance(), bSaturation);
}

void MilArith::And(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::And(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Divide(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Divide(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Max(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Max(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Min(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Min(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Multiply(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Multiply(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance(), bSaturation);
}

void MilArith::Nand(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Nand(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Nor(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Nor(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Or(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Or(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Subtract(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Subtract(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance(), bSaturation);
}

void MilArith::AbsSubtract(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::AbsSubtract(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance(), bSaturation);
}

void MilArith::Xor(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage)
{
	CMilArith::Xor(pSrcImage1->GetUInstance(), pSrcImage2->GetUInstance(), pDestImage->GetUInstance());
}

ULONG MilArith::CountDifference(MilImage^ pSrcImage, MilImage^ pSrcImage2)
{
	return CMilArith::CountDifference(pSrcImage->GetUInstance(), pSrcImage2->GetUInstance());
}

void MilArith::Add(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Add(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance(), bSaturation);
}

void MilArith::And(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::And(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Divide(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Divide(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Max(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Max(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Min(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Min(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Multiply(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Multiply(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance(), bSaturation);
}

void MilArith::Nand(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Nand(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Nor(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Nor(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Or(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Or(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Xor(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage)
{
	CMilArith::Xor(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance());
}

void MilArith::Subtract(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation)
{
	CMilArith::Subtract(pSrcImage->GetUInstance(), fConstant, pDestImage->GetUInstance(), bSaturation);
}

void MilArith::Abs(MilImage^ pSrcImage, MilImage^ pDestImage)
{
	CMilArith::Abs(pSrcImage->GetUInstance(), pDestImage->GetUInstance());
}

void MilArith::Not(MilImage^ pSrcImage, MilImage^ pDestImage)
{
	CMilArith::Not(pSrcImage->GetUInstance(), pDestImage->GetUInstance());
}
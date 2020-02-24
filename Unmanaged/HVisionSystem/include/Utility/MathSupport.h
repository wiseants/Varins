#pragma once

#include "Defines.h"
#include "UtilityClass.h"

#define PI	3.14159265

struct LineStruct
{
	TPoint ptStart;
	TPoint ptEnd;
	TPoint ptCross;

	BOOL bCross;

	// ����
	double lfAnc;
	// Y �����
	double b;

	double lfDistanceX;
	double lfDistanceY;

	BOOL bVertical;
	BOOL bHorizon;

	LineStruct(TPoint pt1, TPoint pt2)
	{
		ptStart = pt1;
		ptEnd = pt2;
		ptCross = TPoint(0, 0);

		lfDistanceX = ptEnd.x - ptStart.x;
		lfDistanceY = ptEnd.y - ptStart.y;

		lfAnc = 1;
		b = 0;

		bCross = FALSE;
		bVertical = FALSE;
		bHorizon = FALSE;

		if (lfDistanceX == 0 )
		{
			bVertical = TRUE;
		}
		else if (lfDistanceY == 0)
		{
			bHorizon = TRUE;
			lfAnc = 0;
			b = ptStart.y;
		}
		else
		{
			// ������ �ƴ� ��쿡 ����� ���Ѵ�.
			lfAnc = lfDistanceY / lfDistanceX;
			b = ptStart.y - (lfAnc * ptStart.x);
		}
	}

	void Calculate(LineStruct& line)
	{
		bCross = TRUE;

		// ���Ⱑ ������ ���༱�̹Ƿ� ������ �� ����.
		if ((bVertical && line.bVertical)
			|| (bHorizon && line.bHorizon)
			|| lfAnc == line.lfAnc)
		{
			bCross = FALSE;
			return;
		}

		// ������ ���ϱ�
		double x = 0.f;
 		double y = 0.f;

		if (line.bVertical)
		{
			x = line.ptStart.x;
			if (bHorizon)
				y = ptStart.y;
			else
				y = lfAnc * x + b;
		}
		else if (line.bHorizon)
		{
			y = line.ptStart.y;
			if (bVertical)
				x = ptStart.x;
			else
				x = (y - b) / lfAnc;
		}
		else if (bVertical)
		{
			x = ptStart.x;
			y = line.lfAnc * x + line.b;
			
		}
		else if (bHorizon)
		{
			y = ptStart.y;
			x = (y - line.b) / line.lfAnc;
		}
		else
		{
			x = (line.b - b) / (lfAnc - line.lfAnc);
			y = lfAnc * x + b;
		}

		// ������
		ptCross.x = x;
		ptCross.y = y;

		TRect rc;
		rc.SetRect(ptStart, ptEnd);
		rc.NormalizeRect();

		if (!rc.PtInRect(ptCross))
			bCross = FALSE;

		// �������� �����ϴ� ���� �����ȿ� �ִ��� ����
		rc.SetRect(line.ptStart, line.ptEnd);
		rc.NormalizeRect();

		if (!rc.PtInRect(ptCross))
			bCross = FALSE;
	}

	BOOL IsCross()
	{
		return bCross;
	}
};

class UTILITYCLASS CMathSupport
{
public:
	CMathSupport();
	~CMathSupport();

	// ������ ���ڸ� 2�� 3���� ���μ����� �� �������� �����´�.(���� Grid ������ ����)
	static void SqrtEx(int nNumber, int& nValue, int& nMod);
	// 2���� ������ �����ߴ��� üũ�Ѵ�.
	static BOOL IsCrossLine(TPoint line1Pt1, TPoint line1Pt2, TPoint line2Pt1, TPoint line2Pt2);
	static double GetDistance(TPoint pt1, TPoint pt2);
	static double GetLineToPointDistance(TPoint linePt1, TPoint linePt2, TPoint pt);
	static double GetAngle(const TPoint& ptCenter, const TPoint& point1, const TPoint& point2, BOOL bNoMinusAngle = TRUE);
	static double GetAngle(const TPoint& point1, const TPoint& point2, BOOL bNoMinusAngle = TRUE);
	static BOOL IsCrossRect(TRect dragRect, TPoint ptStart, TPoint ptEnd);

	/************************************************************************/
	// �ε� �Ҽ��� Plus ����
	// �ε� �Ҽ����� ���� ��� Double ������ ����� ������ ���� �Էµ� �� �ִ�.
	// �׷��� �� �Լ��� �̿��Ͽ� �����ο� �Ҽ��θ� String���� �����Ͽ� ���� �����ϰ�,
	// �Ҽ� 3��° �ڸ����� 0�� ���� ��� 0�� ���Ͻ�Ų��.
	/************************************************************************/
	static double FloatingPlus(double lfA, double lfB);
	static int CompareDoubleAbsoulte(double x, double y, double absTolerance = (1.0e-8));
	static double Round(double lfValue, int nPos, BOOL fFloor = FALSE);
	static double Rounding(double x, int digit);
	static void Switch(long& a, long& b);
	static void Switch(float& a, float& b);
	static void Switch(double& a, double& b);
	static TPoint GetCrossPoint(TPoint Line1Pt1, TPoint Line1Pt2, TPoint Line2Pt1, TPoint Line2Pt2);
	static TPoint GetCrossPoint(double lfSlope1, double lfInterruptY1, double lfSlope2, double lfInterruptY2);
	static TPoint GetCrossPoint(TPoint LinePt1, TPoint LinePt2, double lfSlope, double lfInterruptY);

	static BOOL IsCrossArc(TRect rcCircle, double lfStartAngle, double lfEndAngle, TRect rc, TPoint* _ptCross = NULL);
	static BOOL IsCrossArc(TRect rcCircle, double lfStartAngle, double lfEndAngle, TPoint ptStart, TPoint ptEnd, TPoint* _ptCross = NULL);

	static BOOL GetIntersectPoint(const TPoint& AP1, const TPoint& AP2, const TPoint& BP1, const TPoint& BP2, TPoint* IntersectP);
	static CdblPoint RotatePoint(CdblPoint pt, CdblPoint centerPt, double degree);
	static double GetPolygonsArea(TPoint* pt, int nDir);

	// ���� ����
	static double QuadraticEquation(double lfA, double lfB, double lfC, BOOL bPlusValue = TRUE);
	static int GetQuadraticEquationCount(double lfA, double lfB, double lfC);

	//���� ���� ����
	static int GetCircleLineintersection(TPoint ptCircleCenter, double radius, TPoint ptLine1, TPoint ptLine2, TPoint* _ptCross = NULL);
};

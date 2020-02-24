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

	// 기울기
	double lfAnc;
	// Y 관계수
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
			// 수직이 아닐 경우에 기울기로 구한다.
			lfAnc = lfDistanceY / lfDistanceX;
			b = ptStart.y - (lfAnc * ptStart.x);
		}
	}

	void Calculate(LineStruct& line)
	{
		bCross = TRUE;

		// 기울기가 같으면 평행선이므로 교차할 수 없다.
		if ((bVertical && line.bVertical)
			|| (bHorizon && line.bHorizon)
			|| lfAnc == line.lfAnc)
		{
			bCross = FALSE;
			return;
		}

		// 교차점 구하기
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

		// 교차점
		ptCross.x = x;
		ptCross.y = y;

		TRect rc;
		rc.SetRect(ptStart, ptEnd);
		rc.NormalizeRect();

		if (!rc.PtInRect(ptCross))
			bCross = FALSE;

		// 교차점이 교차하는 직선 영역안에 있는지 여부
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

	// 정해진 숫자를 2와 3으로 소인수분해 후 나머지를 가져온다.(임의 Grid 나누기 위해)
	static void SqrtEx(int nNumber, int& nValue, int& nMod);
	// 2개의 직선이 교차했는지 체크한다.
	static BOOL IsCrossLine(TPoint line1Pt1, TPoint line1Pt2, TPoint line2Pt1, TPoint line2Pt2);
	static double GetDistance(TPoint pt1, TPoint pt2);
	static double GetLineToPointDistance(TPoint linePt1, TPoint linePt2, TPoint pt);
	static double GetAngle(const TPoint& ptCenter, const TPoint& point1, const TPoint& point2, BOOL bNoMinusAngle = TRUE);
	static double GetAngle(const TPoint& point1, const TPoint& point2, BOOL bNoMinusAngle = TRUE);
	static BOOL IsCrossRect(TRect dragRect, TPoint ptStart, TPoint ptEnd);

	/************************************************************************/
	// 부동 소수점 Plus 연산
	// 부동 소수점을 더할 경우 Double 범위를 벗어나서 쓰레기 값이 입력될 수 있다.
	// 그래서 이 함수를 이용하여 정수부와 소수부를 String으로 변경하여 따로 연산하고,
	// 소수 3번째 자리까지 0이 나올 경우 0을 리턴시킨다.
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

	// 근의 공식
	static double QuadraticEquation(double lfA, double lfB, double lfC, BOOL bPlusValue = TRUE);
	static int GetQuadraticEquationCount(double lfA, double lfB, double lfC);

	//원과 직선 교점
	static int GetCircleLineintersection(TPoint ptCircleCenter, double radius, TPoint ptLine1, TPoint ptLine2, TPoint* _ptCross = NULL);
};

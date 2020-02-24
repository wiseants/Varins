#pragma once
#include "UtilityClass.h"

class CdblPoint;
typedef CdblPoint* LpDblPoint;

#define USE_CRAMERS_RULE

#define FMAX(a,b) ((a) > (b) ? (a) : (b))
#define FMIN(a,b) ((a) > (b) ? (b) : (a))
#define FABS(a) ((a) < 0.0f ? -(a) : (a))
#define OUT_OF_RANGE(a) ((a) < 0.0f || (a) > 1.f)

class UTILITYCLASS CIntersectionAlgorithm
{
public:
	CIntersectionAlgorithm(void);
	virtual ~CIntersectionAlgorithm(void);

	static
	BOOL Intersect_Lines(IN LpDblPoint _pL1First, IN LpDblPoint _pL1Second, 
						IN LpDblPoint _pL2First, IN LpDblPoint _pL2Second, 
						OUT LpDblPoint _pResult);

	static
	BOOL Intersect_LinesEx(IN LpDblPoint _pL1First, IN LpDblPoint _pL1Second, 
						IN LpDblPoint _pL2First, IN LpDblPoint _pL2Second, 
						OUT LpDblPoint _pResult);

	static
	BOOL Intersect_LineSegment(IN LpDblPoint _pL1First, IN LpDblPoint _pL1Second, 
							IN LpDblPoint _pL2First, IN LpDblPoint _pL2Second, 
							OUT LpDblPoint _pResult);

protected:
	static
	BOOL CheckLIntersection(CONST LpDblPoint _pL1First, CONST LpDblPoint _pL1Second, CONST LpDblPoint _pResult);


	static 
	BOOL IntersectLineSegments(const double A1x, const double A1y, const double A1z,
								const double A2x, const double A2y, const double A2z, 
								const double B1x, const double B1y, const double B1z,
								const double B2x, const double B2y, const double B2z,
								bool infinite_lines, double epsilon, double &PointOnSegAx,
								double &PointOnSegAy, double &PointOnSegAz, double &PointOnSegBx,
								double &PointOnSegBy, double &PointOnSegBz, double &NearestPointX,
								double &NearestPointY, double &NearestPointZ, double &NearestVectorX,
								double &NearestVectorY, double &NearestVectorZ);

	static 
	void FindNearestPointOnLineSegment(const double A1x, const double A1y, const double A1z,
										const double Lx, const double Ly, const double Lz,
										const double Bx, const double By, const double Bz,
										bool infinite_line, double epsilon_squared, double &NearestPointX,
										double &NearestPointY, double &NearestPointZ,
										double &parameter);

	static 
	void FindNearestPointOfParallelLineSegments(double A1x, double A1y, double A1z,
												double A2x, double A2y, double A2z,
												double Lax, double Lay, double Laz,
												double B1x, double B1y, double B1z,
												double B2x, double B2y, double B2z,
												double Lbx, double Lby, double Lbz,
												bool infinite_lines, double epsilon_squared,
												double &PointOnSegAx, double &PointOnSegAy, double &PointOnSegAz,
												double &PointOnSegBx, double &PointOnSegBy, double &PointOnSegBz);

	static 
	void AdjustNearestPoints(double A1x, double A1y, double A1z,
							double Lax, double Lay, double Laz,
							double B1x, double B1y, double B1z,
							double Lbx, double Lby, double Lbz,
							double epsilon_squared, double s, double t,
							double &PointOnSegAx, double &PointOnSegAy, double &PointOnSegAz,
							double &PointOnSegBx, double &PointOnSegBy, double &PointOnSegBz);

	//////////////////////////////////////////////////////////////////////////
	static
	BOOL lineIntersection(double Ax, double Ay,
						double Bx, double By,
						double Cx, double Cy,
						double Dx, double Dy,
						double *X, double *Y);

	static
	BOOL lineSegmentIntersection(double Ax, double Ay,
								double Bx, double By,
								double Cx, double Cy,
								double Dx, double Dy,
								double *X, double *Y);

protected:
	static double g_dEpsilon;
};

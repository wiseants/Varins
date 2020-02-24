#ifndef __RASTER_PRIVATE_STRUCTURES__
#define __RASTER_PRIVATE_STRUCTURES__


#include <list>
#pragma warning(push)
#pragma warning(disable:4018)
#include <vector>
#pragma warning(pop)

#define TINY	1.0e-20

struct ROISize
{
	long left;
	long top;
	long width;
	long height;
};

struct SCharPoint
{
	char m_x;
	char m_y;
};


struct SLongPoint
{
	long m_x;
	long m_y;
};

typedef std::list<SLongPoint> LPointList;
typedef LPointList::iterator LPointListIterator;

struct SDoublePoint
{
	double m_x;
	double m_y;
};

typedef std::list<SDoublePoint> DPointList;
typedef DPointList::iterator DPointListIterator;
typedef std::vector<SDoublePoint> DPointVector;
typedef DPointVector::iterator DPointVectorIterator;

struct SDouble3DPoint
{
	double m_x;
	double m_y;
	double m_z;
};


struct SLineSpec
{
	double m_theta;	// radian
	double m_cos;
	double m_sin;
	double m_rho;	// positive
};

typedef std::list<SLineSpec> LineSpecList;
typedef LineSpecList::iterator LineSpecListIterator;
typedef LineSpecList::const_iterator LineSpecListConstIterator;



struct SLongRange
{
	long m_start;
	long m_end;
};

typedef std::list<SLongRange> LRangeList;
typedef LRangeList::iterator LRangeListIterator;


struct _SBlobInfo	// Bottom-Up type.
{
	double m_ax;		// Area center
	double m_ay;		// Area center
	double m_gx;		// Gravity center
	double m_gy;		// Gravity center
	long m_area;		// Area
	long m_weight;		// Weight
	long m_density;		// Average Intensity
	long m_left;		// x-coord
	long m_right;		// x-coord
	long m_lower;		// y-coord
	long m_upper;		// y-coord
	long m_width;		// m_right - m_left
	long m_height;		// m_upper - m_lower
	bool m_IsValid;
};


struct SPatchVertexes
{	
	double m_x1;	// 화면 좌측 아래를 원점으로 하여
	double m_y1;	// 원점에서 가장 가까운 점을 기준점으로 시계 반대 방향으로 순서를 매긴다.
	double m_x2;
	double m_y2;
	double m_x3;
	double m_y3;
	double m_x4;
	double m_y4;
};

struct SNeighborPoint
{
	double m_x0;	// 현재 픽셀은 0번
	double m_y0;
	double m_x1;	// 현재 관심 픽셀로부터 우측에 있는 교점을 1번으로 하여
	double m_y1;	// 시계 반대 방향으로 순서을 매긴다.
	double m_x2;
	double m_y2;
	double m_x3;
	double m_y3;
	double m_x4;
	double m_y4;
};


__forceinline CArchive &operator>>(CArchive &ar, SCharPoint &dst){
	return ar >> dst.m_x >> dst.m_y;}
__forceinline CArchive &operator<<(CArchive &ar, SCharPoint &src){
	return ar << src.m_x << src.m_y;}
__forceinline CArchive &operator>>(CArchive &ar, SDoublePoint &dst){
	return ar >> dst.m_x >> dst.m_y;}
__forceinline CArchive &operator<<(CArchive &ar, SDoublePoint &src){
	return ar << src.m_x << src.m_y;}


#endif
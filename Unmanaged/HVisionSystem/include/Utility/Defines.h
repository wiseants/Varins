#include "dblRect.h"
#include "dblPoint.h"
#include "dblSize.h"
#include <atltypes.h>

#define DOUBLE_RECT

#ifdef DOUBLE_RECT
#define POS_UNIT	double
typedef CdblRect	TRect;
typedef CdblSize	TSize;
typedef CdblPoint	TPoint;
#define POS_CAST(x)		x
#define DEV_CAST(x)		long(x)
#define RECT_CAST(x)	x.GetCRect()
#define POINT_CAST(x)	x.GetCPoint()
#define SIZE_CAST(x)	x.GetCSize()
#else
#define POS_UNIT	long
typedef CRect TRect;
typedef CSize TSize;
typedef CPoint TPoint;
#define POS_CAST(x)		double(x)
#define DEV_CAST(x)		x
#define RECT_CAST(x)	x
#define POINT_CAST(x)	x
#define SIZE_CAST(x)	x
#endif

#pragma warning( disable : 4786)

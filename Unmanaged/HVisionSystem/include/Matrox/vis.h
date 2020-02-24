
#ifndef v_vis_h
#define v_vis_h

#if (__STDC__ || __cplusplus)
#define PROTO(x) x
#else
#define PROTO(x) ()
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifndef hipl_h
#include "hipl_format.h"
#endif

/*******************************************************************************
 *
 * Definition of Image Data Structure
 *
 */
typedef struct vis_buffer {
	short		width;		/* Number of columns.		*/
	short		height;		/* Number of rows.		*/
	short		x_offset;	/* Window offset from rat.	*/
	short		depth;		/* Pixel "FORMAT" (not depth)	*/
	unsigned short	flags;		/* misc image information	*/
	unsigned char	**rat;		/* -> Row/Address table.	*/

	struct vis_buffer *parent;	/* New field */
	short		y_offset;	/*    "      */
} vis_buffer;

typedef struct vis_stream {
	int		nframes;	/* number of image frames */
	vis_buffer	**image;	/* misc image information */
	int		width;
	int		height;
} vis_stream;


/*******************************************************************************
 *
 * Definition of Run and Blob Data Structure
 *
 */
typedef struct vrip_run
{
  struct vrip_run	*fwd;
  struct vrip_run	*bwd;
  short			x, y;
  short			length;
  int			weight;
} vrip_run;

typedef struct vblob_feature
{
  int			sx, sy, width, height;
  float			cx, cy;
  float			density;
} vblob_feature;

typedef struct vrip_blob
{
  struct vrip_blob	*next;
  struct vrip_blob	*prev;
  struct vrip_run	*head;
  struct vrip_run	*tail;
  int			area;
  int			color;
  char			isFg;
  short			x, y, w, h;
  struct vblob_feature	*feature;
} vrip_blob;


/* Definition of Image Format (vis_buffer->depth)
 */
#define	VIS_BINARY	1
#define	VIS_BYTE	8
#define	VIS_SHORT	16
#define	VIS_INT		32
#define	VIS_FLOAT	33
#define	VIS_COMPLEX	63
#define	VIS_DOUBLE	64
#define	VIS_RGB		65
#define	VIS_MAX_DEPTH	VIS_DOUBLE


/* Useful constant macros
 */

#ifndef NULL
#define NULL		0
#endif

#ifndef TRUE
#define TRUE		1
#endif

#ifndef FALSE
#define FALSE		0
#endif


/* Useful non-constant macros
*/
#ifndef FOREVER
#define FOREVER		for(;;)
#endif

#ifndef MIN
#define MIN(x,y)	(((x) < (y)) ? (x) : (y))
#endif

#ifndef MAX
#define MAX(x,y)	(((x) > (y)) ? (x) : (y))
#endif

#ifndef ABS
#define ABS(x)		(((x) >  0 ) ? (x) : -(x))
#endif

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif

#define CIA_BIT_VALUE(b) (1 << ((b) - 1))
#define CIA_NBIT_MASK(n) ((1 << (n)) - 1)
#define VIS_IS_BAD(b)	(!(b) || (b)->width < 0 || (b)->height < 0 ||  \
				 (b)->depth < 0 || (b)->depth  > VIS_MAX_DEPTH)
#define VIS_ARE_SAME_SIZE(a,b) ( (a)->width  == (b)->width && \
				 (a)->height == (b)->height)
#define VIS_ARE_SAME_DEPTH(a,b) ((a)->depth  == (b)->depth)



/* Useful typedefs
*/
#ifndef __cplusplus
typedef char	bool;
#endif




/*******************************************************************************
 *
 * Type declarations of the vis facility functions.
 *
 */
#define C_BUF_P		extern vis_buffer*
#define C_STR_P		extern vis_stream*
#define C_VOID		extern void

/*******************************************************************************
 * vfio.c : File I/O
 *
 *
 */
extern vis_buffer *vfio_read_vis (int fd, int argc, char **argv);
extern void	vfio_write_vis (int fd, vis_buffer *img);

C_BUF_P	vfio_read	PROTO((int fd, vis_buffer *img));
C_BUF_P	vfio_read_pgm	PROTO((int fd, vis_buffer *img));
C_BUF_P	vfio_read_bmp	PROTO((int fd, vis_buffer *img));
C_BUF_P	vfio_read_raw	PROTO((FILE *fp, vis_buffer *img));

C_VOID	vfio_write	PROTO((int fd, vis_buffer *src));
C_VOID	vfio_write_pgm	PROTO((int fd, vis_buffer *src));
C_VOID	vfio_write_bmp	PROTO((int fd, vis_buffer *src));
C_VOID	vfio_write_raw	PROTO((int fd, vis_buffer *src));


/*******************************************************************************
 * Image Stream related functions
 *
 *
 */
C_STR_P	vis_new_stream	  (int, vis_stream*);
C_STR_P	vis_create_stream (int, int, int, int, vis_stream*);
C_STR_P	vfio_read_stream  (int, vis_stream*);
C_VOID	vfio_write_stream (int, vis_stream*);

C_STR_P	vis_extract_stream(vis_stream*, vis_stream*, int, int, int);
C_STR_P	vis_average_stream(vis_stream*, vis_stream*, int, int, int);
C_STR_P	vis_merge_stream  (vis_stream*, vis_stream*, int, int, int, int);
C_STR_P	vis_stack_stream  (vis_stream*, vis_stream*, int, int, int);
C_BUF_P	vis_add_to_int	  (vis_buffer*, vis_buffer*);


/*******************************************************************************
 * vis_gen.c
 *
 *
 */
C_BUF_P	vis_create	PROTO(( int width, int height, int depth ));
C_BUF_P	vis_create_dib	PROTO(( int width, int height, int depth ));
C_VOID	vis_delete	PROTO(( vis_buffer *image ));
C_BUF_P	vis_set		PROTO((vis_buffer *src, int z));
C_BUF_P	vis_set_boundary PROTO((vis_buffer *src, int z, int bwid));
C_BUF_P	vis_window PROTO(( vis_buffer *src, vis_buffer *dst, int x0,
				      int y0, int width, int height ));
extern int vis_inverse	PROTO((vis_buffer *image));


/*******************************************************************************
 * vis_copy.c
 *
 *
 */
C_BUF_P	vis_copy	PROTO((vis_buffer *src, vis_buffer *dst));
C_BUF_P	vis_binary_copy	PROTO((vis_buffer *src, vis_buffer *dst, 
					  int bg, int fg));
C_BUF_P	vis_thresh_copy PROTO((vis_buffer *src, vis_buffer *dst, 
				  int th, int fg, int bg));
C_BUF_P	vis_mask_copy	PROTO((vis_buffer *src, vis_buffer *dst, 
			 vis_buffer *mask, int bg));


C_BUF_P	vis_histogram	PROTO((vis_buffer*, vis_buffer*));
extern int vis_th_ostu	PROTO((vis_buffer*, int));


/*******************************************************************************
 * vis_filter.c
 *
 *
 */
#define VIS_RANK_SE	(1 << 0)
#define VIS_RANK_S	(1 << 1)
#define VIS_RANK_SW	(1 << 2)
#define VIS_RANK_E	(1 << 3)
#define VIS_RANK_C	(1 << 4)
#define VIS_RANK_W	(1 << 5)
#define VIS_RANK_NE	(1 << 6)
#define VIS_RANK_N	(1 << 7)
#define VIS_RANK_NW	(1 << 8)
#define VIS_RANK_CROSS	VIS_RANK_C | VIS_RANK_N | VIS_RANK_E \
				   | VIS_RANK_S | VIS_RANK_W
#define VIS_RANK_ALL 511

C_BUF_P	vis_gauss	PROTO((vis_buffer *s, vis_buffer *d, int it));
C_BUF_P	vis_separable_median PROTO((vis_buffer *s, vis_buffer *d, int sz));
C_BUF_P	vis_rank	PROTO((vis_buffer *s, vis_buffer *d, int m, int r, int *ad));
C_BUF_P	vis_laplace	PROTO((vis_buffer *s, vis_buffer *d, int it));


/*******************************************************************************
 * vis_sample.c
 *
 *
 */
C_BUF_P	vis_sample	PROTO((vis_buffer *s, vis_buffer *dst, 
			  int xskip, int yskip, int xavg, int yavg));
C_BUF_P	vis_expand	PROTO((vis_buffer *s, vis_buffer *d, int xm, int ym));
C_BUF_P	vis_min		PROTO((vis_buffer *s1, vis_buffer *s2, vis_buffer *d));
C_BUF_P	vis_max		PROTO((vis_buffer *s1, vis_buffer *s2, vis_buffer *d));


/*******************************************************************************
 * vis_sample.c
 *
 *
 */
C_BUF_P	vis_sobel	PROTO((vis_buffer *s, vis_buffer *m, vis_buffer *a));


/*******************************************************************************
 * vis_trans.c
 *
 *
 */
C_BUF_P	vis_transform	PROTO((vis_buffer*, vis_buffer*, 
			  double, double, double,
			  double, double, double, int));
C_BUF_P	vis_rotate	PROTO((vis_buffer*, vis_buffer*,
			  double, double, double));
C_BUF_P	vis_rotate_coaxis PROTO((vis_buffer*, vis_buffer*, 
			  double, double, double, double, double));
C_BUF_P	vis_rotate_centered PROTO((vis_buffer*, vis_buffer*, double));
C_BUF_P	vis_scale	PROTO((vis_buffer*, vis_buffer*, 
			  double, double, double, double));
C_BUF_P	vis_transpose	PROTO((vis_buffer*, vis_buffer*));
C_BUF_P	vis_resize	PROTO((vis_buffer*, vis_buffer*, int, int, int));


extern vis_buffer *vpro_project(vis_buffer*, vis_buffer*, double);

extern short *vpro_weights PROTO((vis_buffer*, double, short*));
C_BUF_P	vis_disphist	PROTO((vis_buffer*, vis_buffer*, int));



#define LEN_RUN_OVERLAP(p,q)	( MIN ((p)->x+(p)->length, (q)->x+(q)->length) \
				- MAX ((p)->x, (q)->x) )
#define IS_RUN_OVERLAP(p,q)	((MIN ((p)->x+(p)->length, (q)->x+(q)->length) \
				 >MAX ((p)->x, (q)->x)) ? 1 : 0)

/////////////////////////////////////////////////////// by Cho

typedef enum {
    vmorph_op_union,	/* Union of element a and element b. */
    vmorph_op_dilate	/* Dilation of element a by element b. */
} vmorph_op;

typedef enum {
    vmorph_type_expr,
    vmorph_type_point,
    vmorph_type_image,
} vmorph_element_type;

typedef struct vmorph_element {
    /* Reserved for internal use. */
    unsigned int flags;
    unsigned int format;
    vmorph_element_type type;
    union {
	vis_buffer *image;

	struct {
	    int x, y;
        } point;

	struct {
	    struct vmorph_element *a;
	    struct vmorph_element *b;
	    vmorph_op op;
	} expr;
    } element;
} vmorph_element;

typedef struct vmorph_params {
    /* Foreground and background values for thresholding. */
    unsigned int fg;
    unsigned int bg;
} vmorph_params;


/* Morphological operations. */

extern vis_buffer *vmorph_dilate PROTO((vis_buffer *src, vis_buffer *dst, 
					vmorph_params *params, 
					vmorph_element *element));
extern vis_buffer *vmorph_erode PROTO((vis_buffer *src, vis_buffer *dst, 
				       vmorph_params *params, 
				       vmorph_element *element));
extern vis_buffer *vmorph_open PROTO((vis_buffer *src, vis_buffer *dst, 
				      vmorph_params *params, 
				      vmorph_element *element));
extern vis_buffer *vmorph_close PROTO((vis_buffer *src, vis_buffer *dst, 
				       vmorph_params *params, 
				       vmorph_element *element));
extern vis_buffer *vmorph_3x3_filter PROTO((vis_buffer *src, vis_buffer *dst, 
					    vmorph_params *params, char **mlist));
extern vis_buffer *vmorph_3x3 PROTO((vis_buffer *src, vis_buffer *dst, 
				     vmorph_params *params, char *lut));

/* Structuring elements. */

extern vmorph_element vmorph_sq3;
extern vmorph_element vmorph_dia3;
extern vmorph_element vmorph_disk5;
extern vmorph_element vmorph_ls3_0;
extern vmorph_element vmorph_ls3_45;
extern vmorph_element vmorph_ls3_90;
extern vmorph_element vmorph_ls3_135;

/* 3x3 lookup tables. */

extern char vmorph_lut_median[512];
extern char vmorph_lut_tl_thin[512];
extern char vmorph_lut_br_thin[512];
extern char vmorph_lut_disconnect[512];
extern char vmorph_lut_fgp[512];
extern char vmorph_lut_bgp[512];
extern char vmorph_lut_truncate[512];

///////////////////////////////////////////////////////////// by Cho

#ifdef __cplusplus
}
#endif

#endif /* !v_vis_h */



/*******************************************************************************
 *
 * HIPS Picture Header Format Standard
 *
 * Including
 *	- handles hips_format file I/O,
 *	- parse and initialize input arguments
 *	- alloc/free 1, 2-dimensional memory
 *	- time functions for performance checking (will be added)
 *
 */


#ifndef HIPL_H
#define HIPL_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#ifdef	WIN32
#include	<process.h>
#include	<fcntl.h>
#include	<io.h>
#include	<time.h>
#endif


/*******************************************************************************
 * perr Macro definition
 *
 */
#ifndef perr
#ifdef	WIN32
#include <windows.h>
#define	perr(str) MessageBox(GetFocus(),str,"ERROR:?.lib", MB_OK|MB_ICONSTOP) 
#else
#define	perr(str) do { fprintf(stderr,"ERROR: %s\n",str); exit(1); } while(0)
#endif
#endif


/*******************************************************************************
 * hips_format image head structure
 *
 */
struct header {
	char	*orig_name;	/* The originator of this sequence */
	char	*seq_name;	/* The name of this sequence */
	int	num_frame;	/* The number of frames in this sequence */
	char	*orig_date;	/* The date the sequence was originated */
	int	rows;		/* The number of rows in each image */
	int	cols;		/* The number of columns in each image */
	int	bits_per_pixel;	/* The number of significant bits per pixel */
	int	bit_packing;	/* Nonzero if bits were packed contiguously */
	int	pixel_format;	/* The format of each pixel, see below */
	char	*seq_history;	/* The sequence's history of transformations */
	char	*seq_desc;	/* Descriptive information */
};

/* Pixel Format Codes */
#define	PFBYTE	0		/* Bytes interpreted as integers */
#define PFSHORT	1		/* Short int's interpreted as integers */
#define PFINT	2		/* Int's */
#define	PFFLOAT	3		/* Float's */
#define	PFCOMPLEX 4		/* 2 Float's interpreted as (real,imaginary) */
#define PFASCII	5		/* Ascii representation, with linefeeds after each row */
#define PFQUAD1	11		/* quad-tree encoding */
#define PFBHIST	12		/* histogram of byte image */
#define PFSPAN	13		/* spanning tree format */
#define PLOT3D	24		/* plot-3d format */
#define PFAHC	400		/* adaptive hierarchical encoding */
#define PFOCT	401		/* oct-tree encoding */
#define	PFBT	402		/* binary tree encoding */
#define PFAHC3	403		/* 3-d adaptive hierarchical encoding */
#define PFBQ	404		/* binquad encoding */
#define PFRLED	500		/* run-length encoding */
#define PFRLEB	501		/* run-length encoding, line begins black */
#define PFRLEW	502		/* run-length encoding, line begins white */

/* Bit packing formats */
#define	MSBFIRST 1		/* bit packing - most significant bit first */
#define	LSBFIRST 2		/* bit packing - least significant bit first */
#define FBUFLIMIT 30000


#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * hips_format image handling function in "hipl.c"
 *
 */
    int	init_header	(struct header *hd,
			 char *onm,
			 char *snm,
			 int nfr,
			 char *odt,
			 int rw, int cl, int bpp,
			 int bpk, int pfmt,
			 char *desc);
    struct header *get_hips_header ();
    void read_hips_header (FILE *fp, struct header *hd);
    int	read_header	(struct header *hd);
    int	fread_header	(int fd, struct header *hd);
    int	update_header	(struct header *hd, int argc, char **argv);
    int	write_header	(struct header *hd);
    int	fwrite_header	(int fd, struct header *hd);
    char* desc_massage	(char *s);
    int	update_desc	(struct header *hd, char *txt);
    int	pread		(int fd, char *buf, int count);
    int	std_binary	();

/*******************************************************************************
 * memory allocation / free functions in ./memory/lgmem.c
 *
 */
    char*   allocMem	(int size);
    int	    freeMem	(char *array);
    char**  alloc2DMem	(int row, int col);
    int	    free2DMem	(char **image, int row, int col);

/*******************************************************************************
 * argument parsing functions in ./argument/readswitch.c
 *
 */
    char    *read_switch (int *argc,
			  char **argv,
			  char *name,
			  int args,
			  char *defreturn);
    int     read_bswitch (int *argc,
			  char **argv,
			  char *name);
    int     read_iswitch (int *argc,
			  char **argv,
			  char *name,
			  int defval);
    double  read_dswitch (int *argc,
			  char **argv,
			  char *name,
			  double defval);
    int     get_line     (FILE *fp, char *str);

/*******************************************************************************
 * functions in ./time/lgtime.c
 *
 */
    int     init_time();
    int     check_time(int i);
    int     prttime_elapsed(char *msg, int before, int after);
    int     prttime_current(char *msg);
    int     prttime_point(char *msg, int i);

#ifdef __cplusplus
}
#endif

#endif /* HIPL_H */


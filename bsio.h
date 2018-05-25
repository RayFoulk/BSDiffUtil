//------------------------------------------------------------------------+
#include <bzlib.h>   // BZFILE

//------------------------------------------------------------------------+
typedef struct
{
    // TODO: add other I/O options.  hex dump,
	// enable/disable patch output, dump metrics,
	// add LZ compression.. etc...
	
    BZFILE *pfbz2;
    int bz2err;
    int readcount;

    unsigned long refcount;
}
bsio_t;

//------------------------------------------------------------------------+
void bsio_Read(bsio_t * bsio, void * b, void * buf, int len);
void bsio_ReadOpen(bsio_t * bsio, FILE * f, int verbosity, int small,
		void * unused, int nUnused);
void bsio_ReadClose(bsio_t * bsio, void * b);

//------------------------------------------------------------------------+
void bsio_Write(bsio_t * bsio, void* b, void * buf, int len);
void bsio_WriteOpen(bsio_t * bsio, FILE * f,int blockSize100k,
		int verbosity, int workFactor);
void bsio_WriteClose(bsio_t * bsio, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out);

//------------------------------------------------------------------------+
#include <bzlib.h>   // BZFILE

//------------------------------------------------------------------------+
typedef struct
{
    // TODO: add other I/O options.  hex dump, LZ compression..
	
    BZFILE *pfbz2;
    int bz2err;
    int readcount;

    unsigned long refcount;
}
bsio_t;

//------------------------------------------------------------------------+
void bsio_Read(void * b, void * buf, int len);
void * bsio_ReadOpen(int * bzerror, FILE * f, int verbosity, int small,
		void * unused, int nUnused);
void bsio_ReadClose(int * bzerror, void * b);

//------------------------------------------------------------------------+
void bsio_Write(int * bzerror, void* b, void * buf, int len);
void * bsio_WriteOpen(int * bzerror, FILE * f,int blockSize100k,
		int verbosity, int workFactor);
void bsio_WriteClose(int * bzerror, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out);

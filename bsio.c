//------------------------------------------------------------------------+
#include <bzlib.h>
#include <err.h>

#include "bsio.h"
#include "utils.h"

//------------------------------------------------------------------------+
// module data
static bsio_t bsio = {
		NULL,
		0,
		0,
		0
};

//------------------------------------------------------------------------+
void bsio_Read(void * b, void * buf, int len)
{
	bsio.readcount = BZ2_bzRead(&bsio.bz2err, b, buf, len);

    if ((bsio.readcount < len) ||
    		((bsio.bz2err != BZ_OK) && (bsio.bz2err != BZ_STREAM_END)))
	{
		errx(1, "%s: Short read, corrupt patch\n", __FUNCTION__);
	}
}

//------------------------------------------------------------------------+
void * bsio_ReadOpen(int * bzerror, FILE * f, int verbosity, int small,
		void * unused, int nUnused)
{
	return BZ2_bzReadOpen(bzerror, f, verbosity, small, unused, nUnused);
}

//------------------------------------------------------------------------+
void bsio_ReadClose(int * bzerror, void * b)
{
	BZ2_bzReadClose(bzerror, b);
}

//------------------------------------------------------------------------+
void bsio_Write(int * bzerror, void * b, void * buf, int len)
{
	printf("%s: refcount: %lu\n", __FUNCTION__, bsio.refcount);
	hexdump(buf, len);
	bsio.refcount++;
	printf("\n");

	BZ2_bzWrite(bzerror, b, buf, len);
    if (bzerror != BZ_OK)
    {
        errx(1, "bsio_Write, bz2err = %d", bz2err);
    }

}

//------------------------------------------------------------------------+
void* bsio_WriteOpen(int * bzerror, FILE * f,int blockSize100k,
		int verbosity, int workFactor)
{
	return BZ2_bzWriteOpen(bzerror, f, blockSize100k, verbosity,
			workFactor);
}

//------------------------------------------------------------------------+
void bsio_WriteClose(int * bzerror, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out)
{
	BZ2_bzWriteClose(bzerror, b, abandon, nbytes_in, nbytes_out);
    if (bzerror != BZ_OK)
    {
        errx(1, "bsio_WriteClose, bz2err = %d", bz2err);
    }
}

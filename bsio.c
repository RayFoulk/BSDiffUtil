//------------------------------------------------------------------------+
#include <bzlib.h>
#include <err.h>

#include "bsio->h"
#include "utils.h"

//------------------------------------------------------------------------+
void bsio_Read(bsio_t * bsio, void * b, void * buf, int len)
{
	bsio->readcount = BZ2_bzRead(&bsio->bz2err, b, buf, len);

    if ((bsio->readcount < len) ||
    		((bsio->bz2err != BZ_OK) && (bsio->bz2err != BZ_STREAM_END)))
	{
		errx(1, "%s: Short read, corrupt patch\n", __FUNCTION__);
	}
}

//------------------------------------------------------------------------+
void * bsio_ReadOpen(bsio_t * bsio, FILE * f, int verbosity, int small,
		void * unused, int nUnused)
{
	memset(bsio, 0, sizeof(bsio_t));

	bsio->pfbz2 = BZ2_bzReadOpen(&bsio->bz2err, f, verbosity, small, unused, nUnused);
	if (bsio->pfbz2 == NULL)
	{
		errx(XXXXXXXXXXXXXXXXXXXXXXXXXXXXX);
	}
}

//------------------------------------------------------------------------+
void bsio_ReadClose(bsio_t * bsio, void * b)
{
	BZ2_bzReadClose(&bsio->bz2err, b);
}

//------------------------------------------------------------------------+
void bsio_Write(bsio_t * bsio, void * b, void * buf, int len)
{
	printf("%s: refcount: %lu\n", __FUNCTION__, bsio->refcount);
	hexdump(buf, len);
	bsio->refcount++;
	printf("\n");

	BZ2_bzWrite(&bsio->bz2err, b, buf, len);
    if (&bsio->bz2err != BZ_OK)
    {
        errx(1, "bsio_Write, bz2err = %d", bz2err);
    }

}

//------------------------------------------------------------------------+
void* bsio_WriteOpen(bsio_t * bsio, FILE * f,int blockSize100k,
		int verbosity, int workFactor)
{
	memset(bsio, 0, sizeof(bsio_t));

	return BZ2_bzWriteOpen(&bsio->bz2err, f, blockSize100k, verbosity,
			workFactor);
}

//------------------------------------------------------------------------+
void bsio_WriteClose(bsio_t * bsio, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out)
{
	BZ2_bzWriteClose(&bsio->bz2err, b, abandon, nbytes_in, nbytes_out);
    if (&bsio->bz2err != BZ_OK)
    {
        errx(1, "bsio_WriteClose, bz2err = %d", bz2err);
    }
}

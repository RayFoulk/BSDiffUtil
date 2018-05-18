//------------------------------------------------------------------------+
// grep -hi BZ2_ *.c | sed -e 's/^.*\(BZ2_.*(\).*$/\1/p' | grep -v errx | sort | uniq
// BZ2_bzRead(
// BZ2_bzReadClose(
// BZ2_bzReadOpen(
// BZ2_bzWrite(
// BZ2_bzWriteClose(
// BZ2_bzWriteOpen(

//------------------------------------------------------------------------+
int bsio_Read(int * bzerror, void * b, void * buf, int len);
void * bsio_ReadOpen(int * bzerror, FILE * f, int verbosity, int small,
		void * unused, int nUnused);
void bsio_ReadClose(int * bzerror, void * b);

//------------------------------------------------------------------------+
void bsio_Write(int * bzerror, void* b, void * buf, int len);
void* bsio_WriteOpen(int * bzerror, FILE * f,int blockSize100k,
		int verbosity, int workFactor);
void bsio_WriteClose(int * bzerror, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out);

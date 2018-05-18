
// grep -hi BZ2_ *.c | sed -e 's/^.*\(BZ2_.*(\).*$/\1/p' | grep -v errx | sort | uniq
// BZ2_bzRead(
// BZ2_bzReadClose(
// BZ2_bzReadOpen(
// BZ2_bzWrite(
// BZ2_bzWriteClose(
// BZ2_bzWriteOpen(



int BZ2_bzRead(int * bzerror, void * b, void * buf, int len);
void * BZ2_bzReadOpen(int * bzerror, FILE * f, int verbosity,
    int small, void * unused, int nUnused);
void BZ2_bzReadClose(int * bzerror, void * b);

void BZ2_bzWrite(int * bzerror, void* b, void * buf, int len);
void* BZ2_bzWriteOpen(int * bzerror, FILE * f,int blockSize100k,
    int verbosity, int workFactor);
void BZ2_bzWriteClose (
      int*          bzerror,
      void*       b,
      int           abandon,
      unsigned int* nbytes_in,
      unsigned int* nbytes_out
   );

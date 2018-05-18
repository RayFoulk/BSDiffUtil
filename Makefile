CFLAGS		+=	-O3 -lbz2 -Wall

PREFIX		?=	/usr/local
INSTALL_PROGRAM	?=	${INSTALL} -c -s -m 555
INSTALL_MAN	?=	${INSTALL} -c -m 444

all:		bsdiff bspatch
bsdiff:		bsdiff.c
bspatch:	bspatch.c

test:
	./bsdiff tests/bin1 tests/bin2 tests/bin.patch

clean:
	rm -f bsdiff bspatch tests/bin.patch

install:
	${INSTALL_PROGRAM} bsdiff bspatch ${PREFIX}/bin
#.ifndef WITHOUT_MAN
#	${INSTALL_MAN} bsdiff.1 bspatch.1 ${PREFIX}/man/man1
#.endif


CC=gcc

# para debug
CFLAGS=-O0 -g  -Wall -Werror

#para produção
#CFLAGS=-O2 -g  -Wall -Werror

#diretório com biblioteca
LPATH=.

all: libversionfs.so vfs_test


versionfs.o:
	$(CC) $(CFLAGS) -fpic versionfs.c -c

libversionfs.so: versionfs.o
	$(CC) $(CFLAGS) -shared -o libversionfs.so versionfs.o

vfs_test: vfs_test.c libversionfs.so
	$(CC) $(CFLAGS) -L$(LPATH) vfs_test.c -o vfs_test -lversionfs

.PHONY: clean

clean:
	rm -rf *~ *.o *.so *.dSYM vfs_test
	clear
	clear

test: vfs_test
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(LPATH) ./vfs_test
	
my: clean all test

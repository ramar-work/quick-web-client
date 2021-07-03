
CC = clang
IFLAGS = -Ivendor
CLANGFLAGS = -Wall -Werror -Wno-unused -Wno-format-security $(IFLAGS)
CFLAGS = $(CLANGFLAGS)


main: web.o vendor/zwalker.o
	$(CC) $(CFLAGS) -lgnutls -o web web.o vendor/zwalker.o webtest.c

clean:
	-rm -f *.o

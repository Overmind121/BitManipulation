CC = clang
CFlags = -Wall -Wpedantic -Werror -Wextra
LFLAGS = -lm

all: manipulate

manipulate:  manipulate.o bitvector.o
	$(CC) -o manipulate manipulate.o bitvector.o $(LFLAGS)

manipulate.o: bitvector.h
	$(CC) $(CFLAGS) -c manipulate.c 

bitvector.o: bitvector.c
	$(CC) $(CFLAGS) -c bitvector.c

clean:
	rm -f manipulate *.o

format:
	clang-format -i -style=file *.[ch]




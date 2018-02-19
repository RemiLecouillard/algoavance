CFLAGS = -Wall -Wextra -pedantic-errors
CC = gcc
LDFLAGS =
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)

.PHONY: clean all distclean

all: testABR.out

testABR.out: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

.o: .c

clean :
	rm -f *.o *~

distclean : clean
	rm *.out

doc :
	doxygen Doxyfile

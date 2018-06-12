CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
LDFLAGS += -lmpi
CC = mpicc
.PHONY: all clean

all: codebreaker

codebreaker: codebreaker.o mpi/mpi-layer.o distribution/distribution.a
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	make -C distribution clean
	make -C cracker clean
	make -C mpi clean
	rm -f *.o

distclean: clean
	rm -f codebreaker

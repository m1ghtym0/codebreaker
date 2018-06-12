CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
LIBS += -lmpi -lssl -lcrypto
CC = mpicc
.PHONY: all clean

all: codebreaker

codebreaker: codebreaker.o mpi/mpi-layer.o distribution/distribution.o cracker/cracker.a input/input.a
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	make -C distribution clean
	make -C cracker clean
	make -C mpi clean
	make -C input clean
	rm -f *.o
	rm -rf *.gch

distclean: clean
	rm -f codebreaker

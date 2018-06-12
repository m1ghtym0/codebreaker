CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
LIBS += -lmpi
#STATIC_LIBS += -lssl -lcrypto
# This is an ugly trick so we don't have to write the annoying module file
STATIC_LIBS += /usr/lib/x86_64-linux-gnu/libcrypto.a
CC = mpicc
.PHONY: all clean

all: codebreaker

#codebreaker: codebreaker.o mpi/mpi-layer.o distribution/distribution.a cracker/cracker.a input/input.a /usr/lib/x86_64-linux-gnu/libcrypto.a
codebreaker: codebreaker.o mpi/mpi-layer.o distribution/distribution.a cracker/cracker.a input/input.a
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) $(STATIC_LIBS)

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

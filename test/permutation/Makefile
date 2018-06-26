CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s

.PHONY: all clean

all: permutation-test

permutation-test: permutation-test.o ../../src/permutation/permutation.a ../../src/input/input.a
	$(CC) -o $@ $^ $(LIBS)


%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f permutation-test result *.o


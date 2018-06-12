CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s

.PHONY: all clean

all: distribution-test

distribution-test: distribution-test.o ../../src/distribution/distribution.a ../../src/input/input.a
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f distribution-test result *.o

CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
.PHONY: all clean

all: input distribution.a

input:
	make -C input

distribution.a: distribution.o input/read_file.o input/vector.o
	ar cr $@ $^

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	make -C input clean
	rm -f *.o

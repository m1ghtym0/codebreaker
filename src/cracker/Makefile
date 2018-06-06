CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
SRC = cracker.c md5.c sha256.c sha512.c
.PHONY: all clean

all: cracker

cracker: $(SRC)
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) $^

clean:
	rm -f *.o

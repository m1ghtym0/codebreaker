CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
SRC = cracker.c md5.c sha256.c sha512.c
OBJ = $(SRC:.c=.o)
.PHONY: all clean

all: cracker.a

cracker.a: $(OBJ)
	ar cr $@ $(OBJ)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) $^

clean:
	rm -f *.o *.a

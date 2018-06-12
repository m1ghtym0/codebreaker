CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
LIBS += -lssl -lcrypto

.PHONY: all clean

all: md5-test sha256-test sha512-test cracker-test cracker-test2

md5-test: md5-test.o ../../src/cracker/md5.o ../../src/cracker/md5.h
	$(CC) -o $@ $^ $(LIBS)

sha256-test: sha256-test.o ../../src/cracker/sha256.o ../../src/cracker/sha256.h
	$(CC) -o $@ $^ $(LIBS)

sha512-test: sha512-test.o ../../src/cracker/sha512.o ../../src/cracker/sha512.h
	$(CC) -o $@ $^ $(LIBS)

cracker-test: cracker-test.o ../../src/cracker/cracker.a ../../src/input/input.a ../../src/cracker/cracker.h
	$(CC) -o $@ $^ $(LIBS)

cracker-test2: cracker-test2.o ../../src/cracker/cracker.a ../../src/input/input.a ../../src/cracker/cracker.h
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<	$(LIBS)

clean:
	rm -f cracker-test2 cracker-test md5-test sha256-test sha512-test *.o

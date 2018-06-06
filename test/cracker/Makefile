CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
LDFLAGS += 
LIBS += -lssl -lcrypto

.PHONY: all clean

all: md5-test

md5-test: md5-test.o ../../src/cracker/md5.o ../../src/cracker/md5.h
	$(CC) -o $@ $^ $(LIBS)
	
%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<	$(LIBS)

clean:
	rm -f md5-test *.o

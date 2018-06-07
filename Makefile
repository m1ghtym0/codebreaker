.PHONY: build clean test

build: main mpi cracker

main:
	$(MAKE) -C src

mpi:
	$(MAKE) -C src/mpi

cracker:
	$(MAKE) -C src/cracker

test: build
	$(MAKE) -C test
	
clean:
	$(MAKE) -C src clean
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean

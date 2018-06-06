.PHONY: build clean test

build: mpi cracker

mpi:
	$(MAKE) -C src/mpi
	
cracker:
	$(MAKE) -C src/cracker

test:
	$(MAKE) -C test
	
clean:
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean

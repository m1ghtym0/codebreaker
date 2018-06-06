.PHONY: build clean

build: main mpi cracker

main:
	$(MAKE) -C src

mpi:
	$(MAKE) -C src/mpi

cracker:
	$(MAKE) -C src/cracker

clean:
	$(MAKE) -C src clean
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean

.PHONY: build clean test

build: main mpi cracker permutation

main:
	$(MAKE) -C src

mpi:
	$(MAKE) -C src/mpi

cracker:
	$(MAKE) -C src/cracker

permutation:
	$(MAKE) -C src/permutation
	$(MAKE) -C src/permutation/input


test: build
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean
	$(MAKE) -C src/permutation clean
	$(MAKE) -C src/permutation/input clean

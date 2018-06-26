.PHONY: build clean test

build: codebreaker

codebreaker: mpi input cracker distribution permutation
	$(MAKE) -C src

mpi:
	$(MAKE) -C src/mpi

cracker:
	$(MAKE) -C src/cracker

distribution:
	$(MAKE) -C src/distribution

input:
	$(MAKE) -C src/input

permutation:
	$(MAKE) -C src/permutation

test: build
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean
	$(MAKE) -C src/distribution clean
	$(MAKE) -C src/input clean
	$(MAKE) -C src/permutation clean

.PHONY: build clean cracker run

all: build run

build: cracker distribution permutation
run: build

cracker:
	$(MAKE) -C cracker
	$(MAKE) -C distribution
	$(MAKE) -C permutation
clean:
	#$(MAKE) -C mpi clean
	$(MAKE) -C cracker clean
	$(MAKE) -C distribution clean
	$(MAKE) -C permutation clean
run:
	./run_tests.sh

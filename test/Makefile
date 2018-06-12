.PHONY: build clean cracker run

all: build run

build: cracker distribution
run: build

cracker:
	$(MAKE) -C cracker
	$(MAKE) -C distribution

clean:
	#$(MAKE) -C mpi clean
	$(MAKE) -C cracker clean
	$(MAKE) -C distribution clean

run:
	./run_tests.sh

.PHONY: build clean cracker run

all: build run

build: cracker
run: build

cracker:
	$(MAKE) -C cracker

clean:
	#$(MAKE) -C mpi clean
	$(MAKE) -C cracker clean

run:
	./run_tests.sh

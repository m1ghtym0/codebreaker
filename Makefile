.PHONY: build clean

build: mpi cracker

mpi:
	$(MAKE) -C src/mpi
    
cracker:
	$(MAKE) -C src/cracker

clean:
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/cracker clean

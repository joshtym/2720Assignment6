.PHONY  : all
all:
	$(MAKE) -C src
	$(MAKE) -C simulationDir

.PHONY : testcases
testcases:
	$(MAKE) -C src
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean
	$(MAKE) -C simulationDir clean
	rm simulationDir/interface
	rm include/*~

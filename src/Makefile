## right now there is no production code apart from the libraries...
## Call recursively on the libraries

CC = g++
LIBS = -lcppunit -ldl
THEOBJECTS = 
HEADERDIRS = ../include
OBJDIR = ../obj
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS)) 

.PHONY: all
all:
	$(MAKE) -C paystation
# generate the production code by linking here ...

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~
	$(MAKE) -C paystation clean

## generate the prerequistes and append to the desired file 
#.prereq : $(THEOBJECTS:.o=.cc) $(wildcard $(HEADERDIRS)/*.h) Makefile
#	rm -f .prereq 
#	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cc) >> ./.prereq
## include the generated prerequisite file 
#include .prereq

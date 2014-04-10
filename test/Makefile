## the test directory shoul dreally only contain one .cc file (the main.cc)
## so I decided to keep everything here

CC = g++
LN = g++
LIBS = -lcppunit -ldl -lpaystation
PRODUCTIONDIR = ../obj
THEOBJECTS = main.o
HEADERDIRS = ../include
OBJDIR = .
CCFLAGS = -I $(HEADERDIRS)
LNFLAGS = -L$(PRODUCTIONDIR)/paystation/
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))



$(OBJDIR)/testcases: $(OBJS) $(PRODUCTIONDIR)/paystation/libpaystation.a
	$(LN) $(LNFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ 

## generate the prerequistes and append to the desired file 
.prereq : $(THEOBJECTS:.o=.cpp) $(wildcard $(HEADERDIRS)/*.h) $(wildcard *h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cpp) >> ./.prereq
## include the generated prerequisite file 
include .prereq

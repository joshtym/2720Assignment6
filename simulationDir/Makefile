CC = g++
LN = g++
LIBS = -lcppunit -ldl -lpaystation -lncurses -ltinfo
PRODUCTIONDIR = ../obj
THEOBJECTS = main.o
HEADERDIRS = ../include
OBJDIR = .
CCFLAGS = -I $(HEADERDIRS) -I /usr/include/
LNFLAGS = -L$(PRODUCTIONDIR)/paystation/
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))


$(OBJDIR)/interface: $(OBJS) $(PRODUCTIONDIR)/paystation/libpaystation.a
	$(LN) $(LNFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ 


.prereq : $(THEOBJECTS:.o=.cpp) $(wildcard $(HEADERDIRS)/*.h) $(wildcard *h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cpp) >> ./.prereq

include .prereq

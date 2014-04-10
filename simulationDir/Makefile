CC = g++
LN = g++
LIBS = -lcppunit -ldl -lpaystation -lncurses -ltinfo
OBJSDIR = ../obj
THEOBJECTS = main.o
INCLUDEDIR = ../include
OBJDIR = .
CCFLAGS = -I $(INCLUDEDIR) -I /usr/include/
LNFLAGS = -L$(OBJSDIR)/paystation/
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))


$(OBJDIR)/interface: $(OBJS) $(OBJSDIR)/paystation/libpaystation.a
	$(LN) $(LNFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~ 


.prereq : $(THEOBJECTS:.o=.cpp) $(wildcard $(INCLUDEDIR)/*.h) $(wildcard *h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cpp) >> ./.prereq

include .prereq

CC = g++
AR = ar
ARFLAGS = -cr 
LIBS = -lcppunit -ldl
THEOBJECTS = PayStationImpl.o StandardReceipt.o LinearRateStrategy.o ProgressiveRateStrategy.o AlternatingRateStrategy.o ClockBasedDecisionStrategy.o DisplayStrategy.o
HEADERDIRS = ../../include
OBJDIR = ../../obj/paystation
CCFLAGS = -I $(HEADERDIRS)
OBJS = $(addprefix $(OBJDIR)/, $(THEOBJECTS))

$(OBJDIR)/libpaystation.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -f $(OBJDIR)/*.o *~

## generate the prerequistes and append to the desired file 
.prereq : $(THEOBJECTS:.o=.cpp) $(wildcard $(HEADERDIRS)/*.h) Makefile
	rm -f .prereq 
	$(CC) $(CCFLAGS) -MM $(THEOBJECTS:.o=.cpp) >> ./.prereq
## include the generated prerequisite file 
include .prereq

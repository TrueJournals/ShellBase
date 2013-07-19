#####################################################################
#  User configurable
#####################################################################
# Installation prefix, excluding trailing /.  Files will be copied
#  to this directory on make install, including $(PREFIX)lib/,
#  $(PREFIX)include/, etc.
PREFIX := /usr

#####################################################################
#  Probably shouldn't touch unless you know what you're doing
#####################################################################
CXX := g++
CP := cp
RM := rm -rf
MKDIR := mkdir -p
DOXYGEN := doxygen
CXXFLAGS := -fPIC -Wall -std=c++11
LIBS := 
INCLUDES := -I./inc/
SRCS := ./src/ShellBase.cpp

OBJS := $(SRCS:%.cpp=%.o)
		
.PHONY: all install depend clean

all: depend libshellbase.so

install: all
	$(CP) libshellbase.so $(PREFIX)/lib/
	$(MKDIR) $(PREFIX)/include/libshellbase/
	$(CP) -r ./inc/* $(PREFIX)/include/libshellbase/
	
clean:
	$(RM) libshellbase.so $(OBJS) .depend

libshellbase.so: $(OBJS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c -o $@ $<

depend: .depend

.depend: $(SRCS)
	@$(RM) ./.depend
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MM $^ > ./.depend;

-include .depend

# Pending documentation
#doc:
#	$(DOXYGEN) ./doc/Doxyfile
#
#docclean:
#	$(RM) ./doc/html ./doc/latex

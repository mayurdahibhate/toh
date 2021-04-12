CPPC=g++
CPPFLAGS=-o

all: toh

toh: toh.hpp toh.cpp
	$(CPPC) $(CPPFLAGS) toh toh.cpp 

install:
	cp toh /usr/bin/

clean:
	rm -f toh

distclean: clean

uninstall: 
	rm /usr/bin/toh

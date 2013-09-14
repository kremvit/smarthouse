
# Main makefile

include makefile.inc

: all

all: libcore tests

libcore: force_look
	$(ECHO) Building libcore...
	cd ./libcore; $(MAKE) all

tests: libcore
	$(ECHO) Building tests...

clean:
	$(ECHO) Cleaning...
	cd ./libcore; $(MAKE) clean

force_look:
	true

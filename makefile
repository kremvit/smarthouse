
# Main makefile

include makefile.inc

: all

all: libcore librpcserver smarthouse

libcore: force_look
	$(ECHO) Building libcore...
	cd ./libcore; $(MAKE) all

librpcserver: force_look
	cd ./librpcserver; $(MAKE) all

smarthouse: force_look
	cd ./smarthouse; $(MAKE) all

tests: libcore
	$(ECHO) Building tests...

clean:
	$(ECHO) Cleaning...
	cd ./libcore; $(MAKE) clean
	cd ./librpcserver; $(MAKE) clean
	cd ./smarthouse; $(MAKE) clean

force_look:
	true


#makefile

INCS=	-I../librpcserver/include \
		-I../libcore/include

: all

all:
	g++ -g -O0 src/main.cpp $(INCS) -o smarthouse -L../libs -lrpcserver -ljsonrpc -ljson -lcore 
	cp smarthouse ../bin

clean:
	rm -rf smarthouse
	rm -rf ../bin/smarthouse

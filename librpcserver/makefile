
# makefile

INCS=	-I./include \
		-I../smarhouse/include \
		-I../3rd-party/jsonrpc-cpp-0.4/src \
		-I../libcore/include \

all:
	g++ -c -fPIC -g $(INCS) src/CRpc.cpp -o CRpc.o
	g++ -c -fPIC -g $(INCS) src/RpcMap.cpp -o RpcMap.o
	g++ -c -fPIC -g $(INCS) src/CRpcServer.cpp -o CRpcServer.o
	g++ -c -fPIC -g $(INCS) src/CAppFacade.cpp -o CAppFacade.o
	g++ -shared -Wl,-soname,librpcserver.so.1 -olibrpcserver.so.1.0.1 RpcMap.o CRpc.o CRpcServer.o CAppFacade.o -L../libs -ljsonrpc
	cp librpcserver.so.1.0.1 ../libs/librpcserver.so

clean:
	rm -rf *.o librpcserver.so*
	rm -rf ../libs/librpcserver.so
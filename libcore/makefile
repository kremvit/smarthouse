all:
	g++ -c -fPIC -g -I./include src/CDevice.cpp -o CDevice.o
	g++ -c -fPIC -g -I./include src/CNetworkDevice.cpp -o CNetworkDevice.o
	g++ -c -fPIC -g -I./include src/CRpc.cpp -o CRpc.o
	g++ -c -fPIC -g -I./include -I./3rd-party/jsonrpc-cpp-0.4/src src/RpcMap.cpp -o RpcMap.o
	g++ -shared -Wl,-soname,libcore.so.1 -o libcore.so.1.0.1 CDevice.o CNetworkDevice.o CRpc.o RpcMap.o -L./lib -ljson -ljsonrpc
 
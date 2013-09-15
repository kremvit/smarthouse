all:
	g++ -c -fPIC -g -I./include src/CDevice.cpp -o CDevice.o
	g++ -c -fPIC -g -I./include src/CNetworkDevice.cpp -o CNetworkDevice.o
	g++ -c -fPIC -g -I./include src/CDeviceList.cpp -o CDeviceList.o
	g++ -shared -Wl,-soname,libcore.so.1 -o libcore.so.1.0.1 CDevice.o CNetworkDevice.o CDeviceList.o -L../libs -ljsonrpc
	cp libcore.so.1.0.1 ../libs/libcore.so
	if [ ! -e ../libs/libcore.so.1 ]; then \
	    ln -s libcore.so ../libs/libcore.so.1; \
	fi;

clean:
	rm -rf *.o libcore.so.*
	rm -rf ../libs/libcore.so ../libs/libcore.so.1
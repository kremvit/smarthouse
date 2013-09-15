/*
 * main.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 *
 *  The main application which starts jsonrpc server and initializes all systems
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "CRpcServer.h"
#include "CAppFacade.h"

int main(int argc, char * argv[]) {
	int status = -1;
	do {
		CDeviceList * p_device_list = new CDeviceList();
		if (NULL == p_device_list) {
			status = -1;
			break;
		}

		CAppFacade * p_facade = CAppFacade::Create();
		if (NULL == p_facade) {
			status = -1;
			break;
		}

		status = p_facade->Init(p_device_list);
		if (status != 0) {
			break;
		}

		CRpcServer * p_server = new CRpcServer();
		if (NULL == p_server) {
			status = -1;
			break;
		}

		status = p_server->Init(p_facade);

		status = p_server->Run();
		if (status != 0) {
			break;
		}

		std::cout << "waiting on cin.get" << std::endl;
		std::cin.get();

	} while (0);

	if (status != 0) {
		std::cout << "Failure" << std::endl;
	}

	return status;
}

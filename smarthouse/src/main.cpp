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
	int line_no = 0;
	CDeviceList * p_device_list = NULL;
	CAppFacade * p_facade = NULL;
	CRpcServer * p_server = NULL;

	do {
		p_device_list = new CDeviceList();
		if (NULL == p_device_list) {
			status = -1;
			line_no = __LINE__;
			break;
		}

		status = p_device_list->Build();
		if (status != 0) {
			line_no = __LINE__;
			break;
		}

		p_facade = CAppFacade::Create();
		if (NULL == p_facade) {
			status = -1;
			line_no = __LINE__;
			break;
		}

		status = p_facade->Init(p_device_list);
		if (status != 0) {
			line_no = __LINE__;
			break;
		}

		p_server = new CRpcServer();
		if (NULL == p_server) {
			status = -1;
			line_no = __LINE__;
			break;
		}

		status = p_server->Init(p_facade);
		if (status != 0) {
			line_no = __LINE__;
			break;
		}

		status = p_server->Run();
		if (status != 0) {
			line_no = __LINE__;
			break;
		}

		std::cout << "waiting on cin.get" << std::endl;
		std::cin.get();

	} while (0);

	if (p_server) {
		p_server->Stop();
		p_server->Deinit();
		delete p_server;
		p_server = NULL;
	}

	if (p_facade) {
		p_facade->Deinit();
		delete p_facade;
		p_facade = NULL;
	}

	if (p_device_list) {
		delete p_device_list;
		p_device_list = NULL;
	}

	if (status != 0) {
		std::cout << "Failure in line: " << line_no << std::endl;
	}

	return status;
}

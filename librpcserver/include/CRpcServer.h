/*
 * CRpcServer.h
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#ifndef CRPC_SERVER_H_
#define CRPC_SERVER_H_

#include <pthread.h>

#include "CAppFacade.h"

class CRpcServer {

	pthread_t m_server_thread;

	CAppFacade * m_p_facade;

public:

	CRpcServer();

	int Init(CAppFacade * p_facade);

	int Run();
};

#endif /* CRPC_SERVER_H_ */

/*
 * CRpcServer.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#include "CRpcServer.h"

#include <cstdio>
#include <cstdlib>
#include <csignal>

#include "CRpc.h"
#include "RpcMap.h"

static volatile bool g_run = false;

static void signal_handler(int code)
{
  switch(code)
  {
    case SIGINT:
    case SIGTERM:
      g_run = false;
      break;
    default:
      break;
  }
}

/* NOTE: prt = &m_rpc */
void *thread_function( void *ptr )
{
	int status = -1;

	Json::Rpc::TcpServer server(std::string("127.0.0.1"), 8086);


	if(!networking::init())
	{
		std::cerr << "Networking initialization failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	if(signal(SIGTERM, signal_handler) == SIG_ERR)
	{
		std::cout << "Error signal SIGTERM will not be handled" << std::endl;
	}

	if(signal(SIGINT, signal_handler) == SIG_ERR)
	{
		std::cout << "Error signal SIGINT will not be handled" << std::endl;
	}

	MapRPC(server, *(CRpc*)ptr);

	/* server.SetEncapsulatedFormat(Json::Rpc::NETSTRING); */

	if(!server.Bind())
	{
		std::cout << "Bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	if(!server.Listen())
	{
		std::cout << "Listen failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	g_run = true;

	std::cout << "Start JSON-RPC TCP server" << std::endl;

	while(g_run)
	{
		server.WaitMessage(1000);
	}

	std::cout << "Stop JSON-RPC TCP server" << std::endl;
	server.Close();
	networking::cleanup();

	return NULL;
}

CRpcServer::CRpcServer()
	: m_p_facade(NULL) {
}

int CRpcServer::Init(CAppFacade * p_facade) {

	int status = -1;

	m_p_facade = p_facade;

	m_rpc.Init(m_p_facade);

	status = 0;
	return status;
}

int CRpcServer::Deinit() {

	int status = -1;

	m_p_facade = NULL;

	status = m_rpc.Deinit();

	return status;
}

int CRpcServer::Run() {
	int status = pthread_create( &m_server_thread, NULL, thread_function, (void*)&m_rpc);
	return status;
}

int CRpcServer::Stop() {
	g_run = false;
	return 0;
}




#include <cstdio>
#include <cstdlib>
#include <csignal>

#include "CDevice.h"
#include "CNetworkDevice.h"
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

int main(int argc, char * argv[]) {
	//CNetworkDevice cnd("192.168.1.14", "vkremin-nettop");
	//printf("name = %s\n", cnd.get_network_name());
	//printf("ip = %s\n", cnd.get_ip());

	CRpc rpc;
	Json::Rpc::TcpServer server(std::string("127.0.0.1"), 8086);

	/* to avoid compilation warnings */
	argc = argc;
	argv = argv;

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

	MapRPC(server, rpc);

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

	return 0;
}

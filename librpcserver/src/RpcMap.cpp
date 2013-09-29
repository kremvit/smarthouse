/*
 * RpcMap.cpp
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#include "RpcMap.h"

int MapRPC(Json::Rpc::TcpServer &r_server, CRpc & r_rpc){
	int err = -1;

	do {
		r_server.AddMethod(new Json::Rpc::RpcMethod<CRpc>(r_rpc, &CRpc::Print, std::string("print")));
		r_server.AddMethod(new Json::Rpc::RpcMethod<CRpc>(r_rpc, &CRpc::Notify, std::string("notify")));
		r_server.AddMethod(new Json::Rpc::RpcMethod<CRpc>(r_rpc, &CRpc::GetDeviceList, std::string("getdevicelist")));
		r_server.AddMethod(new Json::Rpc::RpcMethod<CRpc>(r_rpc, &CRpc::GetDevice, std::string("getdevice")));
		r_server.AddMethod(new Json::Rpc::RpcMethod<CRpc>(r_rpc, &CRpc::RestartDevice, std::string("restartdevice")));
		err = 0;
	}while(0);

	return err;
}




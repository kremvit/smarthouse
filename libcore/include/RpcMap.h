/*
 * CRpcMap.h
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#ifndef RPCMAP_H_
#define RPCMAP_H_

#include "CRpc.h"
#include "jsonrpc.h"
#include <json/json.h>

int MapRPC(Json::Rpc::TcpServer &r_server, CRpc & r_rpc);

#endif /* RPCMAP_H_ */

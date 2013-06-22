/*
 * CRpc.h
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#ifndef CRPC_H_
#define CRPC_H_

#include <json/json.h>

/**
 * \class CRpc
 * \brief RPC class for maping calls.
 */
class CRpc
{
  public:
    bool Print(const Json::Value& root, Json::Value& response);

    bool Notify(const Json::Value& root, Json::Value& response);

    bool GetDeviceList(const Json::Value& root, Json::Value& response);

    Json::Value GetDescription();
};

#endif /* CRPC_H_ */

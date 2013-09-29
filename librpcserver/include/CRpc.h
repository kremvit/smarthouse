/*
 * CRpc.h
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#ifndef CRPC_H_
#define CRPC_H_

#include <json/json.h>

#include "CAppFacade.h"

/**
 * \class CRpc
 * \brief RPC class for mapping calls.
 */
class CRpc
{
  private:

	CAppFacade * m_p_facade;

  public:
	CRpc();

	int Init(CAppFacade *);

	int Deinit();

    bool Print(const Json::Value& root, Json::Value& response);

    bool Notify(const Json::Value& root, Json::Value& response);

    bool GetDevice(const Json::Value& root, Json::Value& response);

    bool GetDeviceList(const Json::Value& root, Json::Value& response);

    bool RestartDevice(const Json::Value& root, Json::Value& response);

    Json::Value GetDescription();
};

#endif /* CRPC_H_ */

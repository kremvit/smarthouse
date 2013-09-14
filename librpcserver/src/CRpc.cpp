/*
 * CRpc.cpp
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#include "CRpc.h"

#include <vector>
#include <string>

CRpc::CRpc(){
	p_facade = NULL;
}

int CRpc::Init() {
	int status = -1;

	p_facade = CAppFacade::Create();
	if (p_facade != NULL) {
		status = 0;
	}

	return status;
}

int CRpc::Deinit() {
	int status = -1;

	status = p_facade->Delete();
	if (0 == status) {
		p_facade = NULL;
	}

	return status;
}


bool CRpc::Print(const Json::Value& root, Json::Value& response)
{
	std::cout << "Receive query: " << root << std::endl;
	response["jsonrpc"] = "2.0";
	response["id"] = root["id"];
	response["result"] = "success";
	return true;
}

bool CRpc::GetDeviceList(const Json::Value& root, Json::Value& response)
{
	int status = -1;
	bool ret_value = false;

	std::cout << "Notification: " << root << std::endl;

	response["jsonrpc"] = "2.0";
	response["id"] = root["id"];

	status = p_facade->GetDeviceList(response);

	if (0 == status) {
		ret_value = true;
	}
	return ret_value;
}

bool CRpc::Notify(const Json::Value& root, Json::Value& response)
{
	std::cout << "Notification: " << root << std::endl;
	response = Json::Value::null;
	return true;
}

Json::Value CRpc::GetDescription()
{
	Json::FastWriter writer;
	Json::Value root;
	Json::Value parameters;
	Json::Value param1;

	root["description"] = "Print";

	/* type of parameter named arg1 */
	param1["type"] = "integer";
	param1["description"] = "argument 1";

	/* push it into the parameters list */
	parameters["arg1"] = param1;
	root["parameters"] = parameters;

	/* no value returned */
	root["returns"] = Json::Value::null;

	return root;
}

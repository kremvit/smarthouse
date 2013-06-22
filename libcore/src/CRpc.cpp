/*
 * CRpc.cpp
 *
 *  Created on: Jun 9, 2013
 *      Author: vkremin
 */

#include "CRpc.h"

#include <vector>
#include <string>

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
  std::cout << "Notification: " << root << std::endl;
  std::vector<std::string> device_list;
  device_list.push_back("00");
  device_list.push_back("11");
  response["jsonrpc"] = "2.0";
  response["id"] = root["id"];
  response["device_list"]["0"] = "00";
  response["device_list"]["1"] = "11";
  return true;
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

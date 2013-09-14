/*
 * CAppFacade.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#include "CAppFacade.h"

CAppFacade * CAppFacade::Create() {
	CAppFacade * p_facade = new CAppFacade();

	return p_facade;
}

int CAppFacade::Init(CDeviceList * p_device_list) {
	int status = -1;

	m_p_device_list = p_device_list;
	status = 0;

	return status;
}

int CAppFacade::Delete() {
	int status = -1;
	return status;
}

int CAppFacade::GetDeviceList(Json::Value& device_list) {
	int status = -1;

	device_list["device_list"]["0"] = "44";
	device_list["device_list"]["1"] = "55";
	status = 0;

	return status;
}

int CAppFacade::TurnOffDevice(int device_index) {
	int status = -1;
	return status;
}

int CAppFacade::RestartDevice(int device_index) {
	int status = -1;
	return status;
}

CAppFacade::~CAppFacade() {
	;
}

CAppFacade::CAppFacade() {
	;
}

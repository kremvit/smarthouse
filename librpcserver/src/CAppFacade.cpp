/*
 * CAppFacade.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#include "CAppFacade.h"
#include "CNetworkDevice.h"

CAppFacade * CAppFacade::Create() {
	CAppFacade * p_facade = new CAppFacade();

	return p_facade;
}

int CAppFacade::Init(CDeviceList * p_device_list) {
	int status = -1;

	if (NULL == p_device_list) {
		return -1;
	}

	m_p_device_list = p_device_list;
	status = 0;

	return status;
}

int CAppFacade::Deinit() {
	int status = -1;

	m_p_device_list = NULL;
	status = 0;

	return status;
}

int CAppFacade::GetDeviceList(Json::Value& device_list) {
	int status = -1;

	m_p_device_list->Rebuild();

	for (int i = 0; i < m_p_device_list->Size(); i++) {
		device_list["device_list"][i]["id"] = i;
		device_list["device_list"][i]["ip"] = ((CNetworkDevice*)m_p_device_list->GetDevice(i))->get_ip();
		device_list["device_list"][i]["hostname"] = ((CNetworkDevice*)m_p_device_list->GetDevice(i))->get_network_name();
	}

	status = 0;

	return status;
}

int CAppFacade::GetDevice(int id, Json::Value& device) {
	int status = -1;

	if (id < 0 || id > m_p_device_list->Size()) {
		return -1;
	}

	device["device"]["id"] = id;
	device["device"]["ip"] = ((CNetworkDevice*)m_p_device_list->GetDevice(id))->get_ip();
	device["device"]["hostname"] = ((CNetworkDevice*)m_p_device_list->GetDevice(id))->get_network_name();

	status = 0;

	return status;
}

int CAppFacade::TurnOffDevice(int device_index) {
	int status = -1;
	return status;
}

int CAppFacade::RestartDevice(int device_index) {
	int status = -1;

	CNetworkDevice* device = (CNetworkDevice*)m_p_device_list->GetDevice(device_index);
	if (NULL == device) {
		return -1;
	}

	device->Restart();

	return status;
}

CAppFacade::~CAppFacade() {
	;
}

CAppFacade::CAppFacade() {
	;
}

/*
 * CDeviceList.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#include <cstdlib>

#include "CDeviceList.h"
#include "CNetworkDevice.h"
#include "CNmap.h"

int CDeviceList::AddDevice(CDevice* p_device) {
	int status = -1;

	device_list.push_back(p_device);

	status = 0;
	return status;
}

int CDeviceList::RemoveDevice(CDevice *& r_p_device) {
	int status = -1;

	if (NULL == r_p_device) {
		return -1;
	}

	/* TODO: Add erasing by UID */
	for (int i = 0; i < device_list.size(); i++) {
//		if (device_list[i] == )
	}

	r_p_device = NULL;

	status = 0;
	return status;
}

int CDeviceList::RemoveDevice(int index) {
	int status = -1;

	if (index < 0 || index > device_list.size()) {
		return -1;
	}

	/* TODO: Check if vector.erase call destructor ? */
	//delete device_list[index];

	device_list.erase(device_list.begin() + index);

	return status;
}

CDevice * CDeviceList::GetDevice(int index) {
	if (index < 0 || index > device_list.size())
		return NULL;

	return device_list[index];
}

int CDeviceList::Build() {
	int status = -1;

	CNmap * p_nmap = new CNmap();
	if (NULL == p_nmap) {
		return -1;
	}

	status = p_nmap->Scan(this);

	delete p_nmap;

	return status;
}

int CDeviceList::Rebuild() {
	int status = -1;

	for (int i = 0; i < device_list.size(); i++) {
		delete device_list[i];
	}
	device_list.clear();

	Build();

	return status;
}


void CDeviceList::Print() {
	for (int i = 0; i < device_list.size(); i++) {
		printf ("Device[%i]: %s (%s)\n", i, ((CNetworkDevice*)device_list[i])->get_ip(), ((CNetworkDevice*)device_list[i])->get_network_name());
	}
}

CDeviceList::~CDeviceList() {
	for (int i = 0; i < device_list.size(); i++) {
		delete device_list[i];
	}
	device_list.clear();
}

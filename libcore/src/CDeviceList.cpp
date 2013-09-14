/*
 * CDeviceList.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#include <cstdlib>

#include "CDeviceList.h"

int CDeviceList::AddDevice(CDevice*) {
	int status = -1;
	return status;
}
int CDeviceList::RemoveDevice(CDevice*) {
	int status = -1;
	return status;
}
CDevice * CDeviceList::getDevice(int index) {
	if (index < 0 || index > device_list.size())
		return NULL;

	return device_list[index];
}

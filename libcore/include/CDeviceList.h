/*
 * CDeviceList.h
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#ifndef CDEVICELIST_H_
#define CDEVICELIST_H_

#include <vector>

#include "CDevice.h"

class CDeviceList {
	std::vector<CDevice*> device_list;
public:
	int AddDevice(CDevice*);
	int RemoveDevice(CDevice*);
	CDevice * getDevice(int index);
};


#endif /* CDEVICELIST_H_ */

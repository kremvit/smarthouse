/*
 * CAppFacade.h
 *
 *  Created on: Sep 14, 2013
 *      Author: vkremin
 */

#ifndef CCOREFACADE_H_
#define CCOREFACADE_H_

#include <json/json.h>

#include "CDeviceList.h"

class CAppFacade {

	CDeviceList * m_p_device_list;

	CAppFacade();

public:

	static::CAppFacade * Create();

	int Delete();

	int Init(CDeviceList * p_device_list);

	int GetDeviceList(Json::Value& device_list);
	int TurnOffDevice(int device_index);
	int RestartDevice(int device_index);

	~CAppFacade();
};


#endif /* CCOREFACADE_H_ */

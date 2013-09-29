/*
 * CNetworkDevice.h
 *
 *  Created on: Apr 7, 2013
 *      Author: vkremin
 */

#ifndef CNETWORKDEVICE_H_
#define CNETWORKDEVICE_H_

#include "CDevice.h"
#include <stdio.h>

class CNetworkDevice : public CDevice {
	char * m_p_ip;
	char * m_p_network_name;
public:
	CNetworkDevice(char * p_ip, char * p_network_name);
	~CNetworkDevice();
	char * get_ip() { return this->m_p_ip; }
	char * get_network_name();
	int Restart();
};

#endif /* CNETWORKDEVICE_H_ */

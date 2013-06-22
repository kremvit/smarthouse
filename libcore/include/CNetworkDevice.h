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
	char * get_ip() { printf("CNetworkDevice::get_ip\n"); return this->m_p_ip; }
	char * get_network_name() { return this->m_p_network_name; }
};

extern "C" {
	CNetworkDevice* CNetworkDevice_new(char * p_ip, char * p_network_name){
		return new CNetworkDevice(p_ip, p_network_name);
	}
    char * CNetworkDevice_get_ip(CNetworkDevice * p_cnd){ p_cnd->get_ip(); }
    char * CNetworkDevice_get_network_name(CNetworkDevice * p_cnd) { p_cnd->get_network_name(); }
}


#endif /* CNETWORKDEVICE_H_ */

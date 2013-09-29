/*
 * CNetworkDevice.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: vkremin
 */

#include "CNetworkDevice.h"

#include <stdlib.h>
#include <stdio.h>

CNetworkDevice::CNetworkDevice(char * p_ip, char * p_network_name)
	: m_p_ip(p_ip)
	, m_p_network_name(p_network_name){
}
CNetworkDevice::~CNetworkDevice() {
	if (m_p_ip)
		free(m_p_ip);
	m_p_ip = NULL;

	if (m_p_network_name)
		free(m_p_ip);
	m_p_network_name = NULL;
}

char * CNetworkDevice::get_network_name() {
	if (NULL == this->m_p_network_name) {
		return "";
	}

	return this->m_p_network_name;
}

int CNetworkDevice::Restart() {
	int status = -1;
	char command[100];

	sprintf(command, "ssh %s -t \'%s\'", this->m_p_ip, "echo brcm | sudo -S reboot");

	FILE *cmd = popen(command, "r");
	char result[256]={0x0};
	while (!feof(cmd)) {
		fgets(result, 256, cmd);
		printf("%s\n", result);
	}
	pclose(cmd);

	status = 0;
	return status;
}

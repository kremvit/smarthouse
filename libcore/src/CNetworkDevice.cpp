#include "CNetworkDevice.h"
#include <stdlib.h>

CNetworkDevice::CNetworkDevice(char * p_ip, char * p_network_name)
	: m_p_ip(p_ip)
	, m_p_network_name(p_network_name){
}
CNetworkDevice::~CNetworkDevice() {
	m_p_ip = NULL;
	m_p_network_name = NULL;
}

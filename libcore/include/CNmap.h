/*
 * CNmap.h
 *
 *  Created on: Sep 15, 2013
 *      Author: vkremin
 */

#ifndef CNMAP_H_
#define CNMAP_H_

#include "CDevice.h"
#include "CDeviceList.h"

#include <vector>

class CNmap {
	char * m_p_subnet;
	char * m_p_path;
	const char * m_scan_file;
	const char * m_discover_file;
private:
	int read_result(CDeviceList *const&);
	int read_result(CDevice *const&);
public:

	CNmap();

	~CNmap();

	int Scan(CDeviceList  *const&);

	int DiscoverDevice(CDevice *const&);
};


#endif /* CNMAP_H_ */

/*
 * CDevice.h
 *
 *  Created on: Apr 7, 2013
 *      Author: vkremin
 */

#ifndef CDEVICE_H_
#define CDEVICE_H_

class CDevice {
	int m_id;
public:
	CDevice();
	~CDevice();

	int get_id() { return this->m_id;}
};


#endif /* CDEVICE_H_ */

/*
 * CNmap.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: vkremin
 */

#include <stdio.h>
#include <stdlib.h>

#include <cstring>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "CNmap.h"
#include "CNetworkDevice.h"

CNmap::CNmap()
	: m_p_subnet(NULL)
	, m_scan_file("scan.res")
	, m_discover_file("discover.res"){
	m_p_path = getenv ("PWD");
}

CNmap::~CNmap() {
	m_p_subnet = NULL;
	m_p_path = NULL;
}

int CNmap::Scan(CDeviceList *const& r_device_list) {
	int status = -1;

	char command[200];

	sprintf(command, "%s/../3rd-party/nmap-6.40/nmap -sP 192.168.1.1/24 -oX %s", m_p_path, m_scan_file);

	/*FILE *cmd = popen(command, "r");
	char result[256]={0x0};
	while (!feof(cmd)) {
		fgets(result, 256, cmd);
	    printf("%s\n", result);
	}
	pclose(cmd);*/

	status = system(command);
	if (status != 0) {
		return status;
	}

	status = read_result(r_device_list);

	return status;
}

int CNmap::DiscoverDevice(CDevice *const& p_r_device) {
	int status = -1;

	char* p_path = NULL;
	p_path = getenv ("PWD");
	if (NULL == p_path) {
	    status = -1;
	    return status;
	}

	char command[200];

	sprintf(command, "%s/../3rd-party/nmap-6.40/nmap -sP %s -oX %s", m_p_path, ((CNetworkDevice*)p_r_device)->get_ip(), m_discover_file);

	/*FILE *cmd = popen(command, "r");
	char result[256]={0x0};
	while (!feof(cmd)) {
		fgets(result, 256, cmd);
	    printf("%s\n", result);
	}
	pclose(cmd);*/

	status = system(command);
	if (status != 0) {
		return status;
	}

	status = read_result(p_r_device);

	return status;
}

const char * read_state(xmlNode *&p_node) {
	const char * state = NULL;
	if (NULL == p_node || NULL == p_node->children) {
		return NULL;
	}

	xmlNode * cur_node = p_node->children;
	xmlAttr* attribute = cur_node->properties;
	if (NULL == attribute) {
		return NULL;
	}

	while(attribute && attribute->name && attribute->children)
	{
	  xmlChar* value = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
	  /* TODO: Check for memory leak */
	  //	  xmlFree(value);
	  attribute = attribute->next;
	  state = reinterpret_cast<const char *>(value);
	  break;
	}

	p_node = cur_node;

	return state;
}

const char * read_address(xmlNode *& p_node) {
	const char * address = NULL;
	if (NULL == p_node) {
		return NULL;
	}

	xmlNode* cur_node = p_node;

	for (cur_node = cur_node->next; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			break;
		}
	}
	if (NULL == cur_node || NULL == cur_node->properties) {
		return NULL;
	}

	xmlAttr* attribute = cur_node->properties;

	while(attribute && attribute->name && attribute->children)
	{
	  xmlChar* value = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
	  //xmlFree(value);
	  attribute = attribute->next;
	  address = reinterpret_cast<const char *>(value);
	  break;
	}

	p_node = cur_node;

	return address;
}

const char * read_hostname(xmlNode *&p_node) {
	const char * hostname = NULL;
	if (NULL == p_node) {
		return NULL;
	}

	xmlNode* cur_node = p_node;

	for (cur_node = cur_node->next; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			break;
		}
	}
	cur_node = cur_node->children;
	if (NULL == cur_node) {
		return NULL;
	}

	for (cur_node = cur_node->next; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			break;
		}
	}
	if (NULL == cur_node || NULL == cur_node->properties) {
		return NULL;
	}
	xmlAttr* attribute = cur_node->properties;
	if (NULL == attribute) {
		return NULL;
	}

	while(attribute && attribute->name && attribute->children)
	{
	  xmlChar* value = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
	  //do something with value
	  //xmlFree(value);
	  attribute = attribute->next;
	  hostname = reinterpret_cast<const char *>(value);
	  break;
	}

	p_node = cur_node;

	return hostname;
}

int add_host(xmlNode * a_node, CDeviceList *const& r_device_list) {
	int status = -1;
	CDevice * p_device = NULL;

	xmlNode *cur_node = a_node;

	/* read satate */
	const char * state = read_state(cur_node);


	/* read address */
	const char * address = read_address(cur_node);

	/* read hostname */
	const char * hostname = read_hostname(cur_node);


	p_device = new CNetworkDevice((char *)address, (char *)hostname);
	r_device_list->AddDevice(p_device);

	status = 0;
	return status;
}

int build_device_list(xmlNode * a_node, CDeviceList *const& r_device_list)
{
	int status = -1;
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if (strcmp(reinterpret_cast<const char*>(cur_node->name), "host") == 0) {
            	add_host(cur_node, r_device_list);
            	continue;
            }
        }

        if (cur_node->children) {
        	build_device_list(cur_node->children, r_device_list);
        }
    }
    status = 0;
    return status;
}

int CNmap::read_result(CDeviceList *const& r_device_list) {
	int status = -1;

	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION

	/* parse the file and get the DOM */
	doc = xmlReadFile(m_scan_file, NULL, 0);
	if (NULL == doc) {
		return -1;
	}

	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);

	status = build_device_list(root_element, r_device_list);

	/* free the document */
	xmlFreeDoc(doc);

	/*
	 *Free the global variables that may
	 *have been allocated by the parser.
	 */
	xmlCleanupParser();

	status = 0;
	return status;
}

int CNmap::read_result(CDevice *const& r_device) {
	int status = -1;

	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION

	/* parse the file and get the DOM */
	doc = xmlReadFile(m_discover_file, NULL, 0);
	if (NULL == doc) {
		return -1;
	}

	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);

	//status = build_device_list(root_element, r_device_list);

	/* free the document */
	xmlFreeDoc(doc);

	/*
	 *Free the global variables that may
	 *have been allocated by the parser.
	 */
	xmlCleanupParser();

	status = 0;
	return status;
}

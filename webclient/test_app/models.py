from django.db import models

from ctypes import cdll

lib = cdll.LoadLibrary('/home/vkremin/temp/smarthouse/libs/libcore.so')

class CNetworkDevice(object):
    def __init__(self):
        self.obj = lib.CNetworkDevice_new('12', '23')

    def get_ip(self):
        lib.CNetworkDevice_get_ip(self.obj)
    def get_name(self):
	import pdb; pdb.set_trace()
        lib.CNetworkDevice_get_network_name(self.obj)

class PC(models.Model):
    pc = CNetworkDevice()
    
    def name(self):
	import pdb; pdb.set_trace()
	return self.pc.get_name()

    def ip(self):
	import pdb; pdb.set_trace()
	return self.pc.get_ip()

    def __unicode__(self):
#        return self.pc.get_ip
	return 'asdasd'
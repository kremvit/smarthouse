import os, sys
sys.path.append('/home/vkremin/temp/smarthouse/webclient/virtualenv/kremvit/local/lib/python2.7/site-packages/')
sys.path.append('/home/vkremin/temp/smarthouse/')
sys.path.append('/home/vkremin/temp/smarthouse/webclient')
sys.path.append('/home/vkremin/temp/smarthouse/webclient/kremvit')
os.environ['DJANGO_SETTINGS_MODULE'] = 'kremvit.settings'
import django.core.handlers.wsgi
application = django.core.handlers.wsgi.WSGIHandler()
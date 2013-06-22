import os, sys
sys.path.append('/home/vkremin/.virtualenvs/kremvit/local/lib/python2.7/site-packages/')
sys.path.append('/home/vkremin/python-workspace/')
sys.path.append('/home/vkremin/python-workspace/kremvit/')
os.environ['DJANGO_SETTINGS_MODULE'] = 'kremvit.settings'
import django.core.handlers.wsgi
application = django.core.handlers.wsgi.WSGIHandler()
from django.conf.urls import patterns, url

from test_app import views

urlpatterns = patterns('',
    # ex: /kremvit/
    url(r'^$', views.index, name='index'),
    # ex: /kremvit/5/
    url(r'^(?P<pc_id>\d+)/$', views.detail, name='detail'),
    # ex: /kremvit/4/restart
    url(r'^(?P<pc_id>\d+)/restart/$', views.restart_pc, name='restart'),
)

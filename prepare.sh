#!/bin/sh

cd webclient/virtualenv
virtualenv kremvit
source ./kremvit/bin/activate
pip install django

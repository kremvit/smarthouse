#!/bin/sh

cd webclient/virtualenv
virtualenv kremvit
source ./kremvit/bin/acrivate
pip install django

#!/usr/bin/env python
import os
import sys

if __name__ == "__main__":
    os.environ.setdefault("DJANGO_SETTINGS_MODULE", "kremvit.settings")
    os.environ['LD_LIBRARY_PATH']='$LD_LIBRARY_PATH:/home/vkremin/temp/smarthouse/libs'

    from django.core.management import execute_from_command_line

    execute_from_command_line(sys.argv)

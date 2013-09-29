#!/bin/sh

export PROJECT_HOME=`pwd`/../
export PWD=`pwd`/../smarthouse
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../libs
./smarthouse

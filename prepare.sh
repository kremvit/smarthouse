#!/bin/bash

export LINUX_GCC='linux-gcc-4.7'
export JSONCPP_DIR='jsoncpp-src-0.5.0'
export JSONRPC_DIR='jsonrpc-cpp-0.4'
export SCONS_DIR='scons-local-1.2.0'

# build jsoncpp
function build_jsoncpp() {
    cp -a $SCONS_DIR/* jsoncpp-src-0.5.0/
    cd $JSONCPP_DIR
    python scons.py platform=linux-gcc check
    cp -a ./libs/$LINUX_GCC/libjson_${LINUX_GCC}_libmt.so ../../libs/libjson.so
    cp -a ./libs/$LINUX_GCC/libjson_${LINUX_GCC}_libmt.a ../../libs/libjson.a
    cd ../
}

#build json rpc
function build_jsonrpc() {
    cp -a $SCONS_DIR/* jsonrpc-cpp-0.4/
    cd $JSONRPC_DIR
    python scons.py platform=linux-gcc
    cp -a libjsonrpc.so ../../libs/libjsonrpc.so
    cd ../
}


# prepare C++ environment for libcore and tests
function prepare_c++() {
    cd 3rd-party

    for file in *tar.gz
    do
        tar -xzvf $file
    done

    for file in *tar.bz2
    do
        tar -xvjpf $file
    done

    build_jsoncpp
    build_jsonrpc

    cd ../
}


# initialize python environment for webclient
function prepare_python() {
    mkdir webclient/virtualenv
    cd webclient/virtualenv
    virtualenv kremvit
    source ./kremvit/bin/activate
    pip install django
}

clean() {
    echo "Cleaning ..."

    rm -rf ./3rd-party/$SCONS_DIR
    rm -rf ./3rd-party/$JSONCPP_DIR
    rm -rf ./3rd-party/$JSONRPC_DIR
    rm -rf ./webclient/virtualenv

    exit 0
}

$@

# main actions
prepare_c++
prepare_python
exit 0



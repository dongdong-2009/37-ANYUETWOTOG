#!/bin/sh

export TSLIB_ROOT=/usr/local/tslib
export TSLIB_TSDEVICE=/dev/input/touchscreen0
export TSLIB_CONFFILE=$TSLIB_ROOT/etc/ts.conf
export TSLIB_PLUGINDIR=$TSLIB_ROOT/lib/ts
export TSLIB_CALIBFILE=/etc/pointercal
export TSLIB_FBDEVICE=/dev/fb0
export QWS_MOUSE_PROTO=tslib:/dev/input/touchscreen0
export LD_LIBRARY_PATH=/usr/local/qwt-arm/lib



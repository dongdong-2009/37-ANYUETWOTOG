#!  /usr/bin
make distclean
/usr/local/Trolltech/Qte-4.8.4-arm/bin/qmake
make -j4
cp hmisvr $ANYUETWOTOG_APP_RUNTIME_DIR 

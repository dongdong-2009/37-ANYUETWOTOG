make distclean
qmake-arm
make -j4
cp hmisvr $ARM_CDJ_APP_RUNTIME_DIR

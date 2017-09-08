#/bin/sh
ifconfig eth0 192.168.227.203
ifconfig eth0 netmask 255.255.255.0
route add default gw 192.168.227.254

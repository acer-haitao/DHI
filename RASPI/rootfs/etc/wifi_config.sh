#!/bin/sh

set -e

sleep 1 
ifconfig wlan0
sleep 1 
ifconfig wlan0 up
sleep 1 
ifconfig wlan0 192.168.0.200
sleep 1

route add default gw 192.168.0.1
sleep 1

wpa_supplicant -B -i wlan0 -c /etc/wpa-psk-tkip.conf
sleep 1

#wpa_cli status


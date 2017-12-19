#!/bin/bash
make atreus:tws2
echo Press program key now: switch to third layer, hold B
while [ ! -r /dev/ttyACM0 ]; do sleep 1; done
avrdude -p atmega32u4 -c avr109 -U flash:w:atreus_tws2.hex -P /dev/ttyACM0

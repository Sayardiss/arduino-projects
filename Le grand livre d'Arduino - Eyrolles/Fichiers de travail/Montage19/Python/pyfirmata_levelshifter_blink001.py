#!/usr/bin/python

from time import sleep              # importation de la fonction sleep
from pyfirmata import Arduino, util # importation de la fonction Arduino, util

# communication avec la carte Arduino via le port s�rie
arduinoboard = Arduino('/dev/ttyAMA0')

# programmation de la broche Arduino
pin13 = arduinoboard.get_pin('d:8:o')
while True:
    pin13.write(1) # LED allum�e
    sleep(1)       # pause 1 seconde 
    pin13.write(0) # LED �teinte
    sleep(1)       # pause 1 seconde

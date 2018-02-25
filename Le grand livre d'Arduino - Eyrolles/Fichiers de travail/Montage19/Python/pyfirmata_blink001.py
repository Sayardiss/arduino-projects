#!/usr/bin/python

from time import sleep              # importation de la fonction sleep
from pyfirmata import Arduino, util # importation de la fonction Arduino, util

# communication avec la carte Arduino via le port série
arduinoboard = Arduino('/dev/ttyACM0')

# implémentation d'un Iterator Thread pour éviter
# un débordement de buffer
it = util.Iterator(arduinoboard)
it.start()

# programmation de la broche Arduino
pin13 = arduinoboard.get_pin('d:13:o')
while True:
    pin13.write(1) # LED allumée
    sleep(1)       # pause 1 seconde
    pin13.write(0) # LED éteinte
    sleep(1)       # pause 1 seconde

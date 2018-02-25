#!/usr/bin/env python
import pyfirmata

arduinoboard = pyfirmata.Arduino('/dev/ttyACM0')

pin8 = arduinoboard.get_pin('d:8:i') # entrée sur broche 8

it = pyfirmata.util.Iterator(arduinoboard)
it.start()
pin8.enable_reporting()

while True:
    pin8_state = pin8.read() # lecture de l'état
    if pin8_state == True:
        print 'bouton enfoncé'
    if pin8_state == False:
        print 'bouton non enfoncé'
    arduinoboard.pass_time(0.5) # pause

#!/usr/bin/env python
import pyfirmata
from Tkinter import *

arduinoboard = pyfirmata.Arduino('/dev/ttyACM0')

it = pyfirmata.util.Iterator(arduinoboard)
it.start()

pin3 = arduinoboard.get_pin('d:3:s') # servo sur la broche 3

def cleanup():
    # désactivation de la broche 3
    pin3.write(0)
    arduinoboard.exit()

def moveServo(a):
    # commande du servo par la broche 3
    pin3.write(a)

# GUI
master = Tk()
master.wm_protocol("WM_DELETE_WINDOW", cleanup)
master.wm_title('Servo-Control')

# initialisation du potentiomètre
scale = Scale(master,
    from_ = 0,
    to = 179,
    command = moveServo,
    orient = HORIZONTAL,
    length = 400,
    label = 'Angle')

scale.pack(anchor = CENTER) # centré
mainloop()                  # démarrage du TK Event-Loop

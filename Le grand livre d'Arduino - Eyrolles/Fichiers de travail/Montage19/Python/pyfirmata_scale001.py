#!/usr/bin/env python
import pyfirmata
from Tkinter import *

arduinoboard = pyfirmata.Arduino('/dev/ttyACM0')

pin3 = arduinoboard.get_pin('d:3:p') # sortie MLI sur la broche 3

def cleanup():
    # LED 3 éteinte
    pin3.write(0)
    arduinoboard.exit()
    
def setPWM(pwm):
    # commande par MLI de la LED 3
    # accepte des valeurs comprises entre 0 et 1
    pin3.write(float(pwm)/100.0)    

# GUI
master = Tk()
master.wm_protocol("WM_DELETE_WINDOW", cleanup)

# initialisation du potentiomètre
scale = Scale(master,
    from_ = 0,
    to = 100,
    command = setPWM,
    orient = HORIZONTAL,
    length = 400,
    label = 'PWM-Value')

scale.pack(anchor = CENTER) # centré
master.mainloop()           # démarrage de TK Event-Loop

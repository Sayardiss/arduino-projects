#include <Arduino.h>

#define PIN 8

/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  MI_2, SI_1, DO_2, RE_2, DO_2, SI_1, LA_1, LA_1, DO_2, MI_2, RE_2, DO_2, SI_1,
  DO_2, RE_2, MI_2, DO_2, LA_1, LA_1, LA_1, SI_1, DO_2
  // NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 6, 8, 4, 4, 4, 4, 8, 8, 8, 8
  // 4, 8, 8, 1, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 23; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN);
    delay(40);
  }
}

void loop() {
  // no need to repeat the melody.
}


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

int in_pin = 7;

// notes in the song "Astronomia" by Vicetone
int theme[] = {
  NOTE_AS4,NOTE_AS4,NOTE_AS4,NOTE_AS4,  NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,
  NOTE_C4,NOTE_C4,NOTE_C4,NOTE_C4,  NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,
  NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,  NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,
  NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,  NOTE_C4,NOTE_AS4,NOTE_A4,NOTE_F4,
  NOTE_G4,NOTE_G4,NOTE_D4,NOTE_C4,  NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_A4,
  NOTE_C4,NOTE_AS4,NOTE_A4,NOTE_G4, NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_AS4,
  NOTE_A4,NOTE_AS4,NOTE_G4,NOTE_G4,

  NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_A4,  NOTE_AS4,NOTE_G4,NOTE_G4,NOTE_D4,
  NOTE_C4,NOTE_AS4,NOTE_A4,NOTE_A4,  NOTE_A4,NOTE_C4,NOTE_AS4,NOTE_A4,
  NOTE_G4,NOTE_G4,NOTE_AS4,NOTE_A4,  NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,
  NOTE_B4,

  NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_A4,  NOTE_AS4,NOTE_G4,NOTE_G4,NOTE_D4,
  NOTE_C4,NOTE_AS4,NOTE_A4,NOTE_A4,  NOTE_A4,NOTE_C4,NOTE_AS4,NOTE_A4,
  NOTE_G4,NOTE_G4,NOTE_AS4,NOTE_A4,  NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,
  NOTE_B4,
  
};

int deathSound[] = {
  NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, 
  NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, 
  NOTE_GS4, NOTE_G4, NOTE_D4, NOTE_E4
};

int deathDurations[] = {
  6, 6, 4, 12,   12, 12, 12, 12,
  12, 8, 8, 3
};

// Made all notes eighth notes
int themeDurations[] = {
  8, 8, 8, 8,   8, 8, 8, 8, 
  8, 8, 8, 8,   8, 8, 8, 8, 
  8, 8, 8, 8,   8, 8, 8, 8, 
  8, 8, 8, 8,   8, 8, 8, 8, 
  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,     
  
  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,   8, 8, 8, 8,
  8,

  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,   8, 8, 8, 8,
  8, 8, 8, 8,   8, 8, 8, 8,
  8,

};


void setup() {

}

void loop() {
if (digitalRead(7) == LOW) {

  bgmusic();
  delay(1000);
} else {

  gameovermusic();
  delay(1000);
}

}

void bgmusic() {

  while(digitalRead(7) == LOW){
    // iterate over the 102 notes of the melody:
  for (int thisNote = 0; thisNote < 102; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //Output is pin 13
    int noteDuration = 1000 / themeDurations[thisNote];
    tone(13, theme[thisNote], noteDuration);

    // a minimum time must be set between the notes to distinguish them
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stops the tone playing:
    noTone(13);
    }
  }
};

  void gameovermusic() {
  // iterate over the 102 notes of the melody:
  for (int thisNote = 0; thisNote < 7; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //Output is pin 13
    int noteDuration = 1000 / deathDurations[thisNote];
    tone(13, deathSound[thisNote], noteDuration);

    // a minimum time must be set between the notes to distinguish them
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    // stops the tone playing:
    noTone(13);
    
  }
  };

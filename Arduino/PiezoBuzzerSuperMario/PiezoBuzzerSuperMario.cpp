// Do not remove the include below
#include "PiezoBuzzerSuperMario.h"
#include "Microphone.h"

#include <stdio.h>
//#include <iostream>

//using namespace std;


#define MELODYPIN 17
#define LEDPIN 14

int track = 1;

void setup(void)
{
	Serial.begin(9600);

	pinMode(MELODYPIN, OUTPUT);//buzzer
	pinMode(LEDPIN, OUTPUT);//led indicator when singing a note

}

String s;

void loop(){
//  //sing the tunes
//  sing(1);
//  sing(1);
//  sing(2);

	bool flag = runMicroPhone();
//	bool flag = true;

//	s = flag +"\t"+ track;
	Serial.println(flag);

	if (flag){
		sing(track++);
		if (track==3)
			track=1;
	}
//	else if (flag && ++track==2){
//		sing(2);
//		track=0;
//	}
}


void sing(int song) {
  // iterate over the notes of the melody:
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(MELODYPIN, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(MELODYPIN, 0, noteDuration);

    }

  } else {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(MELODYPIN, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(MELODYPIN, 0, noteDuration);

    }
  }
}


void buzz(int targetPin, long frequency, long length) {
  digitalWrite(LEDPIN, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);

}

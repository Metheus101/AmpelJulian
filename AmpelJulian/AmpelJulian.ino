/*
 Name:		AmpelJulian.ino
 Created:	29.12.2019 14:36:04
 Author:	admin
*/


//Pindef
namespace pin 
{
    int trig_R = A0;
    int trig_Y = 15;
    int trig_G = 16;
    int trig_4 = 17;

    int but_R_sig = 12;
    int but_G_sig = 9;
    int but_B_sig = 8;
    int but_Y_sig = 4;
    int but_W_sig = 2;

    int but_R_led = 11;
    int but_G_led = 10;
    int but_B_led = 6;
    int but_Y_led = 5;
    int but_W_led = 3;

    int ir_sig = 19;
}

// the setup function runs once when you press reset or power the board
void setup() {

    //IO Setup
    digitalWrite(pin::trig_R, LOW);
    digitalWrite(pin::trig_Y, LOW);
    digitalWrite(pin::trig_G, LOW);
    digitalWrite(pin::trig_4, LOW);

    digitalWrite(pin::but_R_led, LOW);
    digitalWrite(pin::but_G_led, LOW);
    digitalWrite(pin::but_B_led, LOW);
    digitalWrite(pin::but_Y_led, LOW);
    digitalWrite(pin::but_W_led, LOW);


    pinMode(pin::trig_R, OUTPUT);
    pinMode(pin::trig_Y, OUTPUT);
    pinMode(pin::trig_G, OUTPUT);
    pinMode(pin::trig_4, OUTPUT);

    pinMode(pin::but_R_led, OUTPUT);
    pinMode(pin::but_G_led, OUTPUT);
    pinMode(pin::but_B_led, OUTPUT);
    pinMode(pin::but_Y_led, OUTPUT);
    pinMode(pin::but_W_led, OUTPUT);

    pinMode(pin::but_R_sig, INPUT_PULLUP);
    pinMode(pin::but_G_sig, INPUT_PULLUP);
    pinMode(pin::but_B_sig, INPUT_PULLUP);
    pinMode(pin::but_Y_sig, INPUT_PULLUP);
    pinMode(pin::but_W_sig, INPUT_PULLUP);

    digitalWrite(pin::but_R_led, HIGH);
    digitalWrite(pin::but_G_led, HIGH);
    digitalWrite(pin::but_B_led, HIGH);
    digitalWrite(pin::but_Y_led, HIGH);
    digitalWrite(pin::but_W_led, HIGH);
    delay(1000);
    digitalWrite(pin::but_R_led, LOW);
    digitalWrite(pin::but_G_led, LOW);
    digitalWrite(pin::but_B_led, LOW);
    digitalWrite(pin::but_Y_led, LOW);
    digitalWrite(pin::but_W_led, LOW);

    digitalWrite(pin::trig_R, HIGH);
    digitalWrite(pin::trig_Y, HIGH);
    digitalWrite(pin::trig_G, HIGH);
    digitalWrite(pin::trig_4, HIGH);
    delay(1000);
    digitalWrite(pin::trig_R, LOW);
    digitalWrite(pin::trig_Y, LOW);
    digitalWrite(pin::trig_G, LOW);
    digitalWrite(pin::trig_4, LOW);


}

// the loop function runs over and over again until power down or reset
void loop() {
  
    if (!digitalRead(pin::but_R_sig))
    {digitalWrite(pin::trig_R, LOW); digitalWrite(pin::but_R_led, HIGH);}
    else { digitalWrite(pin::trig_R, HIGH); digitalWrite(pin::but_R_led, LOW); }
}

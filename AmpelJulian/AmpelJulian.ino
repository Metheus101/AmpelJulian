/*
 Name:		AmpelJulian.ino
 Created:	29.12.2019 14:36:04
 Author:	admin
*/


//Pindef
namespace pin 
{
    int trig_R = A0;
    int trig_Y = A1;
    int trig_G = A2;
    int trig_4 = A3;

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

    int ir_sig = A5;
}

// Classes

class buttons
{
public:
    int R_sig;
    int G_sig;
    int B_sig;
    int Y_sig;
    int W_sig;

    int R_led;
    int G_led;
    int B_led;
    int Y_led;
    int W_led;

private:
    int
};

// the setup function runs once when you press reset or power the board
void setup() {

    //IO Setup
    digitalWrite(pin::trig_R, HIGH);
    digitalWrite(pin::trig_Y, HIGH);
    digitalWrite(pin::trig_G, HIGH);
    digitalWrite(pin::trig_4, HIGH);

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
    delay(2000);
    digitalWrite(pin::but_R_led, LOW);
    digitalWrite(pin::but_G_led, LOW);
    digitalWrite(pin::but_B_led, LOW);
    digitalWrite(pin::but_Y_led, LOW);
    digitalWrite(pin::but_W_led, LOW);



    //Testmode
    if (!digitalRead(pin::but_B_sig))
    {
        while (1)
        {
            if (!digitalRead(pin::but_R_sig))
            {
                digitalWrite(pin::trig_R, LOW); digitalWrite(pin::but_R_led, HIGH);
            }
            else { digitalWrite(pin::trig_R, HIGH); digitalWrite(pin::but_R_led, LOW); }

            if (!digitalRead(pin::but_Y_sig))
            {
                digitalWrite(pin::trig_Y, LOW); digitalWrite(pin::but_Y_led, HIGH);
            }
            else { digitalWrite(pin::trig_Y, HIGH); digitalWrite(pin::but_Y_led, LOW); }

            if (!digitalRead(pin::but_G_sig))
            {
                digitalWrite(pin::trig_G, LOW); digitalWrite(pin::but_G_led, HIGH);
            }
            else { digitalWrite(pin::trig_G, HIGH); digitalWrite(pin::but_G_led, LOW); }

            if (!digitalRead(pin::but_W_sig))
            {
                digitalWrite(pin::trig_4, LOW); digitalWrite(pin::but_W_led, HIGH);
            }
            else { digitalWrite(pin::trig_4, HIGH); digitalWrite(pin::but_W_led, LOW); }

            if (!digitalRead(pin::but_B_sig))
            {
                digitalWrite(pin::but_B_led, HIGH);
                digitalWrite(pin::trig_R, LOW); digitalWrite(pin::trig_4, LOW);
                digitalWrite(pin::trig_Y, LOW); digitalWrite(pin::trig_G, LOW);
            }
            else
            {
                digitalWrite(pin::but_B_led, LOW);
                digitalWrite(pin::trig_R, HIGH); digitalWrite(pin::trig_4, HIGH);
                digitalWrite(pin::trig_Y, HIGH); digitalWrite(pin::trig_G, HIGH);

            }
        }
    }

    digitalWrite(pin::trig_R, LOW);
    digitalWrite(pin::trig_Y, LOW);
    digitalWrite(pin::trig_G, LOW);
    digitalWrite(pin::trig_4, LOW);  
    delay(1000);
    digitalWrite(pin::trig_R, HIGH);
    digitalWrite(pin::trig_Y, HIGH);
    digitalWrite(pin::trig_G, HIGH);
    digitalWrite(pin::trig_4, HIGH);
}



// the loop function runs over and over again until power down or reset
void loop() 
{
  
}

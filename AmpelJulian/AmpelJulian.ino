/*
 Name:		AmpelJulian.ino
 Created:	29.12.2019 14:36:04
 Author:	admin
*/

//Variables

//times in 100ms
int time_default_RY = 100;//10s R
int time_default_YG = 130;//3s Y
int time_default_GY = 230;//10s G
int time_default_YR = 30;//3s Y

int time_R_RY = 30;//3s R
int time_R_YG = 40;//1s Y
int time_R_GY = 70;//3s G
int time_R_YR = 80;//1s Y

int time_Y_random = 30;//3s

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

// ---------------------------------Functions--------------------------

//

//Set Red
void set_red()
{
	digitalWrite(pin::but_R_led, HIGH);
	digitalWrite(pin::but_G_led, LOW);
	digitalWrite(pin::but_B_led, LOW);
	digitalWrite(pin::but_Y_led, LOW);
	digitalWrite(pin::but_W_led, LOW);
	digitalWrite(pin::trig_R, LOW);
	digitalWrite(pin::trig_Y, HIGH);
	digitalWrite(pin::trig_G, HIGH);
	digitalWrite(pin::trig_4, LOW);
}

//Set Yellow
void set_yellow()
{
	digitalWrite(pin::but_R_led, LOW);
	digitalWrite(pin::but_G_led, LOW);
	digitalWrite(pin::but_B_led, LOW);
	digitalWrite(pin::but_Y_led, HIGH);
	digitalWrite(pin::but_W_led, LOW);
	digitalWrite(pin::trig_R, HIGH);
	digitalWrite(pin::trig_Y, HIGH);
	digitalWrite(pin::trig_G, HIGH);
	digitalWrite(pin::trig_4, LOW);
}

//Set Green
void set_green()
{
	digitalWrite(pin::but_R_led, LOW);
	digitalWrite(pin::but_G_led, HIGH);
	digitalWrite(pin::but_B_led, LOW);
	digitalWrite(pin::but_Y_led, LOW);
	digitalWrite(pin::but_W_led, LOW);
	digitalWrite(pin::trig_R, HIGH);
	digitalWrite(pin::trig_Y, HIGH);
	digitalWrite(pin::trig_G, LOW);
	digitalWrite(pin::trig_4, LOW);
}

// Set Off
void set_off()
{
	digitalWrite(pin::but_R_led, LOW);
	digitalWrite(pin::but_G_led, LOW);
	digitalWrite(pin::but_B_led, LOW);
	digitalWrite(pin::but_Y_led, LOW);
	digitalWrite(pin::but_W_led, HIGH);
	digitalWrite(pin::trig_R, HIGH);
	digitalWrite(pin::trig_Y, HIGH);
	digitalWrite(pin::trig_G, HIGH);
	digitalWrite(pin::trig_4, HIGH);
}

//Mode Blue (Automatic Mode)
void mode_blue()
{
	digitalWrite(pin::but_R_led, LOW);
	digitalWrite(pin::but_G_led, LOW);
	digitalWrite(pin::but_B_led, HIGH);
	digitalWrite(pin::but_Y_led, LOW);
	digitalWrite(pin::but_W_led, LOW);
	digitalWrite(pin::trig_R, HIGH);
	digitalWrite(pin::trig_Y, HIGH);
	digitalWrite(pin::trig_G, HIGH);
	digitalWrite(pin::trig_4, HIGH);
	//wait for Release of Button blue
	while (!digitalRead(pin::but_B_sig))
	{
		delay(10);
	}
	delay(100);

	//Loop till White is pressed
	while (!digitalRead(pin::but_W_sig))
	{
		static int count = 0;
		static int mode = 0;//Mode 0: Default

		//setmode...
		//(use Buttons R G Y B  to switch modes; B=default)
		if (!digitalRead(pin::but_B_sig))
		{
			mode = 0;
			count = 0;
		}
		if (!digitalRead(pin::but_R_sig))
		{
			mode = 1;
			count = 0;
		}
		if (!digitalRead(pin::but_Y_sig))
		{
			mode = 2;
			count = 0;
		}

		//Mode 0:
		if (mode == 0)
		{
			if (count = 0)
			{
				digitalWrite(pin::trig_Y, HIGH);
				digitalWrite(pin::trig_R, LOW);
				digitalWrite(pin::trig_4, LOW);
				count++;
			}

			if (count == time_default_RY);
			{
				digitalWrite(pin::trig_R, HIGH);
				digitalWrite(pin::trig_Y, LOW);
				count++;
			}

			if (count == time_default_YG);
			{
				digitalWrite(pin::trig_Y, HIGH);
				digitalWrite(pin::trig_G, LOW);
				count++;
			}
			if (count == time_default_YR - 1);
			{
				count = 0;
			}
		}

		//Mode 1:
		if (mode == 1)
		{
			if (count = 0)
			{
				digitalWrite(pin::trig_Y, HIGH);
				digitalWrite(pin::trig_R, LOW);
				digitalWrite(pin::trig_4, LOW);
				count++;
			}

			if (count == time_R_RY);
			{
				digitalWrite(pin::trig_R, HIGH);
				digitalWrite(pin::trig_Y, LOW);
				count++;
			}

			if (count == time_R_YG);
			{
				digitalWrite(pin::trig_Y, HIGH);
				digitalWrite(pin::trig_G, LOW);
				count++;
			}
			if (count == time_R_YR - 1);
			{
				count = 0;
			}
		}

		//Mode 2 Y Random
		if (mode == 2)
		{
			static long lastlight = 4;
			static long randomlight;

			if (count == time_Y_random)
			{
				count = 0;
			}
			if (count == 0);
			{
				randomlight = random(3);
				while (randomlight == lastlight)
				{
					randomlight = random(3);
				}
				lastlight = randomlight;

				if (randomlight == 0)
				{
					digitalWrite(pin::trig_R, LOW);
					digitalWrite(pin::trig_Y, HIGH);
					digitalWrite(pin::trig_G, HIGH);
					digitalWrite(pin::trig_4, LOW);
				}
				if (randomlight == 1)
				{
					digitalWrite(pin::trig_R, HIGH);
					digitalWrite(pin::trig_Y, LOW);
					digitalWrite(pin::trig_G, HIGH);
					digitalWrite(pin::trig_4, LOW);
				}
				if (randomlight == 2)
				{
					digitalWrite(pin::trig_R, HIGH);
					digitalWrite(pin::trig_Y, HIGH);
					digitalWrite(pin::trig_G, LOW);
					digitalWrite(pin::trig_4, LOW);
				}
			}
			count++;
		}

		delay(100);
	}

	set_off();
	delay(100);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	//Button Red pressed
	if (!digitalRead(pin::but_R_sig))
	{
		set_red();
		while (!digitalRead(pin::but_R_sig))
		{
			delay(10);
		}
	}

	//Button Yellow pressed
	if (!digitalRead(pin::but_Y_sig))
	{
		set_yellow();
		while (!digitalRead(pin::but_Y_sig))
		{
			delay(10);
		}
	}

	//Button Green pressed
	if (!digitalRead(pin::but_G_sig))
	{
		set_red();
		while (!digitalRead(pin::but_G_sig))
		{
			delay(10);
		}
	}

	//Button White pressed
	if (!digitalRead(pin::but_W_sig))
	{
		set_off();
		while (!digitalRead(pin::but_W_sig))
		{
			delay(10);
		}
	}

	//Button Blue pressed
	if (!digitalRead(pin::but_B_sig))
	{
		mode_blue();
	}
}
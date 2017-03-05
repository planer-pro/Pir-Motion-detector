#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define pirpin 10

int led;
unsigned long TimeMot = 0;
unsigned long TimeHold = 0;
unsigned long actTime = 0;

void setup()
{
	display.begin( SSD1306_SWITCHCAPVCC, 0x3C);
	display.clearDisplay();

	pinMode (led,OUTPUT);
	pinMode(pirpin,INPUT);

	display.setTextSize(1);
	display.setTextColor( WHITE);

	actTime = millis() + 1000;
}
void loop()
{
	if(digitalRead(pirpin))
	{
		TimeHold = 0;
		display.clearDisplay();
		display.setCursor(25, 30);
		display.println( "MOTION DETECT!");
		if (actTime <= millis())
		{
			actTime = millis() + 1000;
			display.setCursor(60, 45);
			display.println(TimeMot++);
			display.display();
		}
	}
	else
	{
		TimeMot = 0;
		display.clearDisplay();
		display.setCursor(35, 30);
		display.println( "NO MOTION");
		if (actTime <= millis())
		{
			actTime = millis() + 1000;
			display.setCursor(60, 45);
			display.println(TimeHold++);
			display.display();
		}
	}
}
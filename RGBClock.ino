//RGB Clock with Color Table
//by: dan
///www.faultymultimeter.com

#include "Wire.h"
#include "BlinkM_funcs.h"
#include "colortable.h"

//---attenuation values for Green and Blue since these are perceived by the human eye to be brighter than Red
#define GRN_ATTEN 0.2
#define BLUE_ATTEN 0.2
//------

#define FADE_SPEED 2

int SEC_addr = 0x09;
int MIN_addr = 0x0A;
int HR_addr = 0x0B;

float r=0, g=0, b=0;
//float h=0;

int i = 0; //used for RTC

int seconds=0, minutes=0, hours=0;
int prev_sec=0, prev_min=0, prev_hour=0;

static RGB SEC = {0,0,0};
static RGB MIN = {0,0,0};
static RGB HR = {0,0,0};

void setup() {  
  Wire.begin();
//  Serial.begin(9600);  //uncomment for debugging
//  SetClock();          //Set the time in the function below, then uncomment to set time.
                         //Once time is set, comment out this call and re-upload the sketch.
                         
  BlinkM_setFadeSpeed(SEC_addr, FADE_SPEED);  //set speed of color transitions
  BlinkM_setFadeSpeed(MIN_addr, FADE_SPEED);
  BlinkM_setFadeSpeed(HR_addr, FADE_SPEED);
  GetTime();  //read time from RTC
  
  //---do an initial set of the colors for all ghetto pixels---
  SEC = colorMinSec[seconds];
  BlinkM_fadeToRGB(SEC_addr,SEC.r,SEC.g-(SEC.g*GRN_ATTEN),SEC.b-(SEC.b*BLUE_ATTEN));
  MIN = colorMinSec[minutes];
  BlinkM_fadeToRGB(MIN_addr,MIN.r,MIN.g-(MIN.g*GRN_ATTEN),MIN.b-(MIN.b*BLUE_ATTEN));
  HR = color24h[hours];
  BlinkM_fadeToRGB(HR_addr,HR.r,HR.g-(HR.g*GRN_ATTEN),HR.b-(HR.b*BLUE_ATTEN));
  //------
}

//void HSVtoRGB( float red, float green, float blue, float h, float s, float v );

void loop() {
  GetTime();  
//  Serial.print("seconds: ");Serial.println(seconds,DEC);
//  Serial.print(" minutes: ");Serial.println(minutes,DEC);
//  Serial.print(" hours: ");Serial.println(hours,DEC);  
//  Serial.print(" hue: ");Serial.print(h,DEC);
//  Serial.print(" x: ");Serial.println(x,DEC);
//  Serial.print("hue: ");Serial.println(h,DEC);
//  Serial.print("R: ");Serial.print(HR.r,DEC);
//  Serial.print("G: ");Serial.print(HR.g,DEC);
//  Serial.print("B: ");Serial.println(HR.b,DEC);
  if (seconds != prev_sec)
  {
    SEC = colorMinSec[seconds];
    BlinkM_fadeToRGB(SEC_addr,SEC.r,SEC.g-(SEC.g*GRN_ATTEN),SEC.b-(SEC.b*BLUE_ATTEN));
    prev_sec=seconds;
  }
  if (minutes != prev_min)
  {
    MIN = colorMinSec[minutes];
    BlinkM_fadeToRGB(MIN_addr,MIN.r,MIN.g-(MIN.g*GRN_ATTEN),MIN.b-(MIN.b*BLUE_ATTEN));
    prev_min=minutes;
  }
  if (hours != prev_hour)
  {
    HR = color24h[hours];
    BlinkM_fadeToRGB(HR_addr,HR.r,HR.g-(HR.g*GRN_ATTEN),HR.b-(HR.b*BLUE_ATTEN));
    prev_hour=hours;
  }
}

static void GetTime()
{
  Wire.beginTransmission(104); // 104 is DS3231 device address
  Wire.write(i); // start at register 0
  Wire.endTransmission();
  Wire.requestFrom(104, 3); // request three bytes (seconds, minutes, hours)

  while(Wire.available())
  { 
    seconds = Wire.read(); // get seconds
    minutes = Wire.read(); // get minutes
    hours = Wire.read();   // get hours

    seconds = (((seconds & 0b11110000)>>4)*10 + (seconds & 0b00001111)); // convert BCD to decimal
    minutes = (((minutes & 0b11110000)>>4)*10 + (minutes & 0b00001111)); // convert BCD to decimal
    hours = (((hours & 0b00110000)>>4)*10 + (hours & 0b00001111)); // convert BCD to decimal (assume 24 hour mode)
  }
}

void SetClock()
{
  Wire.beginTransmission(104);
  Wire.write(i);
  Wire.write(0x80); //sec
  Wire.write(0x47 + 0x80); //min
  Wire.write(0x17 + 0x80); //hour (24)
  Wire.endTransmission();
}

////Found this at: http://www.cs.rit.edu/~ncs/color/t_convert.html
//void HSVtoRGB( float red, float green, float blue, float h, float s, float v )
//{
//	int i;
//	float f, p, q, t;
//
//	if( s == 0 ) {
//		// achromatic (grey)
//		red = green = blue = v;
//		return;
//	}
//
//	h /= 60;			// sector 0 to 5
//	i = floor( h );
//	f = h - i;			// factorial part of h
//	p = v * ( 1 - s );
//	q = v * ( 1 - s * f );
//	t = v * ( 1 - s * ( 1 - f ) );
//
//	switch( i ) {
//		case 0:
//			red = v;
//			green = t;
//			blue = p;
//			break;
//		case 1:
//			red = q;
//			green = v;
//			blue = p;
//			break;
//		case 2:
//			red = p;
//			green = v;
//			blue = t;
//			break;
//		case 3:
//			red = p;
//			green = q;
//			blue = v;
//			break;
//		case 4:
//			red = t;
//			green = p;
//			blue = v;
//			break;
//		default:		// case 5:
//			red = v;
//			green = p;
//			blue = q;
//			break;
//	}
//        r = red * 255;
//        g = green * 255;
//        b = blue * 255;
//}

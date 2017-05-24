
#include <LCDMenuLib.h>
#include <LCDMenuLib_makros.h>
#include <LCDMenuLib_menu.h>


/*This following program Prints Food Computer's data
 * to the LCD
 * 
 * 
 */
#include <LiquidCrystal_I2C.h> // LCD_i2c library
#include <Wire.h> // I2C communication library DS18B20
//Libraries included to read data from DS
#include <OneWire.h> // One wire communication  
#include <DallasTemperature.h> // Library used to read temperature from DS18B20

#define One_wire_pin 12

// USER DEFINED FUNCTION

/* USER DEFINED FUNCTION 1
 *  Function Name : HTRdataPrint();
 *  What does it do ?
 *      Prints PWM data at the given xPos and yPos  
 *      and also returns the same PWM data.
 *   
 *  Variables parsed : 
 *      1. Pin number for sensor reading ( Analog Pin ! ).
 *      2. xPos and yPos to print the data.
 *  return type : int 
 */

int HTRdataPrint(byte pinNumber ,byte xPos , byte yPos);

/* USER DEFINED FUNCTION 2
 *    Function Name : foodCompBegin();
 *   What does it do ?
 *        Initializes LCD by printing the version and
 *        specific datas required.
 *    MUST BE CALLED IN SETUP function.
 */   

 void foodCompBegin(void);

 ///////////////////////////////////////////////////////////////////////////

//Selected PWM pin for UNO
//Should change when comes to MEGA
const byte heater1PWM_pin = 3;
const byte heater2PWM_pin = 5;

// Constents used for no Delay
unsigned long previousMillis_1=0;
//unsigned long previousMillis_2=0;
unsigned long currentMillis =millis();

// Structure
// at present pwm at pin 3 and 5 are controlled from data at pin A0
struct heaterPWM{
  int heaterPWM_data; // takes PWM data varing from 0 to 255
  char PWMdata[3];    // takes % of PWM data varying from 0 to 100%
}htr[1]; // since 2 heaters are present htr[1] = htr[0] and htr[1] -- array of structures
// User defined functions

// class object
  LiquidCrystal_I2C myLCD(0x27,16,4);
// classes defined for reading temperature from ds 18b20
  OneWire myOneWire ( One_wire_pin );
  DallasTemperature mySensor(&myOneWire);


const byte setEnvTemp = 20; // Max enviroment Temperature (inside box)
const int setHtrTemp = 200; // Max Heater Temperature 
//////////////////////////////////////////////////////////////////
// value should be obtained from sensor !! kept constent for testing purpose
byte curEnvTemp=23;
int curHtr1Temp=190;
int curHtr2Temp=192;
//////////////////////////////////////////////////////////////////
void setup(void) {  
  Serial.begin(9600);
   foodCompBegin();
  pinMode(3,OUTPUT);
  mySensor.begin();
}// close setup

void loop(void) {

   mySensor.requestTemperatures(); // send command to recieve temperature 
 
  Serial.print(HTRdataPrint(A0,2,1));// HTRdataPrint(Pin number , Xpos ,Ypos);
  Serial.print("\t");
  analogWrite(3,htr[0].heaterPWM_data);
  Serial.print(htr[0].PWMdata);
  Serial.print("\t");
  Serial.println(mySensor.getTempCByIndex(0));
  
}// close loop

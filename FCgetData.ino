
int HTRdataPrint(byte pinNumber,byte xPos,byte yPos)
{ 
  int analogData;
  byte constrainedPerc;
  
   //previousMillis_1 = currentMillis;
   analogData= analogRead(pinNumber);
   htr[0].heaterPWM_data = map(analogData,0,1023,0,255);
   constrainedPerc = constrain( map( htr[0].heaterPWM_data,0,255,0,101 ),0,100);  

  
    //byte constrainedPerc = constrain( map( htr[0].heaterPWM_data,0,255,0,101 ),0,100);  
 
  String PWMdata = String(constrainedPerc);
 PWMdata.toCharArray(htr[0].PWMdata,3);
 if(constrainedPerc < 10)
 {
  myLCD.setCursor(xPos,yPos); 
  myLCD.print("0");
  myLCD.setCursor(xPos+1,yPos);
  myLCD.print(htr[0].PWMdata);
  myLCD.setCursor(xPos+2,yPos); 
  myLCD.print("%"); 
 }
 else if( constrainedPerc < 100)
 {
  myLCD.setCursor(xPos,yPos); 
  myLCD.print(htr[0].PWMdata);
  myLCD.setCursor(xPos+2,yPos); 
  myLCD.print("%");
 }// close else
 else 
 {
  myLCD.setCursor(xPos,yPos); 
  myLCD.print(htr[0].PWMdata);
  myLCD.setCursor(xPos+2,yPos); 
  myLCD.print("%");
 }// close else
  return htr[0].heaterPWM_data;
  
}// close HTRdataPrint();



/* LCD data print
{
  
  
  myLCD.print(Voltage);
  Serial.println(Voltage);

  myLCD.setCursor(10,2);
  myLCD.print(curEnvTemp); // should call digital pin to read the DHT's temperature
  myLCD.print("/");
  myLCD.print(curHtr1Temp); // NTC Thermistor value
  myLCD.print("/");
  myLCD.print(curHtr2Temp);  // NTC 2nd Thermistor value

  myLCD.setCursor(6,3);
  myLCD.print("Fan Status-OFF");  // Relay pin
}
*/
/* 
 *  Function Name : HTRdataPrintString_char();
 *  
 *  
  */




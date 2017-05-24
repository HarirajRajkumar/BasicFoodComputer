# BasicFoodComputer
This following ino's are written to display the value on to the 20x4 LCD
read from various INPUT pins of Arduino UNO


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

Syntax  = int HTRdataPrint(byte pinNumber ,byte xPos , byte yPos);

/* USER DEFINED FUNCTION 2
 *    Function Name : foodCompBegin();  // use this to setup
 *   What does it do ?
 *        Initializes LCD by printing the version and
 *        specific datas required.
 *   
 *   No variables is parsed here.
 *    MUST BE CALLED IN SETUP function.
 */   


#include "Arduino.h" // gives you access to the standard types and constants of the Arduino language (this is automatically added to normal sketches, but not to libraries). 
#include "RelayModule.h" // and to the definitions in header file
#include <Wire.h>


RelayModule::RelayModule()
{
PC8574_LCD_Port_Expander_Base_Addess = 39;
}

RelayModule::RelayModule(byte AlternatePort)
{
PC8574_LCD_Port_Expander_Base_Addess = AlternatePort;
}


bool RelayModule::begin()
{
byte returna,returnb = 0;
byte SendCommand = 0;
Wire.begin(); // join i2c bus

SendCommand = 0 ^ B00001000;                                    // Invert Bit 4, leave others untouched
SendCommand = ~SendCommand;                                     // Invert Whole Control Byte für use with 16 Relais Module (Low active)  
Wire.beginTransmission(PC8574_LCD_Port_Expander_Base_Addess);   // transmit to first PC8574 device (Normally at Address #39 DEC) 
                                                                // device address is specified in datasheet                     
Wire.write(SendCommand);                                        // sends value byte  
returna = Wire.endTransmission(true);                           // stop transmitting

SendCommand = 0 ^ B00001000;                                    // Invert Bit 4, leave others untouched
SendCommand = ~SendCommand;                                     // Invert Whole Control Byte für use with 16 Relais Module (Low active)  
Wire.beginTransmission(PC8574_LCD_Port_Expander_Base_Addess -1);   // transmit to first PC8574 device (Normally at Address #39 DEC) 
                                                                // device address is specified in datasheet                     
Wire.write(SendCommand);                                        // sends value byte  
returnb = Wire.endTransmission(true);                           // stop transmitting

if ((returnb == 1) or (returna == 1)) 
    {
    return false;
    } else
    {
    return true;
    }

}


bool RelayModule::write(byte RelaisPort, bool Status)
{
// Do some bit-wise Vodoo - Calculations for PC8574 LCD Port Expander  ;)
byte SendCommand = 0; 
byte BitMask = 0;
byte Return = 0;
if (RelaisPort < 8)  
  {
  BitMask = ( BitMask | (1  << RelaisPort)); 
  if (Status)  
    {
    valPort_A = valPort_A | BitMask;
    } else 
    {
    BitMask = ~BitMask;
    valPort_A = valPort_A & BitMask;
    } 
  SendCommand = valPort_A ^ B00001000;                            // Invert Bit 4, leave others untouched
  SendCommand = ~SendCommand;                                     // Invert Whole Control Byte für use with 16 Relais Module (Low active)  
  Wire.beginTransmission(PC8574_LCD_Port_Expander_Base_Addess);   // transmit to first PC8574 device (Normally at Address #39 DEC) 
                                                                  // device address is specified in datasheet                     
  Wire.write(SendCommand);                                        // sends value byte  
  Return = Wire.endTransmission(true);                            // stop transmitting
  if (Return == 0)
    {
    return true;
    } else
    {
    return false;
    }
    } 
else if (RelaisPort < 16)                                         // High Port Selected
  {
  RelaisPort = RelaisPort - 8;
  BitMask = ( BitMask | (1  << RelaisPort)); 
  if (Status)  
    {
    valPort_B = valPort_B | BitMask;
    } else 
    {
    BitMask = ~BitMask;
    valPort_B = valPort_B & BitMask;
    } 
  SendCommand = valPort_B ^ B00001000;                            // Invert Bit 4, leave others untouched
  SendCommand = ~SendCommand;                                     // Invert Whole Control Byte für use with 16 Relais Module (Low active)  
  Wire.beginTransmission(PC8574_LCD_Port_Expander_Base_Addess - 1); // transmit to first PC8574 device (Normally at Address #39 DEC) 
                                                                  // device address is specified in datasheet                     
  Wire.write(SendCommand);                                        // sends value byte  
  Return = Wire.endTransmission(true);                            // stop transmitting
  if (Return == 0)
    {
    return true;
    } else
    {
    return false;
    }
  } 
else
  {
  return false;                                                   // Out of Rage
  } 
}

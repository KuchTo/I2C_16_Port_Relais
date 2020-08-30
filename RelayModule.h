#ifndef RelayModule_h // this prevents problems if someone accidently #include's your library twice. 
#define RelayModule_h

#include <Wire.h>

#define JD1 0
#define JD2 1
#define JD3 2
#define JD4 3
#define JD5 4
#define JD6 5
#define JD7 6
#define JD8 7

#define JD9 8
#define JD10 9
#define JD11 10
#define JD12 11
#define JD13 12
#define JD14 13
#define JD15 14
#define JD16 15



class RelayModule {
   public:
   RelayModule();
   RelayModule(byte AlternatePort);
   bool begin();
   bool write(byte RelaisPort, bool Status);
   private:
   byte PC8574_LCD_Port_Expander_Base_Addess = 0;
   volatile byte valPort_A = 0;
   volatile byte valPort_B = 0; 
};

#endif
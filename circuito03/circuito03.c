#include<16F887.h>
#device ADC = 10 //tama�o de bits de resolucion (valores adimencioanles que obtienen un muestreo de una se�al digital)
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOLVP, NOBROWNOUT
#use delay(INTERNAL=4000000)

// se definen las macros simpre antes de llamar a la biblioteca debido a las directivas del lenguaje
// basicamente es establecer como se conectara la lcd con el micro
#define LCD_DATA_PORT getenv("SFR:PORTD")

#include <lcd.c>

#define constanteV 0.0048
#define constanteG 0.26

void main(){

   int16 iAdc ; //  variable que captura el valor adimencional recibido desde el port analogico
   float voltaje;
   float grados;
   
   lcd_init();
   setup_adc_ports(sAN0); // se confitgura el puerto que servira como analogico
   setup_adc(ADC_CLOCK_INTERNAL);
   lcd_putc("\fReady...\n");
   delay_ms(2000);
   
   while(TRUE){
      
      
      iAdc = read_adc(); // asocia el valor leido desde el puerto adc a la variable previamente definida   
      voltaje = iAdc * constanteV;
      grados = iAdc * constanteG;
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Vol=%.2f v", voltaje);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"grad=%.2f%c ", grados,223);
      delay_ms(500);
   }
}

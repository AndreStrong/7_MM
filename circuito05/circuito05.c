#include<16F887.h>
#device ADC = 8//tama�o de bits de resolucion (valores adimencioanles que obtienen un muestreo de una se�al digital)
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOLVP, NOBROWNOUT
#use delay(INTERNAL=4000000)

// se definen las macros simpre antes de llamar a la biblioteca debido a las directivas del lenguaje
// basicamente es establecer como se conectara la lcd con el micro
#define LCD_DATA_PORT getenv("SFR:PORTD")

#include <lcd.c>


void main(){

   int8 iAdc; //  variable que captura el valor adimencional recibido desde el port analogico
   setup_ccp1(CCP_PWM); // se configura el pin ccp1 como PWD
   setup_timer_2(T2_DIV_BY_16, 255,1);
   set_pwm1_duty(0); // se pone el ciclo de trabajo en 0 para su inicializacion (0%)
   
   
   lcd_init();
   setup_adc_ports(sAN0); // se confitgura el puerto que servira como analogico
   setup_adc(ADC_CLOCK_INTERNAL);
   //codigo para comprobar un funcionamiento previo al circuito
   lcd_putc("\fReady...\n");
   delay_ms(2000);
   // basicamente le da el giro al motor
   output_high(PIN_C0);
   output_low(PIN_C1);
   
   
   while(TRUE){
      
      set_adc_channel(0); //configura el AN0 como entrada analogica
      delay_ms(10);
      iAdc = read_adc(); // asocia el valor leido desde el puerto adc a la variable previamente definida  
            
       
      printf(lcd_putc, "\f");
      
      
      if(iAdc == 127){
         output_low(PIN_C4);
         output_low(PIN_C5);
         set_pwm1_duty(0);
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Reposo");
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Vel=0");
      }
      else if(iAdc > 127){
         output_high(PIN_C4);
         output_low(PIN_C5);
         set_pwm1_duty(((iAdc-127)*2)-1);
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Derecha");
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Vel=%u",((iAdc-127)*2)-1);
      }
      else{
         output_low(PIN_C4);
         output_high(PIN_C5);
         set_pwm1_duty(((127-iAdc)*2));
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Izquierda");
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Vel=%u",((127-iAdc)*2));
      }
      
           
      
      delay_ms(100);
   }
}

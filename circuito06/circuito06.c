#include<16F887.h>
#device ADC = 10//tama�o de bits de resolucion
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOLVP, NOBROWNOUT
#use delay(INTERNAL=4000000)
// se inicializa el puerto serie en el microcontrolador
#use RS232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7, timeout = 100) 
//argumentos PS(ancho de banda (Tx bits/s), pin Tx, pin Rx, tiempo de respuesta)
 
// se define el puerto D completo para la conexion al LCD
#define LCD_DATA_PORT getenv("SFR:PORTD")
// se define el uso de la biblioteca para manipular LCD
#include <lcd.c>

//comienzo del programa
//El programa muestra los meses del a�o
//A traves del ADC (10 bits) se estableceran rangos para cada mes de la siguiente manera
// Enero 0-84
// Febrero 85-169
// Marzo 170-254
// Abril 255-339
// Mayo 340-424
// Junio 425-509
// Julio 510-594
// Agosto 595-679
// Septiembre 680-764
// Octubre 765-849
// Noviembre 850-934
// Diciembre 935-1024
// El alcance del programa puede ser para llevar por ejemplo un diario escrito
// Se puede establecer un calendario, y que cada dia el usuario a una determinada hora
// Anote sus observaciones del dia, su estado de animo etc
// Es una aplicacion muy sencilla, pero el hecho de tener un dispositivo especializado en ello
// Puede ser estimulante para realizar una determinada accion

void main(){
   //Variable donde se almacenara el valor del PWM
   int16 iAdc;
   // se inicializa la funcion del LCD
   lcd_init(); 
   
   //Se define el puerto ADC
   setup_adc_ports(sAN0);
   //Se establece el reloj interno del ADC
   setup_adc(ADC_CLOCK_INTERNAL);
   //Imprimir mensaje de preparacion en la LCD
   lcd_putc("\fReady...\n");
   delay_ms(2000);
   //Comienzo del programa
   while(TRUE){
      // se establece ADC canal
      set_adc_channel(0);
      delay_ms(10);
      //lectura del adc
      iAdc = read_adc();
      
      //Limpiar la pantalla
      printf(lcd_putc, "\f");
      //lectura adc impresa
      lcd_gotoxy(1,1);
      printf(lcd_putc, "ADC=%Lu", iAdc);
      printf("Valor del ADC = %Lu\n\r", iAdc);
      if(iAdc >= 0 && iAdc <= 84){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Enero");
         printf("Es el mes de ENERO \n\r");
      }else if(iAdc >= 85 && iAdc <= 169){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Febrero");
         printf("Es el mes de FEBRERO \n\r");
      }else if(iAdc >= 170 && iAdc <= 254){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Marzo");
         printf("Es el mes de MARZO \n\r");
      }else if(iAdc >= 255 && iAdc <= 339){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Abril");
         printf("Es el mes de ABRIL \n\r");
      }else if(iAdc >= 340 && iAdc <= 424){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Mayo"); 
         printf("Es el mes de MAYO \n\r");
      }else if(iAdc >=425 && iAdc <= 509){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Junio"); 
         printf("Es el mes de JUNIO \n\r");
      }else if(iAdc >=510 && iAdc <= 594){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Julio"); 
         printf("Es el mes de JULIO \n\r");
      }else if(iAdc >=595 && iAdc <= 679){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Agosto");
         printf("Es el mes de AGOSTO \n\r");
      }else if(iAdc >=680 && iAdc <= 764){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Septiembre"); 
         printf("Es el mes de SEPTIEMBRE \n\r");
      }else if(iAdc >=765 && iAdc <= 849){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Octubre"); 
         printf("Es el mes de OCTUBRE \n\r");
      }else if(iAdc >=850 && iAdc <= 934){
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Noviembre"); 
         printf("Es el mes de NOVIEMBRE \n\r");
      }else{
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Diciembre"); 
         printf("Es el mes de DICIEMBRE \n\r");
      }
      
      
      delay_ms(100);
   }
}

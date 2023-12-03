#include<16F887.h>
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOLVP, NOBROWNOUT
#use delay(INTERNAL=4000000)
// se inicializa el puerto serie en el microcontrolador
#use RS232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7, timeout = 100) 
//argumentos PS(ancho de banda (Tx bits/s), pin Tx, pin Rx, tiempo de respuesta)
 //Sensores
#define DHT11_PIN PIN_A0
#define spuerta PIN_A1
// se define el puerto D completo para la conexion al LCD
#define LCD_DATA_PORT getenv("SFR:PORTD")
// se define el uso de la biblioteca para manipular LCD
#include <lcd.c>
#include<DHT11.c>
//Consntantes de conversion
#define faCentigrados 0.55555555555555555555555555

void main(){
   //Variable donde se almacenara el valor del ADC de los sensores de peruta y temperatura respectivamente
   int puerta = 0, data_ok = 0;
   float temperatura,centigrados, humedad;
   char modo;
   
   // variable para salir de un modo
   char salir;
   // se inicializa la funcion del LCD
   lcd_init(); 
   
   
   //Imprimir mensaje de preparacion en la LCD
   lcd_putc("\fReady...\n");
   delay_ms(2000);
   //Comienzo del programa
   while(TRUE)
   {     
      //Limpiar la LCD
      printf(lcd_putc, "\f");
      
      //Solicitud de Modo de trabajo
      while(true)
      {
         printf(lcd_putc,"\f");
         printf("\n\r");
         //apagar los actuadores
         //ventilador      
         output_low(PIN_C1);
         output_low(PIN_C2);
         puerta = 0;
         //led de advertencia
         output_low(PIN_C0);
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Seleccion modo");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"a:Auto | b:Man");
         //ingreso de modo de trabajo
         modo = getch();
         if(modo == 'a' || modo == 'b'){
            break;
         }
         
         delay_ms(500);
      }
      
      //En caso de modo A: ADC
      switch(modo){
         case 'a':
         {
            
            while(true)
            {
               //lectura de temperatura
               data_ok = DHT11_read_data(&temperatura,&humedad);
               //lectura de puerta
               puerta = input(spuerta);
               //Imprimir en LCD
               printf(lcd_putc, "\f");
               lcd_gotoxy(1,1);
               printf(lcd_putc, "m:Auto");
               if(puerta == 0){
                  lcd_gotoxy(8,1);
                  printf(lcd_putc, "Pue:Clo\n\r");
               }else{
                  lcd_gotoxy(8,1);
                  printf(lcd_putc, "Pue:Ope");
               }
               //Lectura de temperatura
               if(data_ok == 1)
               {
                  //calculo de grados centigrados
                  centigrados = (temperatura - 32)*faCentigrados;
                  //salidas
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "T: %.1f %CC", centigrados, 223);
                  // calculos de temperatura
                  if (centigrados >= 15 && centigrados <= 30 && puerta == 1) {
                     //ventilador      
                     output_high(PIN_C1);
                     output_low(PIN_C2);
                     lcd_gotoxy(12,2);
                     printf(lcd_putc, "V:ON");
                     //Imprimir en puerto serie
                     printf("Temperatura (C): %.1f %c   |   Puerta: %u   |   Ventilador: ON\n\r",centigrados ,223, puerta);
                     //led de advertencia
                     output_low(PIN_C0);
                  } else if (centigrados > 30 && puerta == 1) {
                     //ventilador      
                     output_high(PIN_C1);
                     output_low(PIN_C2);
                     lcd_gotoxy(12,2);
                     printf(lcd_putc, "V:ON");
                     //Imprimir en puerto serie
                     printf("Temperatura (C): %.1f %c(Precaucion)|Puerta: %u|Ventilador: ON\n\r",centigrados ,223, puerta);
                     //led de advertencia
                     output_high(PIN_C0);
                  } else {
                     //ventilador      
                     output_low(PIN_C1);
                     output_low(PIN_C2);
                     lcd_gotoxy(12,2);
                     printf(lcd_putc, "V:OFF");
                     //Imprimir en puerto serie
                     printf("Temperatura (C): %.1f %c   |   Puerta: %u   |   Ventilador: OFF\n\r",centigrados ,223, puerta);
                     //led de advertencia
                     output_low(PIN_C0);
                     }
               }else{
                  //salidas
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "T:NA");
                  printf("DESCONECTADO\n\r");
               }
      
               // se reinicia spuerta
               puerta = 0;
               //se solicita confirmacion para salir
               salir = getch();
               if(salir == 's') 
               {
                  break;
               }
             
               delay_ms(1500);
            }
       
            
         }
         
         if(salir == 's') {
                  break;
         }
         
         case 'b':
         {
            while(true)
            {
               //repetir lo siguente
               //apagar actuadores
                     output_high(PIN_C1);
                     output_low(PIN_C2);
                     //led
                     output_high(PIN_C0);
               
               while(true)
               {
                  //Normalmente apagado
                  
                  //lectura de temperatura
                  data_ok = DHT11_read_data(&temperatura,&humedad);
                  //lectura de puerta
                  puerta = input(spuerta);
                  //Imprimir en LCD
                  printf(lcd_putc, "\f");
                  lcd_gotoxy(1,1);
                  printf(lcd_putc, "m:Manu");
                  
                  if(data_ok == 1)
                  {
                     //calculo de grados centigrados
                     centigrados = (temperatura - 32)*faCentigrados;
                     //salidas
                     lcd_gotoxy(1,2);
                     printf(lcd_putc, "T: %.1f %CC", centigrados, 223);
                     printf("Temperatura (C): %.1f %c   |   Puerta: %u   |   Ventilador: OFF\n\r",centigrados ,223, puerta);
                     //ventilador
                     output_low(PIN_C1);
                     output_low(PIN_C2);
                     lcd_gotoxy(12,2);
                     printf(lcd_putc, "V:OFF");
                     //led
                     output_high(PIN_C0);
                     
                     
                  }else{
                     //salidas
                     lcd_gotoxy(1,2);
                     printf(lcd_putc, "T:NA");
                     printf("DESCONECTADO\n\r");
                  }
                  
                  //encender o salir
                  salir = getch();
                  if(salir == 'c' || salir == 's')
                  {
                     break;
                  }
                  delay_ms(1500);
                  
               }
               if(salir == 's'){
                  break;
               }
               while(true)
               {
                  
                  
                  
                  //Normalmente encendido
                  
                  //lectura de temperatura
                  data_ok = DHT11_read_data(&temperatura,&humedad);
                  //lectura de puerta
                  puerta = input(spuerta);
                  //Imprimir en LCD
                  printf(lcd_putc, "\f");
                  lcd_gotoxy(1,1);
                  printf(lcd_putc, "m:Manu");
                  
                  if(data_ok == 1)
                  {
                     //calculo de grados centigrados
                     centigrados = (temperatura - 32)*faCentigrados;
                     //salidas
                     lcd_gotoxy(1,2);
                     printf(lcd_putc, "T: %.1f %CC", centigrados, 223);
                     printf("Temperatura (C): %.1f %c   |   Puerta: %u   |   Ventilador: ON\n\r",centigrados ,223, puerta);
                     //ventilador
                     output_high(PIN_C1);
                     output_low(PIN_C2);
                     //led
                     output_high(PIN_C0);
                     lcd_gotoxy(12,2);
                     printf(lcd_putc, "V:ON");
                     
                     
                  }else{
                     //salidas
                     lcd_gotoxy(1,2);
                     printf(lcd_putc, "T:NA");
                     printf("DESCONECTADO\n\r");
                  }
                  
                  
                  
                  
                  
                  //apagar o salir
                  salir = getch();
                  if(salir == 'c' || salir == 's')
                  {
                     break;
                  }
                  delay_ms(1500);
               }
               if(salir == 's'){
                  break;
               }
               
            }
               
            
                     
         
         
         }
               
      }
      
      
     
      
      
     
   }
}

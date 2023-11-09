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
   // se declaran los meses del anio
   char nuMes;
  // se declara variable para modo de trabajo
   char modo;
   // variable para salir de un modo
   char salir;
   // variable para solicitar nuevo mes en modo b
   char nuevoMes;
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
      
      
      //Limpiar la LCD
      printf(lcd_putc, "\f");
      //Apagar los leds en caso de que esten encendidos
      output_low(PIN_C4);
      output_low(PIN_C5);
      //Primer solicitud de Modo de trabajo
      //Imprimir en monitor serie
      printf("Ingrese un modo de trabajo: \n\r");
      printf("A: ADC\n\r");
      printf("B: Manual (Monitor serie)\n\r");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Seleccion modo");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"A:ADC/B:MANUAL");
      //ingreso de modo de trabajo
           
      //se pone un delay para esperar la respuesta del usuario
      //comprobar que se establesca un modo valido
      while(true){
         
         printf("Ingrese un modo de trabajo: \n\r");
         printf("A: ADC\n\r");
         printf("B: Manual (Monitor serie)\n\r");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Seleccion modo");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"A:ADC//B:MANUAL");
         //ingreso de modo de trabajo
         modo = getch();
         printf("Valor ingresado: %c\n\r", modo);
         if(modo == 'a' || modo == 'b'){
            break;
         }
         
         delay_ms(1000);
      }
      
      //En caso de modo A: ADC
      switch(modo){
         case 'a':
         {
            
            while(true){
               //limpiar pantalla
               printf(lcd_putc, "\f");
               //lestura adc
               iAdc = read_adc();
               
               //lectura adc impresa
               //imprimir en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Modo A: ADC=%Lu", iAdc);
               //imprimir en monitor serie
               printf("Modo de trabajo A: ADC\n\r");
               printf("Valor del ADC = %Lu\n\r", iAdc);
               if(iAdc >= 0 && iAdc <= 84){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Enero");
                  printf("Es el mes de ENERO \n\r");
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else if(iAdc >= 85 && iAdc <= 169){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Febrero");
                  printf("Es el mes de FEBRERO \n\r");
                  //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }else if(iAdc >= 170 && iAdc <= 254){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Marzo");
                  printf("Es el mes de MARZO \n\r");
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else if(iAdc >= 255 && iAdc <= 339){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Abril");
                  printf("Es el mes de ABRIL \n\r");
                   //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }else if(iAdc >= 340 && iAdc <= 424){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Mayo"); 
                  printf("Es el mes de MAYO \n\r");
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else if(iAdc >=425 && iAdc <= 509){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Junio"); 
                  printf("Es el mes de JUNIO \n\r");
                   //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }else if(iAdc >=510 && iAdc <= 594){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Julio"); 
                  printf("Es el mes de JULIO \n\r");   
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else if(iAdc >=595 && iAdc <= 679){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Agosto");
                  printf("Es el mes de AGOSTO \n\r");
                  //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }else if(iAdc >=680 && iAdc <= 764){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Septiembre"); 
                  printf("Es el mes de SEPTIEMBRE \n\r");
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else if(iAdc >=765 && iAdc <= 849){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Octubre"); 
                  printf("Es el mes de OCTUBRE \n\r");
                  //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }else if(iAdc >=850 && iAdc <= 934){
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Noviembre"); 
                  printf("Es el mes de NOVIEMBRE \n\r");
                  //actuador impar
                  output_low(PIN_C4);
                  output_high(PIN_C5);
               }else{
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Diciembre"); 
                  printf("Es el mes de DICIEMBRE \n\r");
                  //actuador par
                  output_high(PIN_C4);
                  output_low(PIN_C5);
               }
      
      
               delay_ms(1000);
               
               //se solicita confirmacion para salir
               printf("Ingrese s para salir \n\r");
               salir = getch();
               if(salir == 's') {
                  break;
               }
             
               
            }
       
            
         }
         
         if(salir == 's') {
                  break;
         }
         
         case 'b':
         {
            while(true){
            //salir de esta opcion
               
               
               
               //limpiar lcd
               printf(lcd_putc,"\f");
               //se solicita confirmacion para salir
                              
               //Imprimir en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Modo B: Manual");
               //imprimir en monitor serie
               printf("Modo de trabajo B: Manual\n\r");
               
               
    
               //Se detecta mes invalido
               while(true){
                  //solicitar mes
                  printf("Ingrese un mes 1-12\n\r");
                  nuMes = getch();               
                  nuMes = nuMes - '0';
                  if((nuMes >= 1 && nuMes <= 9)){
                     break;
                  }else if(nuMes == 'a' || nuMes == 'b' || nuMes == 'c'){
                     nuMes = (char)nuMes;
                     break;
                  }
                  delay_ms(1000);
                  
               }
               
               // se detecta mes valido
               while(true){
                  
                  
                  printf("Su mes elegido es: %c\n\r", nuMes);
                  if(nuMes == 1){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Enero");
                     printf("Es el mes de ENERO \n\r");
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);
                  
                  }else if(nuMes == 2){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Febrero");
                     printf("Es el mes de FEBRERO \n\r");
                     //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);
                  
                  }else if(nuMes == 3){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Marzo");
                     printf("Es el mes de MARZO \n\r");
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);
                  
                  }else if(nuMes == 4){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Abril");
                     printf("Es el mes de ABRIL \n\r");
                      //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);
                  }else if(nuMes == 5){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Mayo"); 
                     printf("Es el mes de MAYO \n\r");
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);
                  }else if(nuMes == 6){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Junio"); 
                     printf("Es el mes de JUNIO \n\r");
                      //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);

                  }else if(nuMes == 7){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Julio"); 
                     printf("Es el mes de JULIO \n\r");   
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);

                  }else if(nuMes == 8){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Agosto");
                     printf("Es el mes de AGOSTO \n\r");
                     //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);
                  }else if(nuMes == 9){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Septiembre"); 
                     printf("Es el mes de SEPTIEMBRE \n\r");
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);
                  
                  }else if(nuMes == 'a'){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Octubre"); 
                     printf("Es el mes de OCTUBRE \n\r");
                     //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);
                  
                  }else if(nuMes == 'b'){
                      lcd_gotoxy(1,2);
                     printf(lcd_putc,"Noviembre"); 
                     printf("Es el mes de NOVIEMBRE \n\r");
                     //actuador impar
                     output_low(PIN_C4);
                     output_high(PIN_C5);
                 }else if(nuMes == 'c'){
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Diciembre"); 
                     printf("Es el mes de DICIEMBRE \n\r");
                     //actuador par
                     output_high(PIN_C4);
                     output_low(PIN_C5);
                  }
               
                  delay_ms(500);
               
                  printf("Desea agregar un nuevo mes? (s/n)\n\r");          
                  nuevoMes = getch();
                  if(nuevoMes == 's' || nuevoMes == 'n'){
                     break;
                  }
                  output_low(PIN_C4);
                  output_low(PIN_C5);
                  delay_ms(1000);
                              

             
               }
               
               if (nuevoMes == 'n'){
                  break;
               }
               
               
               
                
               
               
               
            }
         
         
         }
               
      }
      
      
     
      
      
     
   }
}

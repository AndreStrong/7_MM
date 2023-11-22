#include<16F887.h>
#device ADC = 8//tamaño de bits de resolucion
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOLVP, NOBROWNOUT
#use delay(INTERNAL=4000000)
// se inicializa el puerto serie en el microcontrolador
#use RS232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7, timeout = 100) 
//argumentos PS(ancho de banda (Tx bits/s), pin Tx, pin Rx, tiempo de respuesta)
 
// se define el puerto D completo para la conexion al LCD
#define LCD_DATA_PORT getenv("SFR:PORTD")
// se define el uso de la biblioteca para manipular LCD
#include <lcd.c>
//Consntantes de conversion
#define angulo 0.3571428571
#define aceleracion 0.79365079365079


void main(){
   //Variable donde se almacenara el valor del ADC giro
   int8 iAdcGiro;
   int8 iAdcAceleracion;
   //variables para realizar conversiones
   float cGrados;
   float cPWM;
   //variables para la modulacion del PWM
   int8 valor_pwm_der;
   int8 valor_pwm_izq;
   //variable para el control semiautomatico
   char giro;
   char marcha;
   //configuraciones del pwm
   setup_ccp1(CCP_PWM); // se configura el pin ccp1 como PWD
   setup_timer_2(T2_DIV_BY_16, 255,1);
   set_pwm1_duty(0); // se pone el ciclo de trabajo en 0 para su inicializacion (0%)
  // se declara variable para modo de trabajo
   char modo;
   // variable para salir de un modo
   char salir;
   // se inicializa la funcion del LCD
   lcd_init(); 
   
   
   //Se definen los puertos ADC
   setup_adc_ports(sAN0 | sAN1);  
   //Se establece el reloj interno del ADC
   setup_adc(ADC_CLOCK_INTERNAL);
   //Imprimir mensaje de preparacion en la LCD
   lcd_putc("\fReady...\n");
   delay_ms(2000);
   //Comienzo del programa
   while(TRUE)
   {     
      //Limpiar la LCD
      printf(lcd_putc, "\f");
      
      //Primer solicitud de Modo de trabajo
      while(true)
      {
         printf(lcd_putc,"\f");
         
         //apagar los actuadores
               
         output_low(PIN_C4);
         output_low(PIN_C5);
         set_pwm1_duty(0);
               
         output_low(PIN_C0);
         output_low(PIN_C1);
         
         printf("Ingrese un modo de trabajo: \n\r");
         printf("a: Manual\n\r");
         printf("b: Semiautomatico (Monitor serie)\n\r");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Seleccion modo");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"a:Manu | b:Semi");
         //ingreso de modo de trabajo
         modo = getch();
         printf("Valor ingresado: %c\n\r", modo);
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
               //Lectura de los sensores
               set_adc_channel(0);
               delay_ms(10);
               iAdcGiro = read_adc();
               set_adc_channel(1);
               delay_ms(10);
               iAdcAceleracion = read_adc();
               
               //limpiar pantalla
               printf(lcd_putc, "\f");
               
             
               
                
               
               //imprimir en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "M:Ma");
               //imprimir en monitor serie
               printf("Modo de trabajo a: Manual\n\r");
               printf("Lectura S1: %u\n\r", iAdcGiro);
               printf("Lectura S1: %u\n\r", iAdcAceleracion);
               //Validar giro
               if(iAdcGiro == 127 || iAdcGiro == 128 || iAdcGiro == 129)
               {
                  //Imprimir direccion de giro
                  lcd_gotoxy(6,1);
                  printf(lcd_putc, "D:Ce");
                  lcd_gotoxy(11,1);
                  printf(lcd_putc, "%.2f%c", 0.00,223);
                  //Imprimir en puerto serie
                  printf("S1: %u\n\r", iAdcGiro);
                  printf("Direccion: Centro\n\r");
                  printf("Grados: %.2f%c", 0.00,223);
                  //actuadores
                  output_high(PIN_C0);
                  output_high(PIN_C1);
                  
                  
               }else if(iAdcGiro > 129)
               {
                  
                  //Imprimir direccion de giro
                  lcd_gotoxy(6,1);
                  printf(lcd_putc, "D:De");
                  //conversion
                  cGrados = (iAdcGiro - 126) * angulo ;
                  lcd_gotoxy(11,1);
                  printf(lcd_putc, "%.2f%c", cGrados,223);
                  //Imprimir en puerto serie
                  printf("S1: %u\n\r", iAdcGiro);
                  printf("Direccion: Derecha\n\r");
                  printf("Grados: %.2f%c\n\r", cGrados,223);
                  //actuadores
                  output_low(PIN_C0);
                  output_high(PIN_C1);
                  
               }else
               {

                  //Imprimir direccion de giro
                  lcd_gotoxy(6,1);
                  printf(lcd_putc, "D:Iz");
                  //conversion
                  cGrados = (126 - iAdcGiro) * angulo ;
                  lcd_gotoxy(11,1);
                  printf(lcd_putc, "%.2f%c", cGrados,223);
                  //Imprimir en puerto serie
                  printf("S1: %u\n\r", iAdcGiro);
                  printf("Direccion: Izquierda\n\r");
                  printf("Grados: %.2f%c\n\r", cGrados,223);
                  //actuadores
                  output_high(PIN_C0);
                  output_low(PIN_C1);
               }
               
               
               //validar aceleracion
               if(iAdcAceleracion == 127 || iAdcAceleracion == 128 || iAdcAceleracion == 129)
               {
                  //no se limpia pantalla pues se debe de visualizar la info del if anterior
                  //Imprimir direccion de giro
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "Rep V:%.2f%%",0.00);
                  //Imprimir en puerto serie
                  printf("S2: %u\n\r", iAdcAceleracion);
                  printf("Estado: Reposo\n\r");
                  printf("Velocidad: %.2f%%", 0.00);
                  //actuadores
                  output_low(PIN_C4);
                  output_low(PIN_C5);
                  set_pwm1_duty(0);
                  
               }
               else if(iAdcAceleracion > 129)
               {
                  //conversion
                  cPWM = (iAdcAceleracion - 126) * aceleracion;
                  //Imprimir
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "Mar V:%.2f%%",cPWM);
                  //Imprimir en puerto serie
                  printf("S2: %u\n\r", iAdcAceleracion);
                  printf("Estado: Marcha\n\r");
                  printf("Velocidad: %.2f%%", 0.00);
                  //actuadores
                  output_high(PIN_C4);
                  output_low(PIN_C5);
                  valor_pwm_der = ((iAdcAceleracion-126)*2);
                  set_pwm1_duty(valor_pwm_der);
               }else
               {
                  //conversion
                  cPWM = (126 - iAdcAceleracion) * aceleracion;
                  //Imprimir direccion de giro
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "Rev V:%.2f%%",cPWM);
                  //Imprimir en puerto serie
                  printf("S2: %u\n\r", iAdcAceleracion);
                  printf("Estado: Reversa\n\r");
                  printf("Velocidad: %.2f%%", 0.00);
                  //actuadores
                  output_low(PIN_C4);
                  output_high(PIN_C5);
                  valor_pwm_izq = (126-iAdcAceleracion)*2;
                  set_pwm1_duty(valor_pwm_izq);
                  
               }
               
               delay_ms(10);
               
               //se solicita confirmacion para salir
               printf("Ingrese s para salir \n\r");
               salir = getch();
               if(salir == 's') 
               {
                  break;
               }
             
               delay_ms(10);  
            }
       
            
         }
         
         if(salir == 's') {
                  break;
         }
         
         case 'b':
         {
            while(true)
            {
               //leer una entrada
               set_adc_channel(1);
               delay_ms(10);
               iAdcAceleracion = read_adc();
                                            
               //limpiar lcd
               printf(lcd_putc,"\f");
               //se solicita confirmacion para salir
                             
               //Imprimir en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "M:Automatico");
               //imprimir en monitor serie
               printf("Modo de trabajo b: Automatico\n\r");
               // manter marcha o no
               if(iAdcAceleracion > 129)
               {
                  //imprimir en LCD detener
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "Detener");
                  //imrpirmir en monitor serie
                  printf("Denido: Hay un obstaculo");
                  //actuadores
                  set_pwm1_duty(0);
                  output_low(PIN_C0);
                  output_low(PIN_C1);
                  
               }else{
                  //imprimir en LCD avanzar
                  lcd_gotoxy(1,2);
                  printf(lcd_putc, "Avanzar");
                  //imprimir en monitor serie
                  printf("Avanzando");
                  //actuadores
                  set_pwm1_duty(200);
                  output_high(PIN_C0);
                  output_high(PIN_C1);
                  
               }
               delay_ms(100);
               //se solicita confirmacion para salir
               printf("Ingrese s para salir \n\r");
               salir = getch();
               if(salir == 's') 
               {
                  break;
               }
               
               delay_ms(100);
                                 
            }
         
         
         }
               
      }
      
      
     
      
      
     
   }
}

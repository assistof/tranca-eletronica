#include<18f4550.h>
#include <lcd.h>
#use delay(crystal=4MHZ)
#fuses nowdt,xt
#byte PORTB=0xf81
#byte PORTD=0xf83
int i = 0;
int j = 0;

#define B   PIN_B3
#define T   PIN_B2
#define C3  PIN_D0
#define C2  PIN_D5
#define C1  PIN_D6
#define L1  PIN_D1
#define L2  PIN_D2
#define L3  PIN_D3
#define L4  PIN_D4




void scan1(){            // Faz primeira varredura

   int aux=100;           // ,Serve para ser a condição do while
   while(aux != 0)       // Loop para varre as colunas do teclado
   {
      output_low(L1);    // Implementa 0 na coluna a ser verificada,primeira linha da matriz
      output_high(L2);
      output_high(L3);
      output_high(L4);

      if(input(C1) == 0)     // Varre primeira coluna
      {
         i = 3;
         j ++;
         delay_ms(20);   // Tempo para soltar tecla
                         
      }

      if(input(C2) == 0)     // Varre segunda coluna
      {
         i = 2;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      if(input(C3) == 0)     // Varre terceira coluna
      {
         i = 1;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      aux--;             // Decrementa 1 de aux
      delay_us(aux);     
   }

      output_high(L1);
      output_high(L2);
      output_high(L3);
      output_high(L4);

   return;               // Retorna ao main
}                        



//________________________________________________________________________________



void scan2(){            // Faz segunda varredura

   int aux=100;          // ,Serve para ser a condição do while
   while(aux != 0)       // Loop para varre as colunas do teclado
   {
      output_high(L1);    // Implementa 0 na coluna a ser verificada,segunda linha da matriz
      output_low(L2);
      output_high(L3);
      output_high(L4);

      if(input(C1) == 0)     // Varre primeira coluna
      {
         i = 6;
         j ++;
         delay_ms(20);   // Tempo para soltar tecla
                         
      }

      if(input(C2) == 0)     // Varre segunda coluna
      {
         i = 5;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      if(input(C3) == 0)     // Varre terceira coluna
      {
         i = 4;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      aux--;             // Decrementa 1 de aux
      delay_us(aux);     
   }

      output_high(L1);
      output_high(L2);
      output_high(L3);
      output_high(L4);

   return;               // // Retorna ao main
}                        



//________________________________________________________________________________



void scan3(){            // Faz primeira varredura

   int aux=100;          // ,Serve para ser a condição do while
   while(aux != 0)       // Loop para varre as colunas do teclado
   {
      output_high(L1);    // Implementa 0 na coluna a ser verificada,terceira linha da matriz
      output_high(L2);
      output_low(L3);
      output_high(L4);

      if(input(C1) == 0)     // Varre primeira coluna
      {
         i = 9;
         j ++;
         delay_ms(20);   // Tempo para soltar tecla
                         
      }

      if(input(C2) == 0)     // Varre segunda coluna
      {
         i = 8;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      if(input(C3) == 0)     // Varre terceira coluna
      {
         i = 7;
         j ++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      aux--;             // Decrementa 1 de aux
      delay_us(aux);     
   }

      output_high(L1);
      output_high(L2);
      output_high(L3);
      output_high(L4);

   return;              // Retorna ao main
}                        



//________________________________________________________________________________


void scan4(){            // Faz primeira varredura

   int aux=100;           // ,Serve para ser a condição do while
   while(aux != 0)       // Loop para varre as colunas do teclado
   {
      output_high(L1);    // Implementa 0 na coluna a ser verificada,quarta linha da matriz
      output_high(L2);
      output_high(L3);
      output_low(L4);

      if(input(C1) == 0)     // Varre primeira coluna
      {
         
                                   
         
         delay_ms(20);   // Tempo para soltar tecla
          break;//Não faz nada
      }

      if(input(C2) == 0)     // Varre segunda coluna
      {
         i = 0;
         j++;
         delay_ms(20);   // Tempo para soltar a tecla
                         
      }

      if(input(C3) == 0)     // Varre terceira coluna
      {
         
         delay_ms(20);   // Tempo para soltar tecla
         break; //Não faz nada           
      }

      aux--;             // Decrementa 1 de aux
      delay_us(aux);     
   }

      output_high(L1);
      output_high(L2);
      output_high(L3);
      output_high(L4);

   return;               // Retorna ao main
}                        



//________________________________________________________________________________


void BIP(){
      output_high(B);
      delay_ms(100);
      output_low(B);
}


//________________________________________________________________________________


void ABRIR(){
      output_high(B);
      output_high(T);
      delay_ms(3000);
      output_low(T);
      output_low(B);
}

//________________________________________________________________________________



void main()
    {
//Variaveis de armazenamento
     int s1 = 0;
     int s2 = 0;
     int s3 = 0;
     int s4 = 0;
     int s5 = 0;
     int s6 = 0;
     int s7 = 0;

    set_tris_d(0b11100001); //Entradas e saidas da porta "d"
    set_tris_b(0b00000000); //Entradas e saidas da porta "b"
    PORTB=0x000000000;      //Coloca todas as portas de "b" 0
    PORTD=0x000000000;      //Coloca todas as portas de "d" 0
    lcd_inicializa();

    while(1)                     
    {

           while(j == 0)
            {
 
             
             lcd_posicao(1,5);
        printf(lcd_escreve,"BEM-VINDO");
                 delay_ms(500);
             lcd_posicao(2,1);
        printf(lcd_escreve,"INFORME A SENHA:");
                 delay_ms(500);
             lcd_posicao(1,1);
        printf(lcd_escreve,"                   ");
                delay_ms(1000);

                scan1();
                scan2();
                scan3();
                scan4();

            }
             lcd_posicao(2,1);
        printf(lcd_escreve,"                   ");
                delay_ms(200);
            BIP();

              lcd_posicao(1,5);
         printf(lcd_escreve,"  SENHA   ");
              lcd_posicao(2,6);
          printf(lcd_escreve,"%d",i);
                delay_ms(150);
          
         
            s1 = i;
            delay_ms(150);
            j = 1;

            while(j == 1)
            {
              
               lcd_posicao(1,5);
          printf(lcd_escreve,"  SENHA    ");
                lcd_posicao(2,6);
           
           printf(lcd_escreve,"*");
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
               lcd_posicao(1,5);
          printf(lcd_escreve,"  SENHA    ");
                lcd_posicao(2,7);
           printf(lcd_escreve,"%d",i);
            s2 = i;
            delay_ms(200);
            j = 2;

            while(j == 2)
            {
             
               lcd_posicao(1,5);
          printf(lcd_escreve,"  SENHA    ");
                lcd_posicao(2,7);
           printf(lcd_escreve,"*");
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
               lcd_posicao(1,5);
          printf(lcd_escreve,"  SENHA    ");
                lcd_posicao(2,8);
           printf(lcd_escreve,"%d",i);
            s3 = i;
            delay_ms(200);
            j = 3;

            while(j == 3)
            {
            
                lcd_posicao(1,5);
           printf(lcd_escreve,"  SENHA    ");
                 lcd_posicao(2,8);
            printf(lcd_escreve,"*");
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
                 lcd_posicao(1,5);
            printf(lcd_escreve,"  SENHA    ");
                  lcd_posicao(2,9);
             printf(lcd_escreve,"%d",i);
            s4 = i;
            delay_ms(200);
            j = 4;

            while(j == 4)
            {
         
                  lcd_posicao(1,5);
             printf(lcd_escreve,"  SENHA    ");
                   lcd_posicao(2,9);
              printf(lcd_escreve,"*");
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
                   lcd_posicao(1,5);
             printf(lcd_escreve,"  SENHA    ");
                   lcd_posicao(2,10);
              printf(lcd_escreve,"%d",i);
            s5 = i;
            delay_ms(200);
            j = 5;     
while(j == 5)
            {
            
                lcd_posicao(1,5);
           printf(lcd_escreve,"  SENHA    ");
                 lcd_posicao(2,10);
            printf(lcd_escreve,"*");
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
                 lcd_posicao(1,5);
            printf(lcd_escreve,"  SENHA    ");
                  lcd_posicao(2,11);
             printf(lcd_escreve,"%d",i);
            s6 = i;
            delay_ms(200);
            j = 6;
           while(j == 6)
            {
            
                lcd_posicao(1,5);
           printf(lcd_escreve,"  SENHA    ");
                 lcd_posicao(2,11);
            printf(lcd_escreve,"*");
            
                scan1();
                scan2();
                scan3();
                scan4();
            }
            BIP();
                 lcd_posicao(1,5);
            printf(lcd_escreve,"  SENHA    ");
                  lcd_posicao(2,12);
             printf(lcd_escreve,"*");
            s7 = i;
            delay_ms(300);
            j = 7;
            if( j == 7 )
            {
               
                if(s1 == 2 && s2 == 4 && s3 == 8 && s4 == 8 && s5 == 4 && s6==2 && s7 ==0 )
{

                    
                  lcd_posicao(1,3);
             printf(lcd_escreve,"SENHA CORRETA");
                  lcd_posicao(2,5);
             printf(lcd_escreve,"BEM VINDO");

                          BIP();
                          delay_ms(100);
                          ABRIR();
                          delay_ms(5000);
                          BIP();
                          delay_ms(100);

                lcd_posicao(1,2);
           printf(lcd_escreve,"               ");
                lcd_posicao(2,2);
           printf(lcd_escreve,"               ");
                     i = 0;
                     j = 0;
                                    
                }
                
                                    
                else
                {
                lcd_posicao(1,2);
           printf(lcd_escreve,"SENHA INCORRETA");
                lcd_posicao(2,2);
           printf(lcd_escreve,"TENTE NOVAMENTE");
                           BIP();
                           delay_ms(100);
                           BIP();
                           delay_ms(100);
                           BIP();
                           delay_ms(100);
                           BIP();
                           delay_ms(100);
                           BIP();
                           delay_ms(100);
                           BIP();
                           delay_ms(3000);
                           
                lcd_posicao(1,2);
           printf(lcd_escreve,"               ");
                lcd_posicao(2,2);
           printf(lcd_escreve,"               ");
                }
                     i = 0;
                     j = 0;
                                    s1 = 0;
                                    s2 = 0;
                                    s3 = 0;
                                    s4 = 0;
                                    s5 = 0;
                                    s6 = 0;
                                    s7 = 0;
}
    }
}

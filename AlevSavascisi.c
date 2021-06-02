#include <16F877A.h>
#device ADC=10
#fuses XT,NOWDT,NOPUT,NOPROTECT,NOBROWNOUT,NOLVP,NOWRT,NODEBUG,NOCPD
#use delay(clock = 4000000 )
#use fast_io(a)
unsigned long int bilgi;

void mesafe_oku () {
set_adc_channel(0);
delay_us(20);
bilgi = read_adc();

}

void main()
{
set_tris_a(1);
set_tris_d(0);
output_d(0);
setup_adc(adc_clock_div_32);
setup_adc_ports(AN0);



while (1) {
mesafe_oku ();


if((204 < bilgi) && (bilgi < 700 )){
output_d(0xA);
}
else if (bilgi < 204)
{
output_d(0);
output_high(pin_D0);
}
else 
{
output_d(0);
}



if(input(pin_A1) == FALSE){
output_high(pin_D3);
while(!(input(pin_A1)))  //sensor 1 olana kadar islem yapma
      {
      }
output_d(0); 
}

if(input(pin_A2) == FALSE)
{
output_high(pin_D1);
while(!(input(pin_A2)))  //sensor 1 olana kadar islem yapma
      {
      }
output_d(0); 

}

}
}

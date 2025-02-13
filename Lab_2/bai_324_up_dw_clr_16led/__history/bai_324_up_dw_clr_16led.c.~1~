
#include "tv_kit_vdk_18f6722_all.c"

unsigned int8 Led_state = 0;

void main()
{
   set_up_port();
   xuat_32led_don_4byte(0,0,0,0);
while(true){
      if(!input(on))          {delay_ms(50);Led_state = 0x0f;}
      else if(!input(inv))    {delay_ms(50);Led_state =~ Led_state;}
      else if (!input(off))   {delay_ms(50);Led_state=0;}
      
  xuat_32led_don_4byte(0,0,0,Led_state);
  }
}

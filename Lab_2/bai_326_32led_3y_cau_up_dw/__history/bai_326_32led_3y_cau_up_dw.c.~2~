
#include "tv_kit_vdk_18f6722_all.c"

unsigned int8 Led_state = 0;
unsigned int8 dir_state = 0;
usi16 LP = 0;

void dich_bit_left_to_right(){
        LP = (LP >> 1);
        xuat_32led_don_2word(0, LP);
        delay_ms(50);
}
void dich_bit_right_to_left(){
        LP = (LP << 1)+1;
        xuat_32led_don_2word(0, LP);
        delay_ms(50);
}

void main()
{
   set_up_port();
   xuat_32led_don_2word(0, 0);
while(true){

      
      if (!input(clr))  {delay_ms(50);  if (!input(clr)) {
         dir_state = ~dir_state;
         }
      }
      
      if(dir_state == 0){
            if(!input(up))         {delay_ms(50);  if(!input(up))  dich_bit_right_to_left();}
            else if(!input(dw))    {delay_ms(50);  if(!input(dw))   dich_bit_left_to_right();}
      }else{
            if(!input(up))         {delay_ms(50);  if(!input(up))  dich_bit_left_to_right();}
            else if(!input(dw))    {delay_ms(50);  if(!input(dw))   dich_bit_right_to_left();}
      }
      
  }
}

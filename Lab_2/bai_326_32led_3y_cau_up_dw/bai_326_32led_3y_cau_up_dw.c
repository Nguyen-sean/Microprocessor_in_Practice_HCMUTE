
#include "tv_kit_vdk_18f6722_all.c"

int8 Led_task_state = 0;

void task0(){
xuat_32led_don_2word(0, 0);
}

void task1(usi16 dl){ //right to left
    usi8 i; 
    usi32 x;
    x= 0;
    for(i = 0; i < 32; i++)
    {   
         
        x = (x << 1) + 1;
        xuat_32led_don_1dw(x);
        delay_ms(dl);
    }
    for(i = 0; i < 32; i++)
    {
        x = (x << 1);
        xuat_32led_don_1dw(x);
        delay_ms(dl);
    }
}

void task2(usi16 dl){ // left to right
    usi8 i; 
    usi32 x;
    x= 0;
    for(i = 0; i < 32; i++)
    {
        x = (x >> 1) + 0x80000000;
        xuat_32led_don_1dw(x);
        delay_ms(dl);
    }
    for(i = 0; i < 32; i++)
    {
        x = (x >> 1);
        xuat_32led_don_1dw(x);
        delay_ms(dl);
    }
}

void main()
{
   set_up_port();
   xuat_32led_don_2word(0, 0);
while(true){      
      if(!input(up)){
         delay_ms(50);  
         if(!input(up)) { 
            Led_task_state ++;
            if (Led_task_state > 2) Led_task_state = 2;
         }
      }
      
      if(!input(dw)){
         delay_ms(50);  
         if(!input(dw)) { 
            Led_task_state --;
            if (Led_task_state < 0) Led_task_state = 0;
         }
      }
      
      switch(Led_task_state){
         case 0: 
            task0();break;
         case 1: 
            task1(20);break;
         case 2: 
            task2(20);break;
      }
      
  }
}


#include "tv_kit_vdk_18f6722_all.c"

int8 Led_task_state = 0;

void task0(){
xuat_32led_don_2word(0, 0);
}

void task1(usi16 dl){ //right to left
    static usi8 i = 0; 
    static usi32 x = 0;

    if(i < 32) {   
        x = (x << 1) + 1;
        xuat_32led_don_1dw(x);
        delay_ms(dl);
        i++;
    }
    else if(i < 64) {
        x = (x << 1);
        xuat_32led_don_1dw(x);
        delay_ms(dl);
        i++;
    }
    else {
        i = 0; // Reset cycle
        x = 0;
    }
}

void task2(usi16 dl){ //left to right
    static usi8 i = 0; 
    static usi32 x = 0;

    if(i < 32) {
        x = (x >> 1) + 0x80000000;
        xuat_32led_don_1dw(x);
        delay_ms(dl);
        i++;
    }
    else if(i < 64) {
        x = (x >> 1);
        xuat_32led_don_1dw(x);
        delay_ms(dl);
        i++;
    }
    else {
        i = 0; // Reset cycle
        x = 0;
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

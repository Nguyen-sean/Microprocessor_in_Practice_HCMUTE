
#include "tv_kit_vdk_18f6722_all.c"

void main()
{
   set_up_port();
xuat_32led_don_4byte(0,0,0,0);
while(true){
   
      if(!input(on)){
         xuat_32led_don_4byte(0,0,0,0xFF);
      }
      if (!input(off)){
         xuat_32led_don_4byte(0,0,0,0);
      }
  
  }
}

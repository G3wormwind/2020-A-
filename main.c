#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "adc.h"
#include "mlx90614.h" 
#include "HC_SR04.h"


   
// int main(void)
// {	 

//	float a;
//	delay_init();	    	 //延时函数初始化	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
//	uart_init(115200);	 	 //串口初始化为115200
// 	LED_Init();			     //LED端口初始化
//	LCD_Init();	
//    	 
//      
//	while(1)
//	{
//		SMBus_Init();
//		a = SMBus_ReadTemp();
//		printf("温度 = %f℃\r\n",a);
//		LED0=!LED0;
//		delay_ms(250);	
//	}
// }
int main()
{
	float a;
	LED_Init();
	delay_init();
	LED0 = 0;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	 //串口初始化为115200	
	printf("串口初始化成功！\r\n");
	SMBus_Init();	 
	Hcsr04Init();	
	printf("超声波初始化成功！\r\n");//测试程序是否卡在下面两句上面
	while(1)
	{
		float length;
		a = SMBus_ReadTemp();
		printf("温度 = %f℃\r\n",a);
		LED0=!LED0;
		length = Hcsr04GetLength();
		printf("距离为:%.3f\r\n",length);
		delay_ms(500);
	}
	
}

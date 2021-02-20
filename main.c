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
//	delay_init();	    	 //��ʱ������ʼ��	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	uart_init(115200);	 	 //���ڳ�ʼ��Ϊ115200
// 	LED_Init();			     //LED�˿ڳ�ʼ��
//	LCD_Init();	
//    	 
//      
//	while(1)
//	{
//		SMBus_Init();
//		a = SMBus_ReadTemp();
//		printf("�¶� = %f��\r\n",a);
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
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	 //���ڳ�ʼ��Ϊ115200	
	printf("���ڳ�ʼ���ɹ���\r\n");
	SMBus_Init();	 
	Hcsr04Init();	
	printf("��������ʼ���ɹ���\r\n");//���Գ����Ƿ���������������
	while(1)
	{
		float length;
		a = SMBus_ReadTemp();
		printf("�¶� = %f��\r\n",a);
		LED0=!LED0;
		length = Hcsr04GetLength();
		printf("����Ϊ:%.3f\r\n",length);
		delay_ms(500);
	}
	
}

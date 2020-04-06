/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-01-xx
  * @brief   WF-ESP8266 WiFiģ�����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_SysTick.h"
#include "bsp_esp8266.h"
#include "bsp_dht11.h"
#include "common.h"
#include "esp8266_init_config.h"
#include "onenet.h"
 
 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
	uint8_t buff[1024];
DHT11_Data_TypeDef DHT11_Data;	
int main ( void )
{
	/* ��ʼ�� */
  USARTx_Config ();                                                              //��ʼ������1
	SysTick_Init ();                                                               //���� SysTick Ϊ 1ms �ж�һ�� 
	//ESP8266_Init ();                                                               //��ʼ��WiFiģ��ʹ�õĽӿں�����
	DHT11_Init ();

	
                      //��ӡ����������ʾ��Ϣ

	
 // ESP8266_StaTcpClient_UnvarnishTest ();
	ESP8266_StaTcpClient_UnvarnishTest();
	
  while ( 1 )
		{   
			 Delay_ms(500);
			if(DHT11_Read_TempAndHumidity(&DHT11_Data)==SUCCESS){
				 printf("\r\n��ȡDHT11�ɹ�!\r\n\r\nʪ��Ϊ%d.%d %%RH ���¶�Ϊ %d.%d�� \r\n",\
                   DHT11_Data.humi_int,DHT11_Data.humi_deci,DHT11_Data.temp_int,DHT11_Data.temp_deci);
				 sprintf((char *)buff,"%2d",DHT11_Data.temp_int);
				 ESP8266_Post_OneNet(HTTP_DEVICES_ID,HTTP_API_KEY,Temperature_ID,(char *)buff);
         sprintf((char *)buff,"%2d",DHT11_Data.humi_int);
         ESP8266_Post_OneNet(HTTP_DEVICES_ID,HTTP_API_KEY,Humidity_ID,(char *)buff);
				
			}
			else{
				  printf("Read DHT11 ERROR!\r\n");
				
				
				
			}
		
			
			
			
			
		
	}
	
	
}


/*********************************************END OF FILE**********************/

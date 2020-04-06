/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-01-xx
  * @brief   WF-ESP8266 WiFi模块测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无
  * @retval 无
  */
	uint8_t buff[1024];
DHT11_Data_TypeDef DHT11_Data;	
int main ( void )
{
	/* 初始化 */
  USARTx_Config ();                                                              //初始化串口1
	SysTick_Init ();                                                               //配置 SysTick 为 1ms 中断一次 
	//ESP8266_Init ();                                                               //初始化WiFi模块使用的接口和外设
	DHT11_Init ();

	
                      //打印测试例程提示信息

	
 // ESP8266_StaTcpClient_UnvarnishTest ();
	ESP8266_StaTcpClient_UnvarnishTest();
	
  while ( 1 )
		{   
			 Delay_ms(500);
			if(DHT11_Read_TempAndHumidity(&DHT11_Data)==SUCCESS){
				 printf("\r\n读取DHT11成功!\r\n\r\n湿度为%d.%d %%RH ，温度为 %d.%d℃ \r\n",\
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

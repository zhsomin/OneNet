   #include "esp8266_init_config.h"

/**
	************************************************************
	************************************************************
	************************************************************
	*	文件名： 
	*
	*	作者： 		吕家振
	*
	*	日期： 		
	*
	*	版本： 		V1.1
	*
	*	说明： 		
	*
	*	修改记录：
	************************************************************
	************************************************************
	************************************************************
**/

char cStr [ 100 ], cCh;

/**
  * @brief  ESP8266 （Sta Tcp Client）透传
  * @param  无
  * @retval 无
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	
    printf ( "\r\n配置ESP8266与ONENET连接 ......\r\n" );
//    LCD_DisplayStringLine_EN_CH(LINE(2),(uint8_t* )"ESP8266 SETTING FOR ONENET.......");
    ESP8266_Init (); 
	macESP8266_CH_ENABLE();
	
	ESP8266_AT_Test ();
	
	ESP8266_Net_Mode_Choose ( STA );

    ESP8266_Enable_MultipleId ( DISABLE );
     while (!ESP8266_JoinAP ( User_ESP8266_ApSsid, User_ESP8266_ApPwd ) );	
            
    while ( !ESP8266_Link_Server ( enumTCP, User_ESP8266_TcpServer_IP, User_ESP8266_TcpServer_Port, Single_ID_0 ) );
    printf ( "\r\n配置 ESP8266 完毕\r\n" );
//    LCD_DisplayStringLine_EN_CH(LINE(3),(uint8_t* )"配置 ESP8266 完毕.......");
}	



//==========================================================
//	函数名称：	ESP8266_Init
//
//	函数功能：	初始化ESP8266
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：		
//==========================================================

void Onenet_Init(void)
{
    printf("ESP8266配置中.......\r\n");
    ESP8266_Init ();          //初始化WiFi模块使用的接口和外设
    macESP8266_CH_ENABLE();

    ESP8266_AT_Test ();  
    ESP8266_Net_Mode_Choose ( STA );
    while ( ! ESP8266_JoinAP ( User_ESP8266_ApSsid,User_ESP8266_ApPwd ) );
    ESP8266_Enable_MultipleId ( DISABLE );
    while(!ESP8266_Link_Server(enumTCP,User_ESP8266_TcpServer_IP,User_ESP8266_TcpServer_Port,Single_ID_0));	
    ESP8266_UnvarnishSend();
//        macESP8266_Usart("POST /devices/520156476/datapoints?type=3 HTTP/1.1\r\n");
//        macESP8266_Usart("api-key:lPfTX5Caqf7237TCBc773mS7tK8=\r\n");
//        macESP8266_Usart("Host:api.heclouds.com\r\n");
//        macESP8266_Usart("Content-Length:11\r\n");
//        macESP8266_Usart("\r\n");
//        macESP8266_Usart("{\"TEMP\":15}");
}

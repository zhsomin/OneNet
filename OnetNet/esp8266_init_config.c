   #include "esp8266_init_config.h"

/**
	************************************************************
	************************************************************
	************************************************************
	*	�ļ����� 
	*
	*	���ߣ� 		������
	*
	*	���ڣ� 		
	*
	*	�汾�� 		V1.1
	*
	*	˵���� 		
	*
	*	�޸ļ�¼��
	************************************************************
	************************************************************
	************************************************************
**/

char cStr [ 100 ], cCh;

/**
  * @brief  ESP8266 ��Sta Tcp Client��͸��
  * @param  ��
  * @retval ��
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	
    printf ( "\r\n����ESP8266��ONENET���� ......\r\n" );
//    LCD_DisplayStringLine_EN_CH(LINE(2),(uint8_t* )"ESP8266 SETTING FOR ONENET.......");
    ESP8266_Init (); 
	macESP8266_CH_ENABLE();
	
	ESP8266_AT_Test ();
	
	ESP8266_Net_Mode_Choose ( STA );

    ESP8266_Enable_MultipleId ( DISABLE );
     while (!ESP8266_JoinAP ( User_ESP8266_ApSsid, User_ESP8266_ApPwd ) );	
            
    while ( !ESP8266_Link_Server ( enumTCP, User_ESP8266_TcpServer_IP, User_ESP8266_TcpServer_Port, Single_ID_0 ) );
    printf ( "\r\n���� ESP8266 ���\r\n" );
//    LCD_DisplayStringLine_EN_CH(LINE(3),(uint8_t* )"���� ESP8266 ���.......");
}	



//==========================================================
//	�������ƣ�	ESP8266_Init
//
//	�������ܣ�	��ʼ��ESP8266
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================

void Onenet_Init(void)
{
    printf("ESP8266������.......\r\n");
    ESP8266_Init ();          //��ʼ��WiFiģ��ʹ�õĽӿں�����
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

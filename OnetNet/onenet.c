 #include "onenet.h"
 #include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include "bsp_esp8266.h"
#include "common.h"
#include "stdarg.h"	 
#include "bsp_SysTick.h"	
#include "esp8266_init_config.h"	
/**
	************************************************************
	************************************************************
	************************************************************
	*	文件名： 
	*
	*	作者： 		
	*
	*	日期： 		
	*
	*	版本： 		V1.1
	*
	*	说明： 		onenet和http数据交互接口
	*
	*	修改记录：
	************************************************************
	************************************************************
	************************************************************
**/
//  AT+CWMODE=1
//AT+RST
//AT+CWJAP="OPPOr17","12345678"
//AT+CIPMUX=0
//AT+CIPSTART="TCP","183.230.40.33",80		onenet
//AT+CIPMODE=1
//AT+CIPSEND




/**
* @brief  透传发送的改进版本
  * @param  无
  * @retval 无
  * @attention 
  */
 void ESP8266_Post_OneNet(char *devices_id,char *api_key,char *datastream_id,char *point_value)
{
  
	char cStr [ 1500 ] = { 0 };
		    
    u16 length=0;
    char post_str[100]={0};  
    char *post_p1=0;
    char *post_p2=0;
    char check[1]={0};


            sprintf((char*)post_str,"{\"%s\":%s}",datastream_id,point_value);
            length = strlen(post_str);
            sprintf ( cStr,"POST /devices/%s/datapoints?type=3 HTTP/1.1\r\napi-key: %s\r\nHost: api.heclouds.com\r\nContent-Length: %d\r\n\r\n%s",devices_id,api_key,length,post_str );
         if(ESP8266_Get_LinkStatus()==3)
    {       
     printf("\r\n发送数据......\r\n");
			ESP8266_UnvarnishSend ();	//透传发送
           
            ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );
             Delay_ms ( 500 );
            if((post_p1=(char*)strstr((const char*)strEsp8266_Fram_Record .Data_RX_BUF,"errno")),(post_p1!=NULL)) //寻找POST后OneNet返回的开始符
            {
                if((post_p2=(char*)strstr((const char*)post_p1,"}")),(post_p2!=NULL))//寻找POST后OneNet返回的结束符
                {
                    post_p2=strtok((post_p1),":");
                    post_p2=(char*)strtok(NULL,",");
                    sprintf((char*)check,"%s",post_p2);
                    if(check[0]=='0')//判断OneNET是否接收到数据了，errno:0表示无错误，OneNET接收到数据
                    {   
                        printf("\r\nOneNET接收到数据!\r\n");
                    }
                    else
                        printf("\r\nOneNET没有接收到数据!\r\n");
                }
            }
                        ESP8266_ExitUnvarnishSend (); //退出透传
                        ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//关闭透传模式
    }
        
  else{
      //
       ESP8266_ExitUnvarnishSend (); //退出透传
       ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//关闭透传模式
      printf("重新连接。。。。");
       while (!ESP8266_JoinAP ( User_ESP8266_ApSsid, User_ESP8266_ApPwd ) );	
            
    while ( !ESP8266_Link_Server ( enumTCP, User_ESP8266_TcpServer_IP, User_ESP8266_TcpServer_Port, Single_ID_0 ) );
           }  
		
	}

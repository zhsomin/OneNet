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
	*	�ļ����� 
	*
	*	���ߣ� 		
	*
	*	���ڣ� 		
	*
	*	�汾�� 		V1.1
	*
	*	˵���� 		onenet��http���ݽ����ӿ�
	*
	*	�޸ļ�¼��
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
* @brief  ͸�����͵ĸĽ��汾
  * @param  ��
  * @retval ��
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
     printf("\r\n��������......\r\n");
			ESP8266_UnvarnishSend ();	//͸������
           
            ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );
             Delay_ms ( 500 );
            if((post_p1=(char*)strstr((const char*)strEsp8266_Fram_Record .Data_RX_BUF,"errno")),(post_p1!=NULL)) //Ѱ��POST��OneNet���صĿ�ʼ��
            {
                if((post_p2=(char*)strstr((const char*)post_p1,"}")),(post_p2!=NULL))//Ѱ��POST��OneNet���صĽ�����
                {
                    post_p2=strtok((post_p1),":");
                    post_p2=(char*)strtok(NULL,",");
                    sprintf((char*)check,"%s",post_p2);
                    if(check[0]=='0')//�ж�OneNET�Ƿ���յ������ˣ�errno:0��ʾ�޴���OneNET���յ�����
                    {   
                        printf("\r\nOneNET���յ�����!\r\n");
                    }
                    else
                        printf("\r\nOneNETû�н��յ�����!\r\n");
                }
            }
                        ESP8266_ExitUnvarnishSend (); //�˳�͸��
                        ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//�ر�͸��ģʽ
    }
        
  else{
      //
       ESP8266_ExitUnvarnishSend (); //�˳�͸��
       ESP8266_Cmd ( "AT+CIPMODE=0", "OK", 0, 200 );//�ر�͸��ģʽ
      printf("�������ӡ�������");
       while (!ESP8266_JoinAP ( User_ESP8266_ApSsid, User_ESP8266_ApPwd ) );	
            
    while ( !ESP8266_Link_Server ( enumTCP, User_ESP8266_TcpServer_IP, User_ESP8266_TcpServer_Port, Single_ID_0 ) );
           }  
		
	}

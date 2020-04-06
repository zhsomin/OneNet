#ifndef BSP_ONENET_ESP8266_H_
#define BSP_ONENET_ESP8266_H_

//ESP8266 POST���ݵ�OneNet
//devices_id:�豸��ID��
//api_key���豸APIKEY/��ƷAPIKEY
//datastream_id��������ID��Ҳ����������������
//point_value����������Ӧ�����ݵ�ֵ
//˵������͸��ģʽ�·��ͣ���ɺ�һ��Ҫ�˳�͸��ģʽ
#include "onenet.h"
#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include "bsp_esp8266.h"
#include "common.h"
#include "stdarg.h"	 
#include "bsp_SysTick.h"	

/********************************** �û���Ҫ���õĲ���**********************************/
#define   macUser_ESP8266_BulitApSsid         "SmartHome"      //Ҫ�������ȵ������
#define   macUser_ESP8266_BulitApEcn           OPEN               //Ҫ�������ȵ�ļ��ܷ�ʽ
#define   macUser_ESP8266_BulitApPwd           "123456"         //Ҫ�������ȵ����Կ

#define   macUser_ESP8266_TcpServer_IP         "192.168.4.1"      //������������IP��ַ
#define   macUser_ESP8266_TcpServer_Port       "8080"             //�����������Ķ˿�   

#define   macUser_ESP8266_TcpServer_OverTime   "1800"             //��������ʱʱ�䣨��λ���룩

#define User_ESP8266_ApSsid                       "aaa"              //Ҫ���ӵ��ȵ������
#define User_ESP8266_ApPwd                        "12345678"           //Ҫ���ӵ��ȵ����Կ

#define User_ESP8266_TcpServer_IP                 "183.230.40.33"       //Ҫ���ӵķ������� IP
#define User_ESP8266_TcpServer_Port               "80"                 //Ҫ���ӵķ������Ķ˿�
//#define EDP_ESP8266_TcpServer_IP                 "183.230.40.39"       //Ҫ���ӵķ������� IP
//#define EDP_ESP8266_TcpServer_Port               "876"                 //Ҫ���ӵķ������Ķ˿�
/***************************************************************************************************/
	
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"aaa\",\"12345678\"\r\n"

#define ESP8266_ONENET_INFO		"AT+CIPSTART=\"TCP\",\"183.230.40.39\",876\r\n"

#define HTTP_DEVICES_ID                "590779858"                       //�豸ID
#define HTTP_API_KEY                   "au=PzZoIVqnFjNC5twYjb=sdM4Q="    //APIKEY
#define Temperature_ID            "temp"
#define Humidity_ID                 "humi"

//#define EDP_DEVICES_ID                "522099502"                       //�豸ID
//#define EDP_API_KEY                  "=8LV1Nk08SXRQ51UYaGSoR8HgRk="    //APIKEY
extern char cStr [ 100 ], cCh;
extern  u8 ATMODE;
void ESP8266_AP_init(void);
void ESP8266_StaTcpClient_UnvarnishTest ( void );
//void Onenet_Init(void);
void ESP8266_ONENET_Init(void);
void ESP8266_Onenet_EDP(void);
void Connect_OneNet(void);
void EDP_Liking_Onenet(void);
#endif


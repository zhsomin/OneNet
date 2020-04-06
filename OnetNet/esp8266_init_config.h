#ifndef BSP_ONENET_ESP8266_H_
#define BSP_ONENET_ESP8266_H_

//ESP8266 POST数据到OneNet
//devices_id:设备的ID号
//api_key：设备APIKEY/产品APIKEY
//datastream_id：数据流ID，也就是数据流的名称
//point_value：数据流对应的数据点值
//说明：在透传模式下发送，完成后一定要退出透传模式
#include "onenet.h"
#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include "bsp_esp8266.h"
#include "common.h"
#include "stdarg.h"	 
#include "bsp_SysTick.h"	

/********************************** 用户需要设置的参数**********************************/
#define   macUser_ESP8266_BulitApSsid         "SmartHome"      //要建立的热点的名称
#define   macUser_ESP8266_BulitApEcn           OPEN               //要建立的热点的加密方式
#define   macUser_ESP8266_BulitApPwd           "123456"         //要建立的热点的密钥

#define   macUser_ESP8266_TcpServer_IP         "192.168.4.1"      //服务器开启的IP地址
#define   macUser_ESP8266_TcpServer_Port       "8080"             //服务器开启的端口   

#define   macUser_ESP8266_TcpServer_OverTime   "1800"             //服务器超时时间（单位：秒）

#define User_ESP8266_ApSsid                       "aaa"              //要连接的热点的名称
#define User_ESP8266_ApPwd                        "12345678"           //要连接的热点的密钥

#define User_ESP8266_TcpServer_IP                 "183.230.40.33"       //要连接的服务器的 IP
#define User_ESP8266_TcpServer_Port               "80"                 //要连接的服务器的端口
//#define EDP_ESP8266_TcpServer_IP                 "183.230.40.39"       //要连接的服务器的 IP
//#define EDP_ESP8266_TcpServer_Port               "876"                 //要连接的服务器的端口
/***************************************************************************************************/
	
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"aaa\",\"12345678\"\r\n"

#define ESP8266_ONENET_INFO		"AT+CIPSTART=\"TCP\",\"183.230.40.39\",876\r\n"

#define HTTP_DEVICES_ID                "590779858"                       //设备ID
#define HTTP_API_KEY                   "au=PzZoIVqnFjNC5twYjb=sdM4Q="    //APIKEY
#define Temperature_ID            "temp"
#define Humidity_ID                 "humi"

//#define EDP_DEVICES_ID                "522099502"                       //设备ID
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


#ifndef _ONENET_H_
#define _ONENET_H_

#include "stm32f10x.h"

#define SERVER                    "183.230.40.33"	                //OneNet服务器
#define SERVER_PORT               "80"        	                    //OneNet 公有协议下的Http模式端口
#define DEVICES_ID                "590779858"                        //设备ID
#define API_KEY                   "au=PzZoIVqnFjNC5twYjb=sdM4Q="    //APIKEY



u8 ESP8266_Post_Onenet(char *devices_id,char *api_key,char *datastream_id,char *point_value);    //ESP8266 POST数据一个数据流的数据点到OneNET
u8 ESP8266_Get_Onenet(char *devices_id,char *api_key,char *datastream_id,char *datastream_value);//ESP8266 从OneNET GET一个数据流的数据点
void ESP8266_Post_OneNet(char *devices_id,char *api_key,char *datastream_id,char *point_value);

_Bool OneNet_DevLink(void);
unsigned char OneNet_FillBuf(char *buf);

void OneNet_SendData(void);
void OneNet_RevPro(unsigned char *cmd);

#endif


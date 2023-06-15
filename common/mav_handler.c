#include "mavlink.h"
#include <stdio.h>
unsigned char buf[50];

#define UART_PT &huart2
#define SYS_ID  1
#define COMP_ID 2
mavlink_status_t mavlink_status;
mavlink_command_long_t packet_t;
/*send data STM32 */ 
void send_packet(float lat,float lon , float alt, float heading, float roll,float pitch,float yaw){
    mavlink_message_t msg;
    mavlink_msg_command_long_pack(SYS_ID, COMP_ID,&msg,11,22,33,44,lat,lon,alt, heading, roll,pitch,yaw);
	int len = mavlink_msg_to_send_buffer(buf, &msg);
    HAL_UART_Transmit(UART_PT,buf,len,100);
}


/*Receive  esp */  
// dùng ngắt đọc từng byte c hoặc while loop
void mavlinkCallback(uint8_t c;){
    if (mavlink_parse_char(MAVLINK_COMM_0,c,&msg, &mavlink_status)){
        switch (msg.msgid)
            {
            case MAVLINK_MSG_ID_COMMAND_LONG:
                mavlink_msg_command_long_decode(&msg,&packet_t);
                break;
            default:
                break;
            }
        }
}
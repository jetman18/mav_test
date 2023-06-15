#ifndef _MAV_HANDLER_H_
#define _MAV_HANDLER_H_

extern mavlink_command_long_t packet_t;
void send_packet(float lat,float lon , float alt, float heading, float roll,float pitch,float yaw);
void mavlinkCallback();

#endif
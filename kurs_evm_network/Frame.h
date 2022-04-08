#ifndef _FRAME_H_
#define _FRAME_H_

#include <stdlib.h>
#include "Bitfield.h"

#define ENABLE_COLLISIONS 1
#define DISABLE_COLLISIONS 0

#define DEFAULT_START_FRAME 126		// 0111.1110

typedef struct Frame
{
	Bitfield8 start;
	Bitfield7 recipient_address;
	Bitfield7 sender_address;
	Bitfield1 package_type;
	Bitfield10 data_length;
	Bitfield8 data;
	unsigned char checksum;

}Frame;

void print_frame(Frame* frame);
void convert_to_binary(unsigned char value, char* bin);

void send_frame(Frame* frame, uint16_t number_of_station, uint8_t are_allowed_transmission_errors);
int16_t receive_frame(Frame* frame, uint16_t current_station);

void collisions(Frame* frame);
void form_response_frame(Frame* source_frame, Frame* answer);

uint16_t calculate_bytesum(Frame* frame);
unsigned char calculate_checksum(Frame* frame);

#endif // !_FRAME_H_


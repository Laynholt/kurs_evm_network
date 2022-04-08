#ifndef _BIT_FIELD_H_
#define _BIT_FIELD_H_

#include <stdio.h>
#include <stdint.h>

#define MASK_BIT0 0x0001u
#define MASK_BIT7 0x0080u

#define BIT0 0u
#define BIT1 1u
#define BIT2 2u
#define BIT3 3u
#define BIT4 4u
#define BIT5 5u
#define BIT6 6u
#define BIT7 7u
#define BIT8 8u
#define BIT9 9u

#define set_bit(var, bit_val, num_bit) ((var) |= ((bit_val) << (num_bit)))
#define clear_bit(var, bit_val, num_bit) ((var) &= ~((bit_val) << (num_bit)))

typedef struct Bitfield1
{
	unsigned bit0 : 1;

}Bitfield1;

typedef struct Bitfield7
{
	unsigned bit0 : 1;
	unsigned bit1 : 1;
	unsigned bit2 : 1;
	unsigned bit3 : 1;
	unsigned bit4 : 1;
	unsigned bit5 : 1;
	unsigned bit6 : 1;

}Bitfield7;

typedef struct Bitfield8
{
	unsigned bit0 : 1;
	unsigned bit1 : 1;
	unsigned bit2 : 1;
	unsigned bit3 : 1;
	unsigned bit4 : 1;
	unsigned bit5 : 1;
	unsigned bit6 : 1;
	unsigned bit7 : 1;

}Bitfield8;

typedef struct Bitfield10
{
	unsigned bit0 : 1;
	unsigned bit1 : 1;
	unsigned bit2 : 1;
	unsigned bit3 : 1;
	unsigned bit4 : 1;
	unsigned bit5 : 1;
	unsigned bit6 : 1;
	unsigned bit7 : 1;
	unsigned bit8 : 1;
	unsigned bit9 : 1;

}Bitfield10;

void write_bitfield1(Bitfield1* bf, uint16_t value);
void write_bitfield7(Bitfield7* bf, uint16_t value);
void write_bitfield8(Bitfield8* bf, uint16_t value);
void write_bitfield10(Bitfield10* bf, uint16_t value);

int16_t read_bitfield1(Bitfield1 bf);
int16_t read_bitfield7(Bitfield7 bf);
int16_t read_bitfield8(Bitfield8 bf);
int16_t read_bitfield10(Bitfield10 bf);

void print_bitfield1(Bitfield1 bf);
void print_bitfield7(Bitfield7 bf);
void print_bitfield8(Bitfield8 bf);
void print_bitfield10(Bitfield10 bf);

#endif // !_BIT_FIELD_H_

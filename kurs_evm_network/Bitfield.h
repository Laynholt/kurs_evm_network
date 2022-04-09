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
#define BIT10 10u
#define BIT11 11u
#define BIT12 12u
#define BIT13 13u
#define BIT14 14u
#define BIT15 15u
#define BIT16 16u
#define BIT17 17u
#define BIT18 18u
#define BIT19 19u
#define BIT20 20u
#define BIT21 21u
#define BIT22 22u
#define BIT23 23u
#define BIT24 24u
#define BIT25 25u
#define BIT26 26u
#define BIT27 27u
#define BIT28 28u
#define BIT29 29u
#define BIT30 30u
#define BIT31 31u

#define set_bit(var, bit_val, num_bit) ((var) |= ((bit_val) << (num_bit)))
#define clear_bit(var, bit_val, num_bit) ((var) &= ~((bit_val) << (num_bit)))

#define INTERMEDIATE_OUTPUT_ENABLE 1
#define INTERMEDIATE_OUTPUT_DISABLE 0

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

typedef struct Bitfield32
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
	unsigned bit10 : 1;
	unsigned bit11 : 1;
	unsigned bit12 : 1;
	unsigned bit13 : 1;
	unsigned bit14 : 1;
	unsigned bit15 : 1;
	unsigned bit16 : 1;
	unsigned bit17 : 1;
	unsigned bit18 : 1;
	unsigned bit19 : 1;
	unsigned bit20 : 1;
	unsigned bit21 : 1;
	unsigned bit22 : 1;
	unsigned bit23 : 1;
	unsigned bit24 : 1;
	unsigned bit25 : 1;
	unsigned bit26 : 1;
	unsigned bit27 : 1;
	unsigned bit28 : 1;
	unsigned bit29 : 1;
	unsigned bit30 : 1;
	unsigned bit31 : 1;

}Bitfield32;

typedef struct Bitfield64
{
	Bitfield32 low_bits32;
	Bitfield32 high_bits32;

}Bitfield64;

void write_bitfield1(Bitfield1* bf, uint16_t value);
void write_bitfield7(Bitfield7* bf, uint16_t value);
void write_bitfield8(Bitfield8* bf, uint16_t value);
void write_bitfield10(Bitfield10* bf, uint16_t value);
void write_bitfield32(Bitfield32* bf, uint32_t value);
void write_bitfield64(Bitfield64* bf, uint64_t value);

uint16_t read_bitfield1(Bitfield1 bf);
uint16_t read_bitfield7(Bitfield7 bf);
uint16_t read_bitfield8(Bitfield8 bf);
uint16_t read_bitfield10(Bitfield10 bf);
uint32_t read_bitfield32(Bitfield32 bf);
uint64_t read_bitfield64(Bitfield64 bf);

void print_bitfield1(Bitfield1 bf);
void print_bitfield7(Bitfield7 bf);
void print_bitfield8(Bitfield8 bf);
void print_bitfield10(Bitfield10 bf);
void print_bitfield32(Bitfield32 bf, uint8_t is_intermediated);
void print_bitfield64(Bitfield64 bf, uint8_t is_intermediated);

#endif // !_BIT_FIELD_H_

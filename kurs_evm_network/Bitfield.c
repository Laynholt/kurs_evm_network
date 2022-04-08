#include "Bitfield.h"

void write_bitfield1(Bitfield1* bf, uint16_t value)
{
	bf->bit0 = value & MASK_BIT0;
}

void write_bitfield7(Bitfield7* bf, uint16_t value)
{
	bf->bit0 = value & MASK_BIT0;
	bf->bit1 = (value >> 1) & MASK_BIT0;
	bf->bit2 = (value >> 2) & MASK_BIT0;
	bf->bit3 = (value >> 3) & MASK_BIT0;
	bf->bit4 = (value >> 4) & MASK_BIT0;
	bf->bit5 = (value >> 5) & MASK_BIT0;
	bf->bit6 = (value >> 6) & MASK_BIT0;
}

void write_bitfield8(Bitfield8* bf, uint16_t value)
{
	bf->bit0 = value & MASK_BIT0;
	bf->bit1 = (value >> 1) & MASK_BIT0;
	bf->bit2 = (value >> 2) & MASK_BIT0;
	bf->bit3 = (value >> 3) & MASK_BIT0;
	bf->bit4 = (value >> 4) & MASK_BIT0;
	bf->bit5 = (value >> 5) & MASK_BIT0;
	bf->bit6 = (value >> 6) & MASK_BIT0;
	bf->bit7 = (value >> 7) & MASK_BIT0;
}

void write_bitfield10(Bitfield10* bf, uint16_t value)
{
	bf->bit0 = value & MASK_BIT0;
	bf->bit1 = (value >> 1) & MASK_BIT0;
	bf->bit2 = (value >> 2) & MASK_BIT0;
	bf->bit3 = (value >> 3) & MASK_BIT0;
	bf->bit4 = (value >> 4) & MASK_BIT0;
	bf->bit5 = (value >> 5) & MASK_BIT0;
	bf->bit6 = (value >> 6) & MASK_BIT0;
	bf->bit7 = (value >> 7) & MASK_BIT0;
	bf->bit8 = (value >> 8) & MASK_BIT0;
	bf->bit9 = (value >> 9) & MASK_BIT0;
}

int16_t read_bitfield1(Bitfield1 bf)
{
	int16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	return value;
}

int16_t read_bitfield7(Bitfield7 bf)
{
	int16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	set_bit(value, bf.bit1, BIT1);
	set_bit(value, bf.bit2, BIT2);
	set_bit(value, bf.bit3, BIT3);
	set_bit(value, bf.bit4, BIT4);
	set_bit(value, bf.bit5, BIT5);
	set_bit(value, bf.bit6, BIT6);
	return value;
}

int16_t read_bitfield8(Bitfield8 bf)
{
	int16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	set_bit(value, bf.bit1, BIT1);
	set_bit(value, bf.bit2, BIT2);
	set_bit(value, bf.bit3, BIT3);
	set_bit(value, bf.bit4, BIT4);
	set_bit(value, bf.bit5, BIT5);
	set_bit(value, bf.bit6, BIT6);
	set_bit(value, bf.bit7, BIT7);
	return value;
}

int16_t read_bitfield10(Bitfield10 bf)
{
	int16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	set_bit(value, bf.bit1, BIT1);
	set_bit(value, bf.bit2, BIT2);
	set_bit(value, bf.bit3, BIT3);
	set_bit(value, bf.bit4, BIT4);
	set_bit(value, bf.bit5, BIT5);
	set_bit(value, bf.bit6, BIT6);
	set_bit(value, bf.bit7, BIT7);
	set_bit(value, bf.bit8, BIT8);
	set_bit(value, bf.bit9, BIT9);
	return value;
}

void print_bitfield1(Bitfield1 bf)
{
	char buf[2] = { 48 + bf.bit0, '\0'};
	printf("| %s  |", buf);
}

void print_bitfield7(Bitfield7 bf)
{
	char buf[8] = { 48 + bf.bit6, 48 + bf.bit5, 48 + bf.bit4, 48 + bf.bit3,
					48 + bf.bit2, 48 + bf.bit1, 48 + bf.bit0, '\0'
	};
	printf("| %s |", buf);
}

void print_bitfield8(Bitfield8 bf)
{
	char buf[9] = { 48 + bf.bit7, 48 + bf.bit6, 48 + bf.bit5, 48 + bf.bit4,
					48 + bf.bit3, 48 + bf.bit2, 48 + bf.bit1, 48 + bf.bit0, '\0'
	};
	printf("| %s |", buf);
}

void print_bitfield10(Bitfield10 bf)
{
	char buf[11] = { 48 + bf.bit9, 48 + bf.bit8, 48 + bf.bit7, 48 + bf.bit6,
					 48 + bf.bit5, 48 + bf.bit4, 48 + bf.bit3, 48 + bf.bit2,
					 48 + bf.bit1, 48 + bf.bit0, '\0'
	};
	printf("| %s |", buf);
}

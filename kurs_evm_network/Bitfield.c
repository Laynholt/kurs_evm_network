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

void write_bitfield32(Bitfield32* bf, uint32_t value)
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
	bf->bit10 = (value >> 10) & MASK_BIT0;
	bf->bit11 = (value >> 11) & MASK_BIT0;
	bf->bit12 = (value >> 12) & MASK_BIT0;
	bf->bit13 = (value >> 13) & MASK_BIT0;
	bf->bit14 = (value >> 14) & MASK_BIT0;
	bf->bit15 = (value >> 15) & MASK_BIT0;
	bf->bit16 = (value >> 16) & MASK_BIT0;
	bf->bit17 = (value >> 17) & MASK_BIT0;
	bf->bit18 = (value >> 18) & MASK_BIT0;
	bf->bit19 = (value >> 19) & MASK_BIT0;
	bf->bit20 = (value >> 20) & MASK_BIT0;
	bf->bit21 = (value >> 21) & MASK_BIT0;
	bf->bit22 = (value >> 22) & MASK_BIT0;
	bf->bit23 = (value >> 23) & MASK_BIT0;
	bf->bit24 = (value >> 24) & MASK_BIT0;
	bf->bit25 = (value >> 25) & MASK_BIT0;
	bf->bit26 = (value >> 26) & MASK_BIT0;
	bf->bit27 = (value >> 27) & MASK_BIT0;
	bf->bit28 = (value >> 28) & MASK_BIT0;
	bf->bit29 = (value >> 29) & MASK_BIT0;
	bf->bit30 = (value >> 30) & MASK_BIT0;
	bf->bit31 = (value >> 31) & MASK_BIT0;
}

void write_bitfield64(Bitfield64* bf, uint64_t value)
{
	uint32_t low, high;
	low = value & 0x00000000FFFFFFFFu;
	high = (value >> 32) & 0x00000000FFFFFFFFu;

	write_bitfield32(&bf->low_bits32, low);
	write_bitfield32(&bf->high_bits32, high);
}

uint16_t read_bitfield1(Bitfield1 bf)
{
	uint16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	return value;
}

uint16_t read_bitfield7(Bitfield7 bf)
{
	uint16_t value = 0;
	set_bit(value, bf.bit0, BIT0);
	set_bit(value, bf.bit1, BIT1);
	set_bit(value, bf.bit2, BIT2);
	set_bit(value, bf.bit3, BIT3);
	set_bit(value, bf.bit4, BIT4);
	set_bit(value, bf.bit5, BIT5);
	set_bit(value, bf.bit6, BIT6);
	return value;
}

uint16_t read_bitfield8(Bitfield8 bf)
{
	uint16_t value = 0;
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

uint16_t read_bitfield10(Bitfield10 bf)
{
	uint16_t value = 0;
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

uint32_t read_bitfield32(Bitfield32 bf)
{
	uint32_t value = 0;
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
	set_bit(value, bf.bit10, BIT10);
	set_bit(value, bf.bit11, BIT11);
	set_bit(value, bf.bit12, BIT12);
	set_bit(value, bf.bit13, BIT13);
	set_bit(value, bf.bit14, BIT14);
	set_bit(value, bf.bit15, BIT15);
	set_bit(value, bf.bit16, BIT16);
	set_bit(value, bf.bit17, BIT17);
	set_bit(value, bf.bit18, BIT18);
	set_bit(value, bf.bit19, BIT19);
	set_bit(value, bf.bit20, BIT20);
	set_bit(value, bf.bit21, BIT21);
	set_bit(value, bf.bit22, BIT22);
	set_bit(value, bf.bit23, BIT23);
	set_bit(value, bf.bit24, BIT24);
	set_bit(value, bf.bit25, BIT25);
	set_bit(value, bf.bit26, BIT26);
	set_bit(value, bf.bit27, BIT27);
	set_bit(value, bf.bit28, BIT28);
	set_bit(value, bf.bit29, BIT29);
	set_bit(value, bf.bit30, BIT30);
	set_bit(value, bf.bit31, BIT31);
	return value;
}

uint64_t read_bitfield64(Bitfield64 bf)
{
	uint64_t value;
	uint32_t low, high;
	low = read_bitfield32(bf.low_bits32);
	high = read_bitfield32(bf.high_bits32);

	value = ((uint64_t)high << 32) + low;
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

void print_bitfield32(Bitfield32 bf, uint8_t is_intermediated)
{
	char buf[33] = { 48 + bf.bit31, 48 + bf.bit30,
					 48 + bf.bit29, 48 + bf.bit28, 48 + bf.bit27, 48 + bf.bit26,
					 48 + bf.bit25, 48 + bf.bit24, 48 + bf.bit23, 48 + bf.bit22,
					 48 + bf.bit21, 48 + bf.bit20,
					 48 + bf.bit19, 48 + bf.bit18, 48 + bf.bit17, 48 + bf.bit16,
					 48 + bf.bit15, 48 + bf.bit14, 48 + bf.bit13, 48 + bf.bit12,
					 48 + bf.bit11, 48 + bf.bit10,
					 48 + bf.bit9, 48 + bf.bit8, 48 + bf.bit7, 48 + bf.bit6,
					 48 + bf.bit5, 48 + bf.bit4, 48 + bf.bit3, 48 + bf.bit2,
					 48 + bf.bit1, 48 + bf.bit0, '\0'
	};
	if (!is_intermediated)
		printf("| %s |", buf);
	else
		printf("%s", buf);
}

void print_bitfield64(Bitfield64 bf, uint8_t is_intermediated)
{
	if (!is_intermediated)
	{
		printf("| ");
		print_bitfield32(bf.high_bits32, INTERMEDIATE_OUTPUT_ENABLE);
		print_bitfield32(bf.low_bits32, INTERMEDIATE_OUTPUT_ENABLE);
		printf(" |");
	}
}

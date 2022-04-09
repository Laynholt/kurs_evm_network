#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <math.h>
#include <time.h>

#include "Frame.h"

#define NUMBER_OF_STATIONS 90

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(100);

	Frame frame = { 0 };
	uint16_t nquit = 1;
	uint16_t value;
	uint64_t data_value;

	write_bitfield8(&frame.start, DEFAULT_START_FRAME);
	while (nquit)
	{
		printf("������� ����� ������� �����������[0-89]: ");
		scanf("%u", &value);

		if (value >= NUMBER_OF_STATIONS)
		{
			printf("����������, ������� ����� �� 0 �� %d!\n", NUMBER_OF_STATIONS - 1);
			continue;
		}
		write_bitfield7(&frame.sender_address, value);

		printf("������� ����� ������� ����������[0-89]: ");
		scanf("%u", &value);

		if (value >= NUMBER_OF_STATIONS)
		{
			printf("����������, ������� ����� �� 0 �� %d!\n", NUMBER_OF_STATIONS - 1);
			continue;
		}
		write_bitfield7(&frame.recipient_address, value);

		printf("������� ������[� ���� ����� � 10 ��](����� �� 0 �� 2^64): ");
		scanf("%u", &data_value);
		write_bitfield64(&frame.data, data_value);

		// ����������� ����� ������ ����� 8 ���, ��� ��� 
		// ������������ �������� � ������ 256 ��� �����������
		write_bitfield10(&frame.data_length, 64);

		unsigned char checksum = calculate_checksum(&frame);
		write_bitfield8(&frame.checksum, checksum);

		// ���������� ��������� ����
		printf("\n������������ ����:\n");
		print_frame(&frame);
		printf("\n\n");

		// ���������� ����
		send_frame(&frame, NUMBER_OF_STATIONS, ENABLE_COLLISIONS);

		printf("\n������� 0 ��� ����, ����� �����: ");
		scanf("%u", &nquit);
	}

	return 0;
}
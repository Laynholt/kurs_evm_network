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
		printf("Введите номер станции отправителя[0-89]: ");
		scanf("%u", &value);

		if (value >= NUMBER_OF_STATIONS)
		{
			printf("Пожалуйста, введите число от 0 до %d!\n", NUMBER_OF_STATIONS - 1);
			continue;
		}
		write_bitfield7(&frame.sender_address, value);

		printf("Введите номер станции получателя[0-89]: ");
		scanf("%u", &value);

		if (value >= NUMBER_OF_STATIONS)
		{
			printf("Пожалуйста, введите число от 0 до %d!\n", NUMBER_OF_STATIONS - 1);
			continue;
		}
		write_bitfield7(&frame.recipient_address, value);

		printf("Введите данные[в виде числа в 10 СС](число от 0 до 2^64): ");
		scanf("%u", &data_value);
		write_bitfield64(&frame.data, data_value);

		// Стандартная длина данных будет 8 бит, так как 
		// максимальное значение в данных 256 для наглядности
		write_bitfield10(&frame.data_length, 64);

		unsigned char checksum = calculate_checksum(&frame);
		write_bitfield8(&frame.checksum, checksum);

		// Отображаем введенный кадр
		printf("\nОтправляемый кадр:\n");
		print_frame(&frame);
		printf("\n\n");

		// Отправляем кадр
		send_frame(&frame, NUMBER_OF_STATIONS, ENABLE_COLLISIONS);

		printf("\nНажмите 0 для того, чтобы выйти: ");
		scanf("%u", &nquit);
	}

	return 0;
}
#include "Frame.h"

void print_frame(Frame* frame)
{
	char buf[9] = { '\0' };

	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("||    НК    ||    АП   ||    АИ   || ТС ||     ДД     ||                              ДАННЫЕ                              ||    FCS   ||\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n|");
	print_bitfield8(frame->start);
	print_bitfield7(frame->recipient_address);
	print_bitfield7(frame->sender_address);
	print_bitfield1(frame->package_type);
	print_bitfield10(frame->data_length);
	print_bitfield64(frame->data, INTERMEDIATE_OUTPUT_DISABLE);
	
	convert_to_binary(frame->checksum, buf);
	printf("| %s ||", buf);
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
}

void convert_to_binary(unsigned char value, char* bin)
{
	for (int16_t i = 0; i < 8; ++i)
	{
		bin[i] = ((value << i) & MASK_BIT7) ? '1' : '0';
	}
}

void send_frame(Frame* frame, uint16_t number_of_station, uint8_t are_allowed_transmission_errors)
{
	Frame response_frame = { 0 };
	uint16_t source_station = read_bitfield7(frame->sender_address);
	uint16_t do_collisions = 0;

	// Проверяем, чтобы адреса получателя и отправителя не совпадали
	uint16_t receiver_station = read_bitfield7(frame->recipient_address);
	if (source_station == receiver_station)
	{
		printf("Станция [#%u] отправила кадр сама себе", source_station);
		printf("\nПолученный кадр:\n");
		print_frame(frame);
		printf("\n\n");
		return;
	}

	for (uint16_t i = 0, current_station = source_station; i < number_of_station; ++i)
	{
		current_station = (current_station + 1) % number_of_station;
		printf("Сообщение дошло до станции [#%u]\n", current_station);

		if (are_allowed_transmission_errors)
		{
			do_collisions = rand() % 50;
			if (do_collisions < 25)
				collisions(frame);
		}

		int16_t return_value = receive_frame(frame, current_station);
		// Если нужная станция получила кадр
		if (return_value == 1)
		{
			// Если это не ответное сообщение, то отправляем ответ
			if (!read_bitfield1(frame->package_type))
			{
				form_response_frame(frame, &response_frame);
				printf("Ответ от станции [#%u] сформирован и отправлен в сеть\n", current_station);
				printf("\nСформированный кадр:\n");
				print_frame(&response_frame);
				printf("\n\n");
				send_frame(&response_frame, number_of_station, DISABLE_COLLISIONS);
			}
			break;
		}
		else if (return_value == -1)
		{
			printf("\nИз-за ошибочных значений кадр был отбрашен!\n");
			break;
		}
	}
}

int16_t receive_frame(Frame* frame, uint16_t current_station)
{
	// return
	// -1 - ошибка,
	//  0 - не принял (не нам), 
	//  1 - принял (нам)
	
	// Проверка начала кадра
	if (DEFAULT_START_FRAME != read_bitfield8(frame->start))
	{
		printf("Поле начала кадра некорректно!\nНаше -> ");
		print_bitfield8(frame->start);

		char buf[9] = { '\0' };
		convert_to_binary(DEFAULT_START_FRAME, buf);
		printf(" +|+ Стандартное -> | %s |", buf);
		return -1;
	}

	// Проверка контрольной суммы по мод256
	uint16_t frame_sum = calculate_bytesum(frame);

	if ((frame_sum + (uint16_t)frame->checksum) % 256 != 0)
	{
		printf("Поле контрольной суммы не подходит под полученные значения других полей! Возможно произошла коллизия.\n"
			"Полученный кадр->\n");
		print_frame(frame);
		printf("\n");
		return -1;
	}

	// Смотрим, эта ли станция является получателем
	if (current_station == read_bitfield7(frame->recipient_address))
	{
		if (!read_bitfield1(frame->package_type))
		{
			printf("Станция назначения [#%u] получила кадр. Идёт подготовка к отправке ответа!\n", current_station);
		}
		else
		{
			printf("Станция назначения [#%u] получила кадр-ответ.\n", current_station);
			printf("\nПолученный кадр:\n");
			print_frame(frame);
			printf("\n\n");
		}
		return 1;
	}
	else
	{
		printf("Станция [#%u] проанализировала кадр. Возвращает кадр в сеть!\n", current_station);
		return 0;
	}
}

void collisions(Frame* frame)
{
	// Создаем произвольные ошибки в 
		// Поле начала кадра
		// Поле источника
		// Поле приемника
		// Полях данных и длины данных, если они есть
	// Не трогаем поле типа сообшения (чтобы не было миллионов ответов туда-сюда)

	uint16_t package_type = read_bitfield1(frame->package_type);
	uint16_t damaged_field = rand() % 5;

	uint16_t old_value, new_value; 
	switch (damaged_field)
	{
	case 0u:
	{
		old_value = read_bitfield8(frame->start);
		new_value = old_value + rand() % 10;
		printf("Поле начала кадра было изменено вследствие коллизии со значения\n[%u] - ", old_value);
		print_bitfield8(frame->start);
		printf("  на значение [%u] - ", new_value);
		write_bitfield8(&frame->start, new_value);
		print_bitfield8(frame->start);
		printf("\n");
		break;
	}
	case 1u:
	{
		old_value = read_bitfield7(frame->sender_address);
		new_value = old_value + rand() % 10;
		printf("Поле отправителя было изменено вследствие коллизии со значения\n[%u] - ", old_value);
		print_bitfield7(frame->sender_address);
		printf("  на значение [%u] - ", new_value);
		write_bitfield7(&frame->sender_address, new_value);
		print_bitfield7(frame->sender_address);
		printf("\n");
		break;
	}
	case 2u:
	{
		old_value = read_bitfield7(frame->recipient_address);
		new_value = old_value + rand() % 10;
		printf("Поле получателя было изменено вследствие коллизии со значения\n[%u] - ", old_value);
		print_bitfield7(frame->recipient_address);
		printf("  на значение [%u] - ", new_value);
		write_bitfield7(&frame->recipient_address, new_value);
		print_bitfield7(frame->recipient_address);
		printf("\n");
		break;
	}
	case 3u:
	{
		old_value = read_bitfield10(frame->data_length);
		new_value = old_value + rand() % 10;
		printf("Поле длины данных было изменено вследствие коллизии со значения\n[%u] - ", old_value);
		print_bitfield10(frame->data_length);
		printf("  на значение [%u] - ", new_value);
		write_bitfield10(&frame->data_length, new_value);
		print_bitfield10(frame->data_length);
		printf("\n");
		break;
	}
	case 4u:
	{
		uint64_t old_value_data = read_bitfield64(frame->data);
		uint64_t new_value_data = old_value_data + rand() % 10;
		printf("Поле данных было изменено вследствие коллизии со значения\n[%ul] - ", old_value_data);
		print_bitfield64(frame->data, INTERMEDIATE_OUTPUT_DISABLE);
		printf("  на значение [%ul] - ", new_value_data);
		write_bitfield64(&frame->data, new_value_data);
		print_bitfield64(frame->data, INTERMEDIATE_OUTPUT_DISABLE);
		printf("\n");
		break;
	}
	default:
		break;
	}
}

void form_response_frame(Frame* source_frame, Frame* answer)
{
	uint16_t source, destination;
	source = read_bitfield7(source_frame->recipient_address);
	destination = read_bitfield7(source_frame->sender_address);

	write_bitfield8(&answer->start, DEFAULT_START_FRAME);
	write_bitfield7(&answer->sender_address, source);
	write_bitfield7(&answer->recipient_address, destination);
	write_bitfield1(&answer->package_type, 1);

	answer->checksum = calculate_checksum(answer);
}

uint16_t calculate_bytesum(Frame* frame)
{
	uint16_t frame_sum = 0;
	uint16_t package_type = read_bitfield1(frame->package_type);

	frame_sum += read_bitfield8(frame->start);
	frame_sum += read_bitfield7(frame->sender_address);
	frame_sum += read_bitfield7(frame->recipient_address);
	frame_sum += package_type;

	// Если это не ответное сообщение, то у него есть поле данных (они не 0)
	if (!package_type)
	{
		frame_sum += read_bitfield10(frame->data_length);
		frame_sum += (read_bitfield64(frame->data) % 256);
	}

	return frame_sum;
}

unsigned char calculate_checksum(Frame* frame)
{
	uint16_t frame_sum = calculate_bytesum(frame);
	frame_sum %= 256;
	return 256 - frame_sum;
}

#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "byte.h"
#include "word.h"
#include "dword.h"
#include "memory.h"
#include "stack_block.h"

/*!
	\brief Класс симуляции

	Реализация работы с регистрами и обработка входящих данных
	*/
class ROM_memory
{
	word EAX;
	word EBX;
	word ECX;
	word EDX;
	stack_block Stack;
	memory data;
public:
	/*!
	\brief Возврат значения.
	Возвращает байт по строке
	\param title Возвращает ссылку на байт для пользования
	*/
	byte &return_by_string(const std::string &);
	/*!
	\brief Возврат значения.
	Возвращает регистр по строке
	\param title Возвращает ссылку на dword для пользования
	*/
	word &return_reg_by_string(const std::string &);
	/*!
	\brief Пересылка данных.
	mov приемник, источник. 
	Базовая команда пересылки данных. Копирует содержимое источника в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void mov(const std::string &, const std::string &);
	/*!
	\brief Сложение данных.
	add приемник, источник.
	Складывает содержимое источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void add(const std::string &, const std::string &);
	/*!
	\brief Вычитание данных.
	sub приемник, источник.
	Вычитает содержимое источника из приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void sub(const std::string &, const std::string &);
	/*!
	\brief Операция xor.
	xor приемник, источник.
	Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void xor(const std::string &, const std::string &);
	/*!
	\brief Операция and.
	and приемник, источник.
	Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void and(const std::string &, const std::string &);
	/*!
	\brief Пересылка данных.
	cmp приемник, источник.
	Выполняет операцию сравнения источника и приемника, результат не изменяется, источник не изменяется.
	\param in приемник
	\param out источник
	\return 1 - равны, иначе - 0
	*/
	bool cmp(const std::string &, const std::string &);
	void add_integer(int, const std::string &);
	/*!
	\brief Запись в RAM.
	push источник.
	Записывает значение во временную память.
	\param in источник
	*/
	void push(const std::string &);
	/*!
	\brief Возврат из RAM.
	pop приемник.
	Возвращает значение из временной памяти.
	\param in приемник
	\return Байт, слово, или двйоное слово
	*/
	void pop(const std::string &);
	int comp(const std::string &);
	bool parser(const std::string &);
	bool file_parser();
	/*!
	\brief Проверка наличия.
	Проверяет, введен ли правильный регистр
	\param in 
	*/
	bool validator_parts(const std::string &);
	bool validator_reg(const std::string &);
	bool validator_command_double(const std::string &);
	bool validator_command(const std::string &);
	bool ROM_memory::validator_title(const std::string &);
	bool isint(const std::string &in);
	/*void ROM::save_in_file(); */
};

std::ostream & operator<<(std::ostream &out, word &rhs);



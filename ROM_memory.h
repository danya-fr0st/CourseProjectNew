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
	\brief ����� ���������

	���������� ������ � ���������� � ��������� �������� ������
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
	\brief ������� ��������.
	���������� ���� �� ������
	\param title ���������� ������ �� ���� ��� �����������
	*/
	byte &return_by_string(const std::string &);
	/*!
	\brief ������� ��������.
	���������� ������� �� ������
	\param title ���������� ������ �� dword ��� �����������
	*/
	word &return_reg_by_string(const std::string &);
	/*!
	\brief ��������� ������.
	mov ��������, ��������. 
	������� ������� ��������� ������. �������� ���������� ��������� � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void mov(const std::string &, const std::string &);
	/*!
	\brief �������� ������.
	add ��������, ��������.
	���������� ���������� ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void add(const std::string &, const std::string &);
	/*!
	\brief ��������� ������.
	sub ��������, ��������.
	�������� ���������� ��������� �� ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void sub(const std::string &, const std::string &);
	/*!
	\brief �������� xor.
	xor ��������, ��������.
	��������� �������� xor ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void xor(const std::string &, const std::string &);
	/*!
	\brief �������� and.
	and ��������, ��������.
	��������� �������� xor ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void and(const std::string &, const std::string &);
	/*!
	\brief ��������� ������.
	cmp ��������, ��������.
	��������� �������� ��������� ��������� � ���������, ��������� �� ����������, �������� �� ����������.
	\param in ��������
	\param out ��������
	\return 1 - �����, ����� - 0
	*/
	bool cmp(const std::string &, const std::string &);
	void add_integer(int, const std::string &);
	/*!
	\brief ������ � RAM.
	push ��������.
	���������� �������� �� ��������� ������.
	\param in ��������
	*/
	void push(const std::string &);
	/*!
	\brief ������� �� RAM.
	pop ��������.
	���������� �������� �� ��������� ������.
	\param in ��������
	\return ����, �����, ��� ������� �����
	*/
	void pop(const std::string &);
	int comp(const std::string &);
	bool parser(const std::string &);
	bool file_parser();
	/*!
	\brief �������� �������.
	���������, ������ �� ���������� �������
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



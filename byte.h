#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
/*!
\brief ����

���������� ��������� �����
*/
class byte
{
private:
	//int number_of_bytes;
	unsigned char array_of_bytes; ///<������������� ��������� �����
public:
	
	/*!
	\brief ������� �����������	
	*/
	byte();
	/*!
	\brief ���������������� �����������
	\param val ������������� ���� ���� ������
	*/
	byte(int);
	~byte();
	/*!
	\brief �������� �������� � ���������.
	���������� �� ��������� ������������ ����� � ����������� ��������
	\param in ����������� ������ �� ������, � ������� ����� ��������� ��������
	*/
	byte &operator += (const byte&);
	/*!
	\brief �������� ������������.
	���������� �� ��������� ���������� � ����������� �������� �����
	\param in �����, � ������� ����� ��������� �������� 
	*/
	byte &operator += (int);
	/*!
	\brief �������� ��������� � ���������.
	�������� �������� ������������ ����� � ����������� ��������
	\param in ����������� ������ �� ������, � ������� ����� ��������� ���������
	*/
	byte &operator -= (const byte&);
	/*!
	\brief �������� ��������� � ���������.
	�������� �������� ����������� ���������� � ����������� �������� �����
	\param in �����, � ������� ����� ��������� ���������
	*/
	byte &operator -= (int);
	/*!
	\brief �������� ������������.
	����������� �������� ������� �����
	\param in ����������� ������ �� ������, �������� �������� ����� �������� �������� �����
	*/
	byte &operator =(const byte&);
	/*!
	\brief �������� ������������.
	����������� �������� ���������� �����
	\param in �����, �������� �������� ����� �������� �������� �����
	*/
	byte &operator =(int);
	/*!
	\brief �������� and.
	��������� �������� and ��� ���� ������, ���������� �������� � ������� ����, ����������� �� ��������
	\param in ����������� ������ �� ������
	*/
	byte& operator &=(const byte&);
	/*!
	\brief �������� xor.
	��������� �������� xor ��� ���� ������, ���������� �������� � ������� ����, ����������� �� ��������
	\param in ����������� ������ �� ������
	*/
	byte& operator ^=(const byte&);
	/*!
	\brief ����������.
	���������� � int
	*/
	int convert_to_int() const;
	/*!
	\brief ��������.
	����������� ����
	*/
	void flip();
	/*!
	\brief ��������.
	����������� ��������� ���
	\param index �������� ������� ���� ����� ��������
	*/
	void flip(size_t);
	/*!
	\brief �����.
	�������� ����
	*/
	void reset();
	/*!
	\brief ��������� ����.
	������������� ��������� ��� � 0 ��� 1
	\param index ����� ������������� ����
	*/
	void setbit(int, bool);
	/*!
	\brief ��������� ����.
	���������� ��������� ���
	\param index ����� ������������� ����
	\return �������� ������������� ����
	*/
	bool getbit(int) const;
	/*!
	\brief �������� ���������.
	���������� 1, ���� ������� ����� � 0, ���� ���
	\param in ����������� ������ �� ������, � ������� ����� ��������� ���������
	*/
	bool operator== (const byte&) const;
	/*!
	\brief ������� ������� � ������
	*/
	unsigned char return_array() const;
	/*!
	\brief ������� ������� � ������.
	������� ��� ��������� �� ������
	*/
	unsigned char &return_array();
};
/*!
\brief �������� ������.
������� �������� �����
*/
std::ostream & operator<<(std::ostream &out, byte &rhs);
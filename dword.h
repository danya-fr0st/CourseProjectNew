#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "byte.h"

class dword
{
	byte array_of_bytes[4];

public:
	dword(int);
	dword();
	int convert_to_int() const;
	~dword();
	void flip();
	bool getbit(int) const;
	void setbit(int, bool);
	dword &operator =(const dword&);
	dword &operator =(int);
	void flip(size_t);
	void reset();
	bool operator== (const dword&) const;
	dword &operator += (const dword&);
	dword &operator += (int);
	dword &operator -= (const dword&);
	dword &operator -= (int);
	byte return_byte(size_t) const;
	byte & return_byte(size_t);
	dword(const byte&, const byte&, const byte&, const byte&);
	dword& operator ^=(const dword&);
	dword& operator &=(const dword&);

};

std::ostream & operator<<(std::ostream &out, dword &rhs);
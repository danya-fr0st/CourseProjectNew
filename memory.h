#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "byte.h"
#include "word.h"
#include "dword.h"

class memory 
{
	dword *data;
	char **title;
	int size;
	int count;
public:
	memory();
	~memory();
	void inc_data();
	void dec_data();
	void push(const dword &, const std::string &);
	void print_stack();
	int size_char(char*);
	bool validator(const std::string &);
	dword &return_by_string(const std::string &);
	int return_size()const;
	dword pop();
	
};

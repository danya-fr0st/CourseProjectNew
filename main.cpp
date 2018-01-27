#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "ROM_memory.h"
#include "word.h"
#include "service_registers.h"
#include "dword.h"
#include "memory.h"
#include <locale.h>

std::ostream & operator<<(std::ostream &out, word &rhs)
{
	for (int i = 15; i >= 0; --i)
		out << rhs.getbit(i);
	return out;
}


int main()
{
	ROM_memory test;
	std::string input;
	
	while (input != "end") 
	{
		std::cout << "Available assembly commands: " << std::endl 
				  << "mov, add, sub, cmp, push, pop, out, xor, and, dec, inc\n-------------\nIf you want to parse the file, use function 'open'"<< std::endl;
		std::cout << "-------------\nExample of using: " << std::endl 
				  << "mov AH 5\nmov BH 4\nout\n-------------"<< std::endl;
		std::cin >> input;
		test.parser(input);
		system("pause");
		system("cls");
	}
	
}

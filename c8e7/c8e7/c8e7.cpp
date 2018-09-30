// c8e7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main(int argc, char* argv[])
{
	bool in_error = false;
	while (*Driver::input)
	{
		try
		{
			Lexer::get_token();
			if (Lexer::curr_token == Lexer::END)break;
			if (Lexer::curr_token == Lexer::PRINT)
			{
				in_error = false;
				continue;
			}
			if (in_error == false) std::cout << Parser::expr(false) << '\n';
		}
		catch (Error::Zero_divide)
		{
			std::cerr << "attempt to divide by zero\n";
			in_error = true;
		}
	}
	if (Driver::input != &std::cin)delete Driver::input;
	return Error::no_of_errord;
}


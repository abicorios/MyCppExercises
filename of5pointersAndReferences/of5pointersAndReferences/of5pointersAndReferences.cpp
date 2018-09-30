// of5pointersAndReferences.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "about pointer_of_simbol\n";
	char simbol = 'a';
	std::cout << "my simbol is " << simbol << '\n';
	char*pointer_of_simbol = &simbol;
	std::cout << "pointer_of_simbol is "<< pointer_of_simbol << '\n';
	std::cout << "*pointer_of_simbol is " << *pointer_of_simbol << '\n';
	std::cout << '\n';

	std::cout << "about array_of_integers\n";
	const int length_of_array = 10;
	int array_of_integers[length_of_array];
	for (int i = 0; i < length_of_array; i++) array_of_integers[i] = i;
	std::cout <<"array_of_integers is "<< array_of_integers<< '\n';
	std::cout << "all array_of_integers[i] is ";
	for (int i = 0; i < length_of_array; i++) std::cout << array_of_integers[i]<<" ";
	std::cout << '\n';
	std::cout << '\n';

	std::cout << "about reference_to_array\n";
	int&reference_to_array = array_of_integers[0];
	std::cout << "reference_to_array is " << reference_to_array << " and it is equal to array_of_integers[0]\n";
	std::cout << "&reference_to_array is " << &reference_to_array << " and &array_of_integers[0] is " << &array_of_integers[0] << '\n';
	std::cout << "table &reference_to_array + k and *(&reference_to_array + k)\n";
	for(int k=0;k<length_of_array;k++)std::cout<<&reference_to_array+k<<'\t'<<*(&reference_to_array+k)<<'\n';

	std::cout << "about pointer_of_array\n";
	int*pointer_of_array = array_of_integers;//but it is the pointer of the start element of the array
	std::cout << "pointer_of_array is " << pointer_of_array << " and *pointer_of_array is " << *pointer_of_array << '\n';
	std::cout << "table pointer_of_array and *pointer_of_array\n";
	for (pointer_of_array; pointer_of_array != &array_of_integers[length_of_array]; pointer_of_array++) std::cout<< pointer_of_array<<'\t' << *pointer_of_array << '\n';
	std::cout << pointer_of_array << '\t' << *pointer_of_array <<" it is beyond array\n";
	
	std::cout << "\nabout pointer_of_array_of_strings\n";
	std::string array_of_strings[] = { "abc1","abc2","abc3" };
	std::string*pointer_of_array_of_strings = array_of_strings;
	std::cout << "pointer_of_array_of_strings is " << pointer_of_array_of_strings << '\n';

	std::cout << "\nabout pointer_of_pointer_of_simbol\n";
	char**pointer_of_pointer_of_simbol = &pointer_of_simbol;
	std::cout << "pointer_of_pointer_of_simbol is " << pointer_of_pointer_of_simbol << '\n';

	std::cout << "\nabout int_const\n";
	const int int_const = 20;
	std::cout << "int_const is " << int_const << '\n';

	std::cout << "\nabout pointer_of_int_const\n";
	const int*pointer_of_int_const = &int_const;
	std::cout << "pointer_of_int_const is " << pointer_of_int_const << '\n';

	std::cout << "\nabout const_pointer_of_int\n";
	int n = 10;
	int*const const_pointer_of_int = &n;
	std::cout << "const_pointer_of_int is " << const_pointer_of_int << '\n';
}


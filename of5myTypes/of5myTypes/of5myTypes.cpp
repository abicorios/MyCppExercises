// of5myTypes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	typedef unsigned char Uchar;
	typedef const Uchar CUchar;
	typedef int* Pint;
	typedef char** PPchar;
	typedef char char_array[];
	char_array a = { 'a','b' };
	std::cout << a[0]<<a[1];
	typedef char* Pchar_array;
	Pchar_array pca=&a[0];
	typedef int*array_of_seven_pointers_of_int[7];
	typedef int*array_of_three_pointers_of_int[3];
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	Pint p1 = &i1;
	Pint p2 = &i2;
	Pint p3 = &i3;
	array_of_three_pointers_of_int test = { &i1,&i1,&i1 };
	typedef array_of_seven_pointers_of_int* Parray_of_seven_pointers_of_int;
	array_of_seven_pointers_of_int array_of_seven_pointers_of_int1 = { &i1,&i1,&i1,&i1,&i1,&i1,&i1 };
	Parray_of_seven_pointers_of_int Parray_of_seven_pointers_of_int1 = &array_of_seven_pointers_of_int1;
	std::cout << '\n' << ***Parray_of_seven_pointers_of_int1<<'\t'<< **Parray_of_seven_pointers_of_int1<<'\t'<< *Parray_of_seven_pointers_of_int1<<'\t'<< Parray_of_seven_pointers_of_int1<<'\n';
	typedef array_of_seven_pointers_of_int array_of_eight_arrays_of_seven_pointers_of_int[8];
	array_of_eight_arrays_of_seven_pointers_of_int okay = { { &i3,&i2,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 },{ &i1,&i1,&i1,&i1,&i1,&i1,&i1 } };
	std::cout << *okay[0][1];

}


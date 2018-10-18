#pragma once

#include<iostream>
#include<string>
#include "../include/catalan.hpp"
using namespace std;
#include<Windows.h>							// Precise timer
#include<boost/multiprecision/cpp_int.hpp>	// Really big integers


// Set the integer type for the entire program.
using integer = boost::multiprecision::cpp_int;


/*!	\brief	Recursively compute factorial of 'n'
*/
integer rfactorial(integer const n) {
	if (n <= 1)
		return integer(1);
	else
		return n * rfactorial(n - 1);
}


/*!	\brief	Iteratively compute factorial of 'n'
*/
integer ifactorial(integer const& n) {
	integer product = 1;
	for (integer i = 2; i <= n; ++i)
		product *= i;
	return product;
}


/*!	\brief	Iteratively compute 'n'th power of 'base'
*/
integer ipower(integer const& base, unsigned exp) {
	integer product = 1;
	while (exp--)
		product *= base;
	return product;
}
/*!	\brief	Recursively compute 'n'th power of 'base'
*/
integer rpower(integer const& base, unsigned exp) {
	if (exp == 0)
		return integer(1);
	auto x = rpower(base, exp / 2);
	if (exp % 2 == 0)
		return x * x;
	else
		return base * x * x;
}


void PrintRace()
{

	integer const UPPER_LIMIT = 1000;

	for (int i = 0; i < UPPER_LIMIT; ++i)
	{
		catalan_bionomial(i);
	}

	for (int i = 0; i < UPPER_LIMIT; ++i)
	{
		catalan_product_series(i);
	}

#define TIME_TEST

#if defined(TIME_TEST)
	LARGE_INTEGER frequency, start, stop;
	QueryPerformanceFrequency(&frequency);

	integer n = 1'000;

	// Test the execution time of the iterative function
	QueryPerformanceCounter(&start);
	auto fn = catalan_bionomial(n);
	QueryPerformanceCounter(&stop);
	cpp_int timer1 = stop.QuadPart - start.QuadPart;
	std::cout << "\catalan_bionomial time = " << stop.QuadPart - start.QuadPart << std::endl;

	// Test the execution time of the recursive function
	QueryPerformanceCounter(&start);
	auto rfn = catalan_product_series(n);
	QueryPerformanceCounter(&stop);
	cpp_int timer2 = stop.QuadPart - start.QuadPart;
	std::cout << "\catalan_product_series time = " << stop.QuadPart - start.QuadPart << std::endl;



	// Check that the results match
	if (rfn == fn)
		std::cout << "Results match!\n";
	else
		std::cerr << "Results don't match!\n";

	if (timer1 > timer2)
		std::cout << "Winner is catalan_product_series faster than " << timer1 - timer2 << " ticks" << std::endl;
	else
		std::cout << "Winner is catalan_bionomial  faster than " << timer2 - timer1 << " ticks" << std::endl;
#endif
}
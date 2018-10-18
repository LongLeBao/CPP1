#pragma once
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

/*!	\file	pell.hpp
	\author	Le Bao Long Tran
	\date	Development date
	\brief	Student's Pell number function implementations.
*/


// ToDo:implement the pell() and rpell() functions.
boost::multiprecision::cpp_int pell(boost::multiprecision::cpp_int n)
{
	boost::multiprecision::cpp_int  a = 1, b = 0, c;

	c = 0;
	for (auto i = 1; i <= n; i++)
	{
		c = a + 2 * b;

		a = b;
		b = c;
	}
	return b;
}
template <typename T>
T rpell(T n)
{
	if (n == 0 || n == 1)
		return n;
	return 2 * rpell(n - 1) + rpell(n - 2);
}
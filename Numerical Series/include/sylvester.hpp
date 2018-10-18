#pragma once
#include <valarray>
#include <boost/multiprecision/cpp_int.hpp>

/*!	\file	sylvester.hpp
	\author	Le Bao Long Tran
	\date	Development date
	\brief	Student's Sylvester number function implementations.
*/


// ToDo:implement the sylvester() and rsylvester() functions.

using namespace boost::multiprecision;


cpp_int sylvester(const cpp_int n)
{
	cpp_int a = 2, c;
	c = 2;
	for (auto i = 1; i <= n; i++)
	{

		c = a * a - a + 1;
		a = c;

	}
	return c;
}


cpp_int rsylvester(const cpp_int n)
{

	if (n == 0)
		return 2;
	return rsylvester(n - 1)*rsylvester(n - 1) - rsylvester(n - 1) + 1;

}
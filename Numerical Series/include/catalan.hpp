#pragma once
/*!	\file	catalan.hpp
	\author	Le Bao Long Tran
	\date	Development date
	\brief	Student's Catalan number function implementations.
*/

// import the boost multiprecision integer library
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// ToDo:implement the catalan_bionomial() and catalan_product_series() functions.

cpp_int binomialCoeff(cpp_int n, cpp_int k)
{
	cpp_int res = 1;

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k)
		k = n - k;

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (auto i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}


cpp_int catalan_bionomial(cpp_int n)
{
	// Calculate value of 2nCn 
	const cpp_int c = binomialCoeff(2 * n, n);

	// return 2nCn/(n+1) 
	return c / (n + 1);
}

cpp_int catalan_product_series(const cpp_int& n)
{
	if (n <= 1)
		return 1;
	cpp_int sumNum = 1;
	cpp_int sumDen = 1;
	for (cpp_int i = 2; i <= (n); ++i)
	{
		sumNum *= (n + i);
		sumDen *= i;
	}
	const cpp_int sum = sumNum / sumDen;
	return static_cast<cpp_int>(sum);
}
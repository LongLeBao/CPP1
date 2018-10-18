#pragma once

#include "../include/pell.hpp"
#include "../include/sylvester.hpp"
#include "../include/catalan.hpp"
#include <cstdint>

#include <limits>
#include <cstddef>
#include <iostream>
#include <string>
#include <boost/limits.hpp>

#include<boost/multiprecision/cpp_int.hpp>
#include <boost/math/tools/precision.hpp>


using namespace boost::multiprecision;

using integer = boost::multiprecision::cpp_int;



void PrintAll()
{
	

	int16_t limitInt16 = std::numeric_limits<int16_t >::max();
	int32_t limitInt32 = std::numeric_limits<int32_t >::max();
	int64_t limitInt64 = std::numeric_limits<int64_t >::max();

	uint16_t limitUint16 = std::numeric_limits<uint16_t >::max();
	uint32_t limitUint32 = std::numeric_limits<uint32_t >::max();
	uint64_t limitUint64 = std::numeric_limits<uint64_t >::max();

	const uint128_t limitUint128 = boost::math::tools::max_value<uint128_t>();
	const uint128_t limitInt128 = static_cast<uint128_t>(pow(2, 127) - 1);

	cpp_int biggestInt16 = 1;
	cpp_int biggestInt32 = 1;
	cpp_int biggestInt64 = 1;
	cpp_int biggestInt128 = 1;

	cpp_int biggestUint16 = 1;
	cpp_int biggestUint32 = 1;
	cpp_int biggestUint64 = 1;
	cpp_int biggestUint128 = 1;

	int countSpace = 1;

	cpp_int takeValue;

	unsigned num16s = 0, num16u = 0, num32s = 0, num32u = 0, num64s = 0, num64u = 0, num128s = 0, num128u = 0;

	constexpr unsigned liMit = 1000;

	std::cout << "pell limits\n";
	std::cout << "================\n";



	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitInt16)
		{
			num16s++;
			biggestInt16 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitInt32)
		{
			num32s++;
			biggestInt32 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitInt64)
		{
			num64s++;
			biggestInt64 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitInt128)
		{
			num128s++;
			biggestInt128 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitUint16)
		{
			num16u++;
			biggestUint16 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitUint32)
		{
			num32u++;
			biggestUint32 = pell(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitUint64)
		{
			num64u++;
			biggestUint64 = pell(i);
		}
		else
			break;
	}



	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (pell(i) <= limitUint128)
		{
			num128u++;
			biggestUint128 = pell(i);
		}
		else
			break;
	}

	takeValue = biggestUint128;

	while (takeValue /= 10)
		countSpace++;

	std::cout << std::setw(countSpace) << std::right << biggestInt16 << " = pell(" << --num16s << ") ->  16-bit signed : " << limitInt16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt32 << " = pell(" << --num32s << ") ->  32-bit signed : " << limitInt32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt64 << " = pell(" << --num64s << ") ->  64-bit signed : " << limitInt64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt128 << " = pell(" << --num128s << ") ->  128-bit signed : " << limitInt128 << std::endl;

	std::cout << std::setw(countSpace) << std::right << biggestUint16 << " = pell(" << --num16u << ") ->  16-bit unsigned : " << limitUint16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint32 << " = pell(" << --num32u << ") ->  32-bit unsigned : " << limitUint32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint64 << " = pell(" << --num64u << ") ->  64-bit unsigned : " << limitUint64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint128 << " = pell(" << --num128u << ") ->  128-bit unsigned : " << limitUint128 << std::endl;


	std::cout << std::endl;
	std::cout << "sylvester limits\n";
	std::cout << "================\n";

	biggestInt16 = 1;
	biggestInt32 = 1;
	biggestInt64 = 1;
	biggestInt128 = 1;

	biggestUint16 = 1;
	biggestUint32 = 1;
	biggestUint64 = 1;
	biggestUint128 = 1;

	countSpace = 1;

	num16s = 0, num16u = 0, num32s = 0, num32u = 0, num64s = 0, num64u = 0, num128s = 0, num128u = 0;

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitInt16)
		{
			num16s++;
			biggestInt16 = sylvester(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitInt32)
		{
			num32s++;
			biggestInt32 = sylvester(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitInt64)
		{
			num64s++;
			biggestInt64 = sylvester(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitInt128)
		{
			num128s++;
			biggestInt128 = sylvester(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitUint16)
		{
			num16u++;
			biggestUint16 = sylvester(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitUint32)
		{
			num32u++;
			biggestUint32 = sylvester(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitUint64)
		{
			num64u++;
			biggestUint64 = sylvester(i);
		}
		else
			break;
	}

	
	
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (sylvester(i) <= limitUint128)
		{
			num128u++;
			biggestUint128 = sylvester(i);
		}
		else
			break;
	}
	takeValue = biggestInt128;

	while (takeValue /= 10)
		countSpace++;

	std::cout << std::setw(countSpace) << std::right << biggestInt16 << " = sylvester(" << --num16s << ") ->  16-bit signed : " << limitInt16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt32 << " = sylvester(" << --num32s << ") ->  32-bit signed : " << limitInt32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt64 << " = sylvester(" << --num64s << ") ->  64-bit signed : " << limitInt64 << std::endl;
	//std::cout << "limit of signed 64 integers is          : " << limitInt64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt128 << " = sylvester(" << --num128s << ") ->  128-bit signed : " << limitInt128 << std::endl;

	std::cout << std::setw(countSpace) << std::right << biggestUint16 << " = sylvester(" << --num16u << ") ->  16-bit unsigned : " << limitUint16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint32 << " = sylvester(" << --num32u << ") ->  32-bit unsigned : " << limitUint32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint64 << " = sylvester(" << --num64u << ") ->  64-bit unsigned : " << limitUint64 << std::endl;
	//std::cout << "limit of unsigned 64 integers is          : " << limitUint64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint128 << " = sylvester(" << --num128u << ") ->  128-bit unsigned : " << limitUint128 << std::endl;


	std::cout << std::endl;
	std::cout << "catalan limits\n";
	std::cout << "================\n";


	biggestInt16 = 1;
	biggestInt32 = 1;
	biggestInt64 = 1;
	biggestInt128 = 1;

	biggestUint16 = 1;
	biggestUint32 = 1;
	biggestUint64 = 1;
	biggestUint128 = 1;

	countSpace = 1;

	num16s = 0, num16u = 0, num32s = 0, num32u = 0, num64s = 0, num64u = 0, num128s = 0, num128u = 0;

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitInt16)
		{
			num16s++;
			biggestInt16 = catalan_product_series(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitInt32)
		{
			num32s++;
			biggestInt32 = catalan_product_series(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitInt64)
		{
			num64s++;
			biggestInt64 = catalan_product_series(i);
		}
		else
			break;
	}
	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitInt128)
		{
			num128s++;
			biggestInt128 = catalan_product_series(i);
		}
			
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitUint16)
		{
			num16u++;
			biggestUint16 = catalan_product_series(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitUint32)
		{
			num32u++;
			biggestUint32 = catalan_product_series(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitUint64)
		{
			num64u++;
			biggestUint64 = catalan_product_series(i);
		}
		else
			break;
	}

	for (unsigned i = 0; i <= liMit; ++i)
	{
		if (catalan_product_series(i) <= limitUint128)
		{
			num128u++;
			biggestUint128 = catalan_product_series(i);
		}
		else
			break;
	}

	takeValue = biggestUint128;

	while (takeValue /= 10)
		countSpace++;

	std::cout << std::setw(countSpace) << std::right << biggestInt16 << " = catalan(" << --num16s << ") ->  16-bit signed : " << limitInt16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt32 << " = catalan(" << --num32s << ") ->  32-bit signed : " << limitInt32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt64 << " = catalan(" << --num64s << ") ->  64-bit signed : " << limitInt64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestInt128 << " = catalan(" << --num128s << ") ->  128-bit signed : " << limitInt128 << std::endl;

	std::cout << std::setw(countSpace) << std::right << biggestUint16 << " = catalan(" << --num16u << ") ->  16-bit unsigned : " << limitUint16 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint32 << " = catalan(" << --num32u << ") ->  32-bit unsigned : " << limitUint32 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint64 << " = catalan(" << --num64u << ") ->  64-bit unsigned : " << limitUint64 << std::endl;
	std::cout << std::setw(countSpace) << std::right << biggestUint128 << " = catalan(" << --num128u << ") ->  128-bit unsigned : " << limitUint128 << std::endl;
}

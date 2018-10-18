#pragma once

#include "../include/pell.hpp"
#include "../include/sylvester.hpp"
#include "../include/catalan.hpp"
#include <cstdint>

#include <limits>
#include <cstddef>
#include <iostream>
#include <string>
#include "PrintLimit.h"
#include "PrintRaceCatalan.h"
#include<boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int main()
{

	PrintAll();
	std::cout << std::endl;
	PrintRace();
	return 0;
}

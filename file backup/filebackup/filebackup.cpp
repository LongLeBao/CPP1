#include <iostream>
#include "filebackup.h"

int main(int argc, char* argv[])
{

	std::cout << "File Backup Program -- Lee" << std::endl;

	if (argc == 0)
	{
		FileManagement fm;
		fm.backup();
		fm.report();

	}
	else if (argc == 1)
	{
		FileManagement fm;
		fm.backup();
		fm.report();
	}
	else if (argc == 2)
	{
		FileManagement fm(argv[1]);
		fm.backup();
		fm.report();

	}
	else if (argc == 3)
	{
		FileManagement fm(argv[1], argv[2]);
		fm.backup();
		fm.report();

	}
	else if (argc >= 3)
	{
		std::cout << "You Enter the wrong syntax. Try again!\n";
		return 1;
	}
	std::cin.get();

}

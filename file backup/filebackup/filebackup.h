#pragma once
#include <string>
#include <experimental/filesystem>
#include <locale>
#include <iostream>
#include <iomanip>

class FileManagement
{
	std::experimental::filesystem::path sourceDirectory_ =".";
	std::experimental::filesystem::path backupDirectory_;
public:
	std::vector<std::string> storeFile;
	std::vector<std::string> storeFileSameName;
	std::vector<uintmax_t> storeFilenumber;
	std::vector<uintmax_t> storeFileSameNumber;
	uint64_t s = 0;
	int count = 0;

	void backup();
	void report();

	FileManagement(FileManagement const &) = default;
	FileManagement& operator = (FileManagement const &) = default;

	FileManagement(FileManagement &&) = delete; // disables move construtor
	FileManagement(FileManagement const &&) = delete; // disables const move construtor

	FileManagement operator=(FileManagement &&) = delete; // disables move assignment operator
	FileManagement& operator=(FileManagement const &&) = delete; // disables const move assignment operator

	FileManagement() : sourceDirectory_("."), backupDirectory_("c:\\backup") { }
	FileManagement(std::experimental::filesystem::path const & copyFrom);
	FileManagement(std::experimental::filesystem::path const &, std::experimental::filesystem::path const &);
};

//backup method to copy all files have extension .hpp .h .cpp .c
inline void FileManagement::backup()
{
	for (auto & d : std::experimental::filesystem::recursive_directory_iterator(sourceDirectory_)) {
		const std::string findThem = d.path().extension().string();
		if (findThem == ".hpp" || findThem == ".cpp" || findThem == ".h" || findThem == ".c")
		{
			std::experimental::filesystem::path destination =
				backupDirectory_.string() + "\\" + d.path().filename().string();

			if (!std::experimental::filesystem::exists(destination))
			{

				std::experimental::filesystem::copy_file(d.path(), destination);

				storeFile.push_back(d.path().filename().string());
				storeFilenumber.push_back(std::experimental::filesystem::file_size(d));
				s += std::experimental::filesystem::file_size(d);
				count++;
			}
			else
			{
				storeFileSameName.push_back(d.path().filename().string());
				storeFileSameNumber.push_back(std::experimental::filesystem::file_size(d));
			}
		}
	}
	std::cout << "\ncopy succeeded\n";
}

//report method to report all files copy or not copy and size of files
inline void FileManagement::report()
{
	std::cout.imbue(std::locale(""));
	std::cout << "Report\n";
	std::cout << "Root Directory: " << std::experimental::filesystem::absolute(sourceDirectory_) << std::endl;

	std::cout << "Backup Directory: " << std::experimental::filesystem::absolute(backupDirectory_) << std::endl;
	std::cout << std::endl;

	std::string longest;

	for (unsigned i = 0; i < storeFile.size(); ++i)
	{
		if (storeFile[i].length() > longest.length())
			longest = storeFile[i];
	}
	for (unsigned i = 0; i < storeFileSameName.size(); ++i)
	{
		if (storeFileSameName[i].length() > longest.length())
			longest = storeFileSameName[i];
	}
	
	for (unsigned i = 0; i < storeFile.size(); ++i)
	{
		std::cout << "+ " << std::right << std::setw(longest.length()) << storeFile[i];
		std::cout << std::right << std::setw(longest.length()) << "Size: " << storeFilenumber[i] << std::endl;
	}

	for (unsigned i = 0; i < storeFileSameName.size(); ++i)
	{
		std::cout << "- " << std::right << std::setw(longest.length()) << storeFileSameName[i];
		std::cout << std::right << std::setw(longest.length()) << "Size: " << storeFileSameNumber[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Backup Total: " << std::right << std::setw(longest.length()-2) << count << " files" << std::endl;
	//std::cout << std::right << std::setw(longest.length()) << "Size: " << s << std::endl;
	std::cout << "Size Total: " << std::right << std::setw(longest.length()) << s << " bytes" << std::endl;
}

inline FileManagement::FileManagement(std::experimental::filesystem::path const& copyFrom)
{
	sourceDirectory_ = copyFrom;
	backupDirectory_ = "c:\\backup";
}

inline FileManagement::FileManagement(std::experimental::filesystem::path const & source,
	std::experimental::filesystem::path const & destination)
{
	sourceDirectory_ = source;
	backupDirectory_ = destination;
}
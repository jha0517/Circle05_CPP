#include <iostream>

void    print_red(std::string const str)
{
	std::cout << "\033[1;31m"<< str << "\033[0m" << std::endl;
}

void    print_yellow(std::string const str)
{
	std::cout << std::endl << "\033[1;33m"<< str << "\033[0m" << std::endl;
}

void    print_green(std::string const str)
{
	std::cout << std::endl << "\033[1;32m"<< str << "\033[0m" << std::endl;

}

void    print_blue(std::string const str)
{
	std::cout << std::endl << "\033[1;34m"<< str << "\033[0m" << std::endl;

}
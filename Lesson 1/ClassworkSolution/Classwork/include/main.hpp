#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

template<typename Container>
void PrintContainer(const Container& c)
{
	for (auto value : c)
	{
		std::cout << value << " ";
	}
	std::cout << "\n";
}

#endif
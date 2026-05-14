#include <iostream>
#include "../include/main.hpp"

bool Func(std::mutex& m)
{
	std::unique_lock<std::mutex> ul(m, std::defer_lock);

	if (ul.owns_lock())
	{
		std::cout << "Own\n";
	}
	else
	{
		std::cout << "Not own\n";
	}

	return true;
}

int main()
{
	std::mutex m;
	Func(m);

	return 0;
}

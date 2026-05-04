#include <iostream>
#include "../include/HomeTaskLambda.hpp"

int main()
{
	std::vector<int> vctr{ 1, 2, 3, 4, 5, 6, 7 };
	HomeTaskLambda(vctr, 10);

	for (int const x : vctr)
	{
		std::cout << x << "\n";
	}

    return 0;
}

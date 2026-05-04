#include "../include/HomeTaskLambda.hpp"

void HomeTaskLambda(std::vector<int>& container, int const value)
{
	auto lambda = [&](int const val)
		{
			for (auto& x : container)
			{
				x += val;
			}
		};

	lambda(value);
}

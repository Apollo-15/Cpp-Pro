#include <iostream>
#include <thread>
#include "../include/main.hpp"

void FillRandomNumbers(std::vector<int>& vtr, size_t count)
{
    vtr.clear();
    for (size_t i = 0; i < count; i++)
    {
	    vtr.push_back(rand() % 100 + 1);
    }
}

void AddNext(std::vector<int>& vtr)
{
	for (size_t i = 0; i + 1 < vtr.size(); i++)
	{
        vtr[i] += vtr[i + 1];
	}
}

void VectorHandler::Handle(std::vector<int>& vtr)
{
	for (int x : vtr)
	{
		if (x % 2 == 0)
		{
			std::cout << x / 2 << "\n";
		}
		else
		{
			std::cout << x << "\n";
		}
	}
}


int main()
{
	std::vector<int> data;
	VectorHandler handler;

	std::thread t1(FillRandomNumbers, std::ref(data), 10);
	t1.join();

	std::thread t2(AddNext, std::ref(data));
	t2.join();

	std::thread t3(&VectorHandler::Handle, &handler, std::ref(data));
	t3.join();

    return 0;
}
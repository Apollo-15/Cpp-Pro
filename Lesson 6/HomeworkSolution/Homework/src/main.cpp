#include <iostream>
#include "../include/main.hpp"

#include <thread>
#include <vector>

void ThreadsRange(std::vector<int>& vctr, size_t const start, size_t const rangeEnd, int const addValue)
{
	for (size_t i = start; i < rangeEnd; ++i)
	{
		vctr[i] += addValue;
	}
}

int main()
{
	std::vector <int> myVector(1000, 10);

	int constexpr addValue = 1;
	
	size_t const size = myVector.size();
	size_t const firstQuarterOfVector = size; // end (100% | 1000) 
	size_t const secondQuarterOfVector = size * 3 / 4; // end | start (75% | 1000 * 3 = 3000 / 4 = 750)
	size_t const thirdQuarterOfVector = size * 2 / 4; // end | start (50% | 1000 * 2 = 2000 / 4 = 500)
	size_t const fourthQuarterOfVector = size / 4; // start (25% | 1000 / 4 = 250)

	std::cout << "Thread ranges:\n";
	std::cout << "First Quarter of Vector: 0 -> " << fourthQuarterOfVector << "\n";
	std::cout << "Second Quarter of Vector: " << fourthQuarterOfVector << " -> " << thirdQuarterOfVector << "\n";
	std::cout << "Third Quarter of Vector:: " << thirdQuarterOfVector << " -> " << secondQuarterOfVector << "\n";
	std::cout << "Fourth Quarter of Vector: " << secondQuarterOfVector << " -> " << firstQuarterOfVector << "\n\n";

	std::cout << "Before multithreading:\n";
	std::cout << "First Quarter of Vector: " << myVector[0] << "\n";
	std::cout << "Second Quarter of Vector: " << myVector[fourthQuarterOfVector] << "\n";
	std::cout << "Third Quarter of Vector: " << myVector[thirdQuarterOfVector] << "\n";
	std::cout << "Fourth Quarter of Vector: " << myVector[secondQuarterOfVector] << "\n\n";

	std::thread fourthThread(ThreadsRange, std::ref(myVector), secondQuarterOfVector, firstQuarterOfVector, addValue);
	std::thread thirdThread(ThreadsRange, std::ref(myVector), thirdQuarterOfVector, secondQuarterOfVector, addValue);
	std::thread secondThread(ThreadsRange, std::ref(myVector), fourthQuarterOfVector, thirdQuarterOfVector, addValue);
	std::thread firstThread(ThreadsRange, std::ref(myVector), 0, fourthQuarterOfVector, addValue);

	firstThread.join();
	secondThread.join();
	thirdThread.join();
	fourthThread.join();

	std::cout << "After multithreading:\n";
	std::cout << "First Quarter of Vector: " << myVector[0] << "\n";
	std::cout << "Second Quarter of Vector: " << myVector[fourthQuarterOfVector] << "\n";
	std::cout << "Third Quarter of Vector: " << myVector[thirdQuarterOfVector] << "\n";
	std::cout << "Fourth Quarter of Vector: " << myVector[secondQuarterOfVector] << "\n\n";

	return 0;
}

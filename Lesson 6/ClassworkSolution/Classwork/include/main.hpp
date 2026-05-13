#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>

class VectorHandler
{
public:
	void Handle(std::vector<int>& vtr);
};

void FillRandomNumbers(std::vector<int>& vtr, size_t count);
void AddNext(std::vector<int>& vtr);


#endif
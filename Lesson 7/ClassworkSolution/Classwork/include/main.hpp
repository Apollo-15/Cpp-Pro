#ifndef MAIN_HPP
#define MAIN_HPP

#include <list>
#include <mutex>

class CList
{
private:
	std::mutex m_mt;
	std::list<int> m_arr;

public:
	CList() = default;

	void Add(int value);
	void Add(const std::list<int>& list);

	void GetFrontElem(int& value);

	~CList();
};

void Print(int numberOfThread, CList& list);

void FillRandomNumbers(std::list<int>& list, size_t count);

#endif
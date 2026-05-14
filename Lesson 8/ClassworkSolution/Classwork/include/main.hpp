#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <mutex>
#include <vector>

bool Func(std::mutex& m, std::vector<int>& v);
void Thread(std::mutex& m, std::vector<int>& v);
void FillRandomNumbers(std::vector<int>& v, size_t count);

#endif
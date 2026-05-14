#ifndef MAIN_HPP
#define MAIN_HPP

#include <mutex>
#include <vector>

void Func(std::mutex& m, std::vector<int>& v, size_t& szCount);
size_t InnerFunc(std::mutex& m, std::vector<int>& v, size_t index, size_t& szCount);
#endif
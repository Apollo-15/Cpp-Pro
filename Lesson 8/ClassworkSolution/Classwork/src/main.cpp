#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

void InnerFunc(std::mutex& m, std::vector<int>& v, size_t index, size_t& szCount)
{
    std::lock_guard<std::mutex> lg(m);

    while (true)
    {
        if (v[index] != 0)
        {
            ++szCount;
            v[index] = 0;
            return;
        }
        ++index;
        if (index == v.size())
        {
            return;
        }
    }
}

void Func(std::mutex& m, std::vector<int>& v, size_t& szCount)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        InnerFunc(m, v, i, szCount);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main()
{
    std::vector<int> v;
    std::mutex m;

    for (size_t i = 0; i < 100; ++i)
    {
        v.push_back(rand() % 555 + 1);
    }

    size_t szCount1 = 0;
    size_t szCount2 = 0;

    std::thread th1(Func, std::ref(m), std::ref(v), std::ref(szCount1));
    std::thread th2(Func, std::ref(m), std::ref(v), std::ref(szCount2));

    th1.join();
    th2.join();

    std::cout << "Counts: " << szCount1 + szCount2 << "\n\n";

    return 0;
}
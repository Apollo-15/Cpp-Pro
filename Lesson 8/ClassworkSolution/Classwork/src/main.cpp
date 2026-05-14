#include <iostream>
#include "../include/main.hpp"

bool Func(std::mutex& m, std::vector<int>& v)
{
    std::lock_guard<std::mutex> lc(m);
    for (int& x : v)
    {
        if (x != 0)
        {
            x = 0;
            return true;
        }
    }
    return false;
}

void Thread(std::mutex& m, std::vector<int>& v)
{
    while (Func(m, v))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void FillRandomNumbers(std::vector<int>& v, size_t const count)
{
    v.clear();
    for (size_t i = 0; i < count; i++)
    {
	    v.push_back(rand() % 12345 + 1);
    }
}


int main()
{
	std::mutex m;
    std::vector<int> v;

    FillRandomNumbers(v, 1234);

    std::thread firstThread(Thread, std::ref(m), std::ref(v));
    std::thread secondThread(Thread, std::ref(m), std::ref(v));

    firstThread.join();
    secondThread.join();

    for (int x : v)
    {
	    std::cout << x << "\n";
    }

	return 0;
}

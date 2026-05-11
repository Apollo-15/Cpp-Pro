#include <iostream>
#include "../include/main.hpp"

#include <mutex>
#include <thread>


void Print(int& value, std::mutex& mt, int num)
{
    for (size_t i = 0; i < 1000; i++)
    {
	    if (mt.try_lock())
	    {
		    value = num;
		    std::cout << value << "\n";
		    mt.unlock();
	    }
	    else
	    {
		    std::cout << "Not locked\n";
	    }

    }
}

int main()
{
    int value;
    std::mutex mt;

    std::thread th1(Print, std::ref(value), std::ref(mt), 11111);
    std::thread th2(Print, std::ref(value), std::ref(mt), 22222);
    std::thread th3(Print, std::ref(value), std::ref(mt), 33333);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
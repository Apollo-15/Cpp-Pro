#include "../include/Vector.hpp"

int main()
{
    my_vector::Vector<int> v;

    for (int i = 0; i < 5; ++i)
    {
        v.PushBack(i * 10);
    }

    std::cout << "Vector using operator[]:\n";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Vector using At():\n";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v.At(i) << " ";
    }
    std::cout << "\n";

    try
    {
        std::cout << "Accessing out-of-bounds index:\n";
        std::cout << v.At(100) << "\n";
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    my_vector::Vector<int> v2 = v;

    std::cout << "Copied vector:\n";
    for (size_t i = 0; i < v2.size(); ++i)
    {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n";

    v.Clear();
    std::cout << "Size after Clear(): " << v.size() << "\n";

    return 0;
}
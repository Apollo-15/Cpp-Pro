#include <iostream>
#include <vector>
#include <list>

#include "../include/main.hpp"

int main()
{
    std::vector<int> const sourceContainer = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::list<int> destinationContainer;

    for (auto value : sourceContainer)
    {
        destinationContainer.push_back(value);
    }

    PrintContainer(destinationContainer);

    auto const copiedContainer = destinationContainer;

    PrintContainer(copiedContainer);

    return 0;
}

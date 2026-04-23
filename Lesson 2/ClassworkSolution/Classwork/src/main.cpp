#include "../include/A.hpp"

int main()
{
    A cA;
    A cB(std::move(cA));

    A cC;
    cC = cB;

    A cD;
    cD = std::move(cC);

    return 0;
}

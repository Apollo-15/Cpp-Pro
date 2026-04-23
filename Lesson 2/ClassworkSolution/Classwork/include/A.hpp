#ifndef A_HPP
#define A_HPP

#include <iostream>

class A
{
private:
    int m_a = 0;
    int* m_pPointerToSomething = nullptr;

public:
    A();
    A(const A& obj);
    A(A&& obj) noexcept;

    A& operator=(const A& obj);
    A& operator=(A&& obj) noexcept;
    
	~A();
};

#endif
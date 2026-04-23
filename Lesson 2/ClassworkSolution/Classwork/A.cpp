#include "include/A.hpp"

A::A()
{
    std::cout << "Constructor A: " << this << "\n";
}

A::A(const A& obj)
{
    std::cout << "Constructor of copy A: " << this << "\n";

    m_a = obj.m_a;

    if (obj.m_pPointerToSomething)
        m_pPointerToSomething = new int(*obj.m_pPointerToSomething);
}

A::A(A&& obj) noexcept
{
    std::cout << "Constructor of move A: " << this << "\n";

    m_a = obj.m_a;

    m_pPointerToSomething = obj.m_pPointerToSomething;
    obj.m_pPointerToSomething = nullptr;
}

A::~A()
{
    delete m_pPointerToSomething;
}

A& A::operator=(const A& obj)
{
    if (this != &obj)
    {
        m_a = obj.m_a;

        delete m_pPointerToSomething;
        m_pPointerToSomething = obj.m_pPointerToSomething
            ? new int(*obj.m_pPointerToSomething)
            : nullptr;
    }

    return *this;
}

A& A::operator=(A&& obj) noexcept
{
    delete m_pPointerToSomething;

    m_a = obj.m_a;

    m_pPointerToSomething = obj.m_pPointerToSomething;
    obj.m_pPointerToSomething = nullptr;

    return *this;
}

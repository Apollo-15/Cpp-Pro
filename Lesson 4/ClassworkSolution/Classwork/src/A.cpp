#include "../include/A.hpp"
#include <iostream>

A::A() { std::cout << "Constructor: " << this << "\n"; }
A::~A() { std::cout << "Destructor: " << this << "\n "; }

void A::Test() const { std::cout << m_a << "\n"; }

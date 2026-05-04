#ifndef A_HPP
#define A_HPP

#include <iostream>

class A
{
private:
	int m_a = 10;

public:
	A();
	~A();

	void Test() const;
};

#endif
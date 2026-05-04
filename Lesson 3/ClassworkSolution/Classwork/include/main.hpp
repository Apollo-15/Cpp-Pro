#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>

class FullNameFunctor
{
private:
	std::string m_name;
	std::string m_surname;

public:
	FullNameFunctor(std::string name, std::string surname)
		: m_name(std::move(name)),
		  m_surname(std::move(surname))
	{
	}

	std::string operator()() const
	{
		return m_name + " " + m_surname;
	}
};

class AddToNameFunctor
{
private:
	std::string& m_name;
	std::string m_surname;

public:
	AddToNameFunctor(std::string& name, std::string surname)
		: m_name(name),
		  m_surname(std::move(surname))
	{
	}

	void operator()()
	{
		m_name += m_surname;
	}
};

void Func(void (*f)());

#endif
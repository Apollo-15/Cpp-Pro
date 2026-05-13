#ifndef MAIN
#define MAIN

#include <iostream>

class Teacher;

class Student
{
private:
	std::weak_ptr<Teacher> m_pTeacher;
public:
	Student() { std::cout << "Constructor Student:" << this << "\n"; }
	~Student() { std::cout << "Destructor Student:" << this << "\n"; }

	friend void Link(std::shared_ptr<Teacher>& pTeacher, std::shared_ptr<Student>& pStudent);
};

class Teacher
{
private:
	std::weak_ptr<Student> m_pStudent;
public:
	Teacher() { std::cout << "Constructor Teacher:" << this << "\n"; }
	~Teacher() { std::cout << "Destructor Teacher:" << this << "\n"; }

	friend void Link(std::shared_ptr<Teacher>& pTeacher, std::shared_ptr<Student>& pStudent);
};

void Link(std::shared_ptr<Teacher>& pTeacher, std::shared_ptr<Student>& pStudent)
{
	pTeacher->m_pStudent = pStudent;
	pStudent->m_pTeacher = pTeacher;

	auto& wptr = pStudent->m_pTeacher;

	if (!wptr.expired())
	{
		auto tmp = wptr.lock();
	}
}

#endif
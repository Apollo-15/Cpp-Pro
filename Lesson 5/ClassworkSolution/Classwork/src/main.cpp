#include <iostream>
#include "../include/smart_shared_ptr.hpp"
#include "../include/main.hpp"

int main()
{
    auto studentJason = std::make_shared<Student>();
    auto teacherJack = std::make_shared<Teacher>();

    Link(teacherJack, studentJason);

    return 0;
}

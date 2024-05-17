#include "Student.h"
#include <iostream>

int Student::next_no{0};

Student::Student(const std::string &name_) : no(next_no++), name(name_) {}

Student::Student(std::string &&name_) : no(next_no++), name(std::move(name_)) {}

Student::Student(const Student &stu) : no(stu.no), name(stu.name) {}

Student &Student::operator=(const Student &rhs)
{
    no = rhs.no;
    name = rhs.name;   
    return *this;
}

Student::~Student() {}

Student::Student(Student &&stu)
{
    no = std::move(stu.no);
    name = std::move(stu.name);
}

Student &Student::operator=(Student && rhs)
{
    if (this != &rhs)
    {
        no = std::move(rhs.no);
        name = std::move(rhs.name);
    }
    return *this;
}

Student operator+(const Student& lhs, const Student& rhs)
{
    return Student{lhs.name + rhs.name};
}

std::ostream& operator<<(std::ostream& ostrm, const Student& s)
{
    ostrm << "No: " << s.no << "\tName: " << s.name << std::endl;
    return ostrm;
}

Student& Student::operator>>(const std::string& name_)
{
    name = name_;
    return *this;
}

Student& Student::operator>>(std::string&& name_)
{
    name = std::move(name_);
    return *this;
}

Student& Student::operator<<(const std::string& msg)
{
    print();
    std::cout << "\t" << msg << std::endl;
    return *this;
}

Student& Student::operator<<(std::string&& msg)
{
    print();
    std::cout << "\t" << std::move(msg) << std::endl;
    return *this;
}

Student& Student::operator+=(const Student& rhs)
{
    *this = *this + rhs;
    return *this;
}

void Student::print()
{
    std::cout << "No: " << no << "\tName: " << name << std::endl;
}

int main()
{
    Student s1("Mike");
    Student s2("Jack");
    (s1 + s2).print();
    std::cout << (s1 + s2);

}
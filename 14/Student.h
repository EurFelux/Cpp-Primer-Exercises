#include <string>
#include <iostream>

class Student {
public:
    Student(const std::string&);
    Student(std::string&&);
    Student(const Student&);
    Student& operator=(const Student&);
    ~Student();
    Student(Student&&);
    Student& operator=(Student&&);

private:
    int no;
    std::string name;

public:
    friend Student operator+(const Student&, const Student&);
    friend std::ostream& operator<<(std::ostream&, const Student&);
    Student& operator>>(const std::string&);
    Student& operator>>(std::string&&);
    Student& operator<<(const std::string&);
    Student& operator<<(std::string&&);
    Student& operator+=(const Student&);


    void print();

private:
    static int next_no;

};
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    // 默认构造函数
    Employee();

    // 初始化名字的构造函数
    explicit Employee(const string& _name);
    
    // 拷贝构造无法保证对象唯一性，禁掉
    Employee(const Employee& e) = delete;

    // 拷贝赋值无法保证对象唯一性，禁掉
    Employee& operator=(const Employee& rhs) = delete;

    // 析构函数默认就好
    ~Employee() = default;

    // 打印信息
    void print();
private:
    static unsigned next_no;
    unsigned no;
    string name;
};

Employee::Employee(): name("No Name"), no(0) {}

Employee::Employee(const string& _name) : name(_name), no(Employee::next_no++) {}

void Employee::print() {
    cout << "No. :\t" << no << endl;
    cout << "Name:\t" << name << endl;
    cout << endl;
}

unsigned Employee::next_no = 1;

int main() {
    auto e1 = Employee("Tom");
    auto e2 = Employee("Jack");
    Employee e3;
    e1.print();
    e2.print();
    e3.print();

    return 0;
}
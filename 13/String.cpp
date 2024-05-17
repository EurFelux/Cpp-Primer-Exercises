#include "String.h"
#include <iterator>
#include <iostream>
#include <vector>


String::String(const char* cs): String()
{
    while (*cs != '\0')
    {
        push_back(*cs++);
    }
}

String::String(const String& s)
{
    std::cout << "copy constructor" << std::endl;
    
    auto new_data = alloc_copy(s.cbegin(), s.cend());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

String::String(String&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // 使得s可以安全析构
    s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(const String& rhs)
{
    std::cout << "copy assignment" << std::endl;
    
    auto new_data = alloc_copy(rhs.cbegin(), rhs.cend());
    free();
    elements = new_data.first;
    cap = first_free = new_data.second;
    return *this;
}

String& String::operator=(String&& rhs)
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

String::~String()
{
    free();
}

void String::push_back(const char &c)
{
    chk_alloc();
    alloc.construct(first_free++, c);
}

std::pair<char*, char*>
String::alloc_copy(const char* b, const char* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    for (auto p = first_free; p != elements; )
    {
        alloc.destroy(--p);
    }
    alloc.deallocate(elements, capacity());
}

void String::reallocate()
{
    reallocate(
        size() ? 2 * size() : 1
    );
}

void String::reallocate(size_t n)
{
    auto new_data = alloc.allocate(n);
    auto dest = new_data;
    
    for (auto p = elements; p != first_free; )
    {
        alloc.construct(dest++, std::move(*p++));
    }
    free();

    elements = new_data;
    first_free = dest;
    cap = new_data + n;
}

void String::chk_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

int main()
{
    std::vector<String> v;

    // v.reserve(4);

    std::cout << "push 1:" << std::endl;
    v.push_back("123");
    // v.emplace_back("123");

    std::cout << "push 2:" << std::endl;
    v.push_back("123");
    // v.emplace_back("123");

    std::cout << "push 3:" << std::endl;
    v.push_back("123");
    // v.emplace_back("123");

    std::cout << "push 4:" << std::endl;
    v.push_back("123");
    // v.emplace_back("123");

    return 0;
}
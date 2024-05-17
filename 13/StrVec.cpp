#include "StrVec.h"

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

/**
 * @brief remove last element. UB if empty.
 */
void StrVec::pop_back()
{
    alloc.destroy(--first_free);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);

    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // Implementation 1: for
    if (elements)
    {
        for (auto p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }

    // Implementation 2: for_each
    if (elements)
    {
        // ...How could I do this?
    }

    // Implementation 3: lambda
    // Why I did this?
    auto f = [&](std::string* b, std::string* e)
    {
        while (b != e)
        {
            alloc.destroy(b++);
        }
    };

    f(begin(), end());
    alloc.deallocate(elements, cap - elements);
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    cap = first_free = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &lst)
{
    auto data = alloc_n_copy(lst.begin(), lst.end());
    elements = data.first;
    cap = first_free = data.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = rhs.elements;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;
    reallocate(new_capacity);
}

void StrVec::reallocate(size_t new_capacity)
{
    auto new_data = alloc.allocate(new_capacity);

    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void StrVec::reserve(size_t n)
{
    if (elements)
    {
        if (capacity() < n)
        {
            reallocate(n);
        }
    }
    else
    {
        elements = alloc.allocate(n);
        first_free = elements;
        cap = elements + n;
    }
}

void StrVec::resize(size_t new_size)
{
    if (new_size > size())
    {
        while (new_size != size())
            push_back("");
    } 
    else if (new_size < size())
    {
        while (new_size != size())
            pop_back();
    }
    else
        ;
}
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>

class StrVec
{
private:
    static std::allocator<std::string> alloc;

    /* data */
    std::string *elements;
    std::string *first_free;
    std::string *cap;

public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(const std::initializer_list<std::string>&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    void pop_back();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n);
    void resize(size_t new_size);
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }

    
private:
    /* tool function */
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }

    std::pair<std::string*, std::string*> 
    alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    void reallocate(size_t new_capacity);
};

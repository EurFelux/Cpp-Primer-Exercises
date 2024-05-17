#include <memory>
#include <utility>

class String
{
private:
    std::allocator<char> alloc;

    char *elements;
    char *first_free;
    char *cap;

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String(String&&) noexcept;
    String &operator=(const String &);
    String &operator=(String &&);
    ~String();

    /* operations */
    void push_back(const char&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() { return elements; }
    char* end() { return first_free; }
    const char* cbegin() const { return elements; }
    const char* cend() const { return first_free; }

private:
    std::pair<char *, char *>
    alloc_copy(const char *b, const char *e);
    void free();
    void reallocate();
    void reallocate(size_t n);
    void chk_alloc();
};
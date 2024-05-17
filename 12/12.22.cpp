#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string &front();
    string &back();

private:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw out_of_range(msg);
    };
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
string &StrBlob::front()
{
    check(0, "something");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "something");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "something");
    data->pop_back();
}

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const
    {
        auto p = check(curr, "something");
        return (*p)[curr];
    }
    StrBlobPtr &incr() {return *this;}

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    const string& deref() const
    {
        auto p = check(curr, "something");
        return (*p)[curr];
    }
    const ConstStrBlobPtr& incr () const {
        check(curr, "something");
        ++curr;
        return *this;
    }
    
private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    mutable size_t curr;
};

int main(int argc, char const *argv[])
{
    const auto sb = StrBlob({"abc"});
    auto p = ConstStrBlobPtr(sb, 0);
    auto s = p.deref();
    cout << p.deref() << endl; 
    s.append("def");
    cout << p.deref() << endl; 
    cout << s << endl;

    return 0;
}

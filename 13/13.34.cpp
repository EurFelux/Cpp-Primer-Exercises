#include <iostream>
#include <set>
#include <string>

using namespace std;

class Folder;
class Message;

class Folder
{
public:
    Folder() {}
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void addMsg(Message *msg);
    void remMsg(Message *msg);

private:
    std::set<Message*> messages;
    void save_messages(const Folder&);
    void remove_messages();
};

class Message
{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void save(Folder *);
    void remove(Folder &);
    void remove(Folder *);

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::save(Folder *fp)
{
    folders.insert(fp);
    fp->addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::remove(Folder *fp)
{
    folders.erase(fp);
    fp->remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

// copy constructor
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

// destructor
Message::~Message()
{
    remove_from_Folders();
}

// copy assignment
Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    folders = rhs.folders;
    contents = rhs.contents;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

Folder::Folder(const Folder &f): messages(f.messages)
{
    save_messages(f);
}

Folder& Folder::operator=(const Folder &rhs)
{
    save_messages(rhs);

    messages = rhs.messages;

    remove_messages();

    return *this;
}

Folder::~Folder()
{
    remove_messages();
}

void Folder::save_messages(const Folder& f)
{
    for (auto msg : messages)
    {
        msg->remove(*this);
    }
}

void Folder::remove_messages()
{
    for (auto msg : messages)
    {
        msg->save(*this);
    }
}

int main()
{

    return 0;
}
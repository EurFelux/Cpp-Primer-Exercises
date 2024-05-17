#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class TextQuery;
class QueryResult;
ostream& print(ostream &out, QueryResult &qr);


class TextQuery
{
public:
    friend class QueryResult;
    using key_type = string;
    using mapped_type = shared_ptr<set<int>>;
    using data_iterator = vector<key_type>::iterator;
    using map_value_iterator = map<key_type, mapped_type>::iterator;

    TextQuery(ifstream &f);
    // ~TextQuery();
    QueryResult query(const string &s);

private:
    shared_ptr<vector<string>> data = make_shared<vector<string>>();
    map<key_type, mapped_type> row_map;
};


class QueryResult
{
public:
    friend ostream& print(ostream &out, const QueryResult &qr);
    QueryResult(shared_ptr<set<int>> row_set_ptr,
                shared_ptr<vector<string>> data_ptr,
                const int &count,
                const string& target);

private:
    // nullable
    shared_ptr<set<int>> _row_set_ptr;

    // nullable
    shared_ptr<vector<string>> _data_ptr;

    int _count;

    string _target;
};


/**
 * @brief constructor of TextQuery. create row_map.
 * @param f file stream to read
 */
TextQuery::TextQuery(ifstream &f)
{
    if (!f.is_open())
        throw invalid_argument("f is not open.");
    
    // create map
    string s;
    for (int i = 0; getline(f, s); ++i)
    {
        data->push_back(s);
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
            if (row_map.find(word) == row_map.end())
                row_map.insert({word, make_shared<set<int>>()});
            auto& row_set = *row_map[word];
            row_set.insert(i);
        }
    }
}


/**
 * @brief query a word and count
 * @param target word
 * @return QueryResult
 */
QueryResult TextQuery::query(const string &target)
{
    shared_ptr<set<int>> row_set_ptr;
    int count{0};

    // real-time query (count)
    if (row_map.find(target) != row_map.end())
    {
        cout << "enter loop" << endl;
        row_set_ptr = row_map[target];
        for (const auto &i : *row_set_ptr)
        {
            string line = (*data)[i];
            istringstream iss(line);
            string word;
            while (iss >> word)
            {
                if (word == target)
                    ++count;
            }
        }
    }
    return QueryResult(row_set_ptr, data, count, target);
}


/**
 * @brief constructor of QueryResult.
 * @param row_set_ptr 
 * @param data_ptr 
 * @param count 
 */
QueryResult::QueryResult(shared_ptr<set<int>> row_set_ptr, shared_ptr<vector<string>> data_ptr, const int &count, const string& target) 
                        : _row_set_ptr(row_set_ptr), _data_ptr(data_ptr), _count(count), _target(target) {}


/**
 * @brief print results in QueryResult object.
 * @param out ostream to output
 * @param qr QueryResult object
 */
ostream& print(ostream &out, const QueryResult &qr)
{
    out << qr._target << " occurs " << qr._count << " times:" << endl;
    if (qr._row_set_ptr)
        for (const auto &i : *(qr._row_set_ptr))
        {
            out << "\t(line " << i << "): " << (*(qr._data_ptr))[i] << endl;
        }
    return out;
}

/**
 * @brief test function
 * @param infile 
 */
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;

        print(cout, tq.query(s)) << endl;
    }
}


int main()
{
    auto ifs = ifstream("test.txt");
    runQueries(ifs);
    return 0;
}
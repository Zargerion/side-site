
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Number
{
public:
    string name;
    string number;

    Number(const Number &v): // constructor co v is value of link
    name(v.name),
    number(v.number) {}
    const Number &operator=(const Number &v) // redefine oparator "=" so can copy data from &v.name to name.
    {
        name = v.name;
        number = v.number;
        return v;
    }

vector<Number> telBook;
int main()
{
    fstream f("file.txt");
    while (true)
    {
        Number t;
        f >> t.name;
        if (f.eof())
            break;
        f >> t.number;
        if (f.eof())
            break;
        telBook.push_back(t);
    }
}



};
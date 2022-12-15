#include <iostream>
#include <fstream> // File stream.
#include <string>
using namespace std;

void filereader(string a) // Doesn't takes ''.
{
    ifstream f(a);
    while (true) // While not end of file.
    {
        string v;
        f >> v;
        if (!f.eof()) // If not end of file.
        {
            cout << v << endl;
        }
        else
        {
            break;
        }
    }
}

void filewriter(string a)
{
    ofstream f(a);
    for (int i = 0; i < 10; i++)
    {
        string w;
        cin >> w;
        f << w << endl;
    }
}


int main()
{
    filewriter("file.txt");
    filereader("file.txt");
}
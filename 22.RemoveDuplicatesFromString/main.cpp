#include <QCoreApplication>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void removeDuplicates(string &str)
{
    std::sort(str.begin(), str.end());

    int i = 0, j = 0;
    int n = str.length();

    while(i<n)
    {
        if(str[i]==str[i+1])
            ++i;
        else
        {
            str[j]=str[i];
            ++j;
            ++i;
        }
    }

    //remove extra elements from end of the string
    str = str.substr(0, j);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a string: ";
    getline(cin,str);

    removeDuplicates(str);
    //str.erase(std::unique(str.begin(), str.end()), str.end());
    cout << "After removing duplicates: " << str << endl;

    return a.exec();
}


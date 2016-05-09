#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

#define CHAR_COUNT 256

int * getCountCharArray(string &s)
{
    int * count = new int[CHAR_COUNT];
    std::fill_n(count,CHAR_COUNT,0);
    for(uint i=0;i<s.length();++i)
        count[(int)s[i]]++;

    return count;
}

int firstNonRepeted(string &s)
{
    int * count = getCountCharArray(s);
    int result = -1;
    for(uint i=0;i<s.length();++i)
        if(count[(int)s[i]]==1){
            result = i;
            break;
        }

    delete count;
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string str = "geeksforgeeks";
    int index =  firstNonRepeted(str);
    if (index == -1)
       cout << "Either all characters are repeating or string is empty" << endl;
    else
        cout << "First non-repeating character is " << str[index] << endl;

    return a.exec();
}


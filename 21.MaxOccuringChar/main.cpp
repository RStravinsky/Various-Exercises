#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

char maxOccuringChar(string s)
{
    int count[256]={0};
    for(uint i=0;i<256;++i)
        count[(int)s[i]]++;

    char result;
    int max=-1;
    for(uint i=0;i<s.length();++i)
    {
        if(count[(int)s[i]]>max){
            max = count[(int)s[i]];
            result = s[i];
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a string: ";
    getline(cin,str);
    cout << "Max occuring character in string is " << maxOccuringChar(str) << endl;

    return a.exec();
}


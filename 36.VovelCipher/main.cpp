#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

bool isVovel(char ch)
{
    bool result=false;
    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            result = true;
    }

    return result;
}

void encrypt(string & str)
{
    bool first = true;
    char firstChar;
    int idx;

    for(uint i=0;i<str.length();++i)
    {
        if(!isVovel(str[i])){
            if(first)
            {
                firstChar = str[i];
                idx = i;
                first = false;
            }

            else {
                int pom = str[i];
                str[i]=firstChar;
                firstChar = pom;
            }
        }
    }

    if(!first)
        str[idx]=firstChar;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string word;
    cout << "Write a word: ";
    cin >> word;

    encrypt(word);
    cout << word << endl;

    return a.exec();
}


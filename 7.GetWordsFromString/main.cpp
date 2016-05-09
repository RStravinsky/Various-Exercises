#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<string> getWords(string &s,const char &delimiter)
{
    vector<string> v;
    string buffer{""};

    for(auto elem: s)
    {
        if(elem!=delimiter) buffer+=elem;
        else if(elem==delimiter && buffer !="") {v.push_back(buffer); buffer="";}
    }
    if(buffer !="") v.push_back(buffer);

    return v;
}

int getWords(const char * line,char ** words,const char* delimiter)
{
    int count = 0;

    char * dup = new char[strlen(line)]; // copy original string
    strcpy(dup,line);

    char *token = strtok(dup,delimiter);
    while(token!=NULL)
    {
        words[count] = new char;
        strcpy(words[count],token);
        token = strtok(NULL,delimiter);
        ++count;
    }

    delete[] dup; // free memory
    return count;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "----- CHAR -----" << endl;
    const char * source = "C++ language is a big fun";
    char ** split = new char*[100];
    int size = getWords(source,split," ");
    for(int i=0;i<size;++i)
        cout << split[i] << "x" << endl;
    delete[] split;

    cout << "----- STRING -----" << endl;
    string str = "C++ language    is a big fun";
    vector<string> vect = {getWords(str,' ')};
    for(auto elem: vect)
        cout << elem << "x" << endl;

    return a.exec();
}


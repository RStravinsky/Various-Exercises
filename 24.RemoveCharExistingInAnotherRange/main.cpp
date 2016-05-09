#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <string>


void removeChar(std::string &s, std::string &mask)
{
    int i=0;
    int k=0;
    int sSize=s.length();
    int dSize = mask.length();

    while(i<sSize)
    {
        int j=0;
        bool EXIST = false;
        while(j<dSize)
        {
            if(s[i]==mask[j])
                EXIST = true;
            ++j;
        }

        if(!EXIST)
            s[k++]=s[i];

        i++;
    }

    s = s.substr(0,k);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string str;
    std::cout << "Write a string: ";
    getline(std::cin,str);

    std::string word;
    std::cout << "Write a word: ";
    std::cin >> word;

    removeChar(str,word);

    std::cout << "After removing: " << str << std::endl;

    return a.exec();
}


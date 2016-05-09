#include <QCoreApplication>
#include <iostream>
#include <string>

bool isRotation(std::string s1, std::string s2)
{
    if(s1.size() != s2.size())
        return false;

    if(s1.size() == 0 || s2.size() == 0)
        return false;

    std::string temp;
    temp = s1+s1;

    //auto pos = std::search(temp.begin(),temp.end(),s2.begin(),s2.end());
    auto pos = temp.find(s2);
    if(pos!=std::string::npos)
        return true;

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string str1;
    std::cout << "Write a word: ";
    std::cin >> str1;

    std::string str2;
    std::cout << "Write a word: ";
    std::cin >> str2;

    std::cout << "Are rotated: " << isRotation(str1,str2) << std::endl;
    return a.exec();
}

//MARTYNA
//NAMARTY

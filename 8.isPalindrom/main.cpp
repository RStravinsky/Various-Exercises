#include <QCoreApplication>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindorm(string s)
{
    string temp = s;
    reverse(s.begin(),s.end());
    if(s==temp)
            return true;

    return false;
}

bool isPalindorm(int number)
{
    int temp=0;
    int prev = number;
    while(number!=0)
    {
        temp = temp*10;
        temp = temp+number%10;
        number/=10;
    }

    if(temp==prev)
        return true;

    return false;
}

bool isPalindorm(const char * chStr)
{
    char * str = new char[strlen(chStr)];
    strcpy(str,chStr);
    bool result = false;

    for(unsigned int i=0;i<strlen(str)/2;++i)
            swap(str[i],str[strlen(str)-1-i]);


    if(strcmp(str,chStr)==0)
        result = true;

    delete str;
    return result;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a string: ";
    cin >> str;
    cout << "String is palindrom: " << isPalindorm(str) << endl;

    const char * charStr = str.c_str();
    cout << "Cstring is palindrom: " << isPalindorm(charStr) << endl;

    int num;
    cout << "Write a number: ";
    cin >> num;
    cout << "Number is palindrom: " << isPalindorm(num) << endl;

    return a.exec();
}


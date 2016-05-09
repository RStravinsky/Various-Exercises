#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

void removeChar(string &s, const char &character,bool isStl)
{
    if(character==0)
        return;

    if(isStl){
       //s.erase(remove(s.begin(),s.end(),character),s.end());
        size_t found = 0;
        while(found!=string::npos)
        {
            found = s.find_first_of(character,1);
            if(found!=string::npos)
            {
                s.erase(found,1);
                found = found + 1;
            }
        }
    }
    else { // in place        
       int j=0;
       for(unsigned int i=0;i<s.size();++i){
           while(s[i]==character){
               j=i;
               while(s[j]!=0){
                   s[j]=s[j+1];
                   ++j;
               }
           }
       }
    }
}

void removeChar(char * arr, const char &character) // in place
{
    if(character==0)
        return;

    int j=0;
    for(unsigned int i=0;i<strlen(arr);i++)
        if(*(arr+i)!=character)
        {
            *(arr+j)=*(arr+i);
            ++j;
        }

    *(arr+j)='\0'; // NULL char
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a string: ";
    getline(cin,str);

    char ch;
    cout << "Char to remove: ";
    cin >> ch;

    // covert string to char - dynammicly
    char * arr = new char[str.size()+1];
    copy(str.begin(),str.end(),arr);
    arr[str.size()]='\0';

    removeChar(str,ch,true);
    removeChar(arr,ch);

    cout << "String after remove: " << str << endl;
    cout << "Cstring after remove: " << arr << endl;

    delete[] arr;
    return a.exec();
}


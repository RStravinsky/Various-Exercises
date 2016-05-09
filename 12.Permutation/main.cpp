#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/* function to swap  pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(string s, int i, int length)
{
   int j;
   if (i == length){
     for(int i=0 ;i<= length;++i)
         cout << s[i] << " ";
     cout << endl;
   }
   else
   {
       for (j = i; j <= length; j++) {
          swap(s[i], s[j]);
          permute(s, i+1, length);
          swap(s[i], s[j]); //backtracking
       }
   }
}

void permute(string s)
{
    string temp = s;
    sort(temp.begin(),temp.end());
    while(next_permutation(temp.begin(),temp.end()))
        cout << temp << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Write a word: ";
    string str;
    std::cin >> str;

    permute(str,0,str.length()-1);
    cout << endl;
    permute(str);

    return a.exec();
}


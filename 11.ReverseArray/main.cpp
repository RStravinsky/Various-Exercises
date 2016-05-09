#include <QCoreApplication>
#include <string>
#include <algorithm>
#include <iostream>

/* --------------------------------------------------- /*
 *  Reverse array without affecting special characters
 *  Time complexity: O(n)
 *  1) Let input string be s
    2) l = 0, r = n-1
    3) While l is smaller than r, do following
    a) If s[l] is not an alphabetic character, do l++
    b) Else If s[r] is not an alphabetic character, do r--
    c) Else swap s[l] and s[r]
/* --------------------------------------------------- */

using namespace std;

bool isAlphabet(char c)
{
    return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
}

void reverse(string &s)
{
    int l=0;
    int r=s.length()-1;
    while(l<r)
    {
        if(!isAlphabet(s[l]))
            l++;
        else if(!isAlphabet(s[r]))
            r--;

        else{
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a word:";
    cin >> str;

    cout << "Before reverse: " << str << endl;

    reverse(str);

    cout << "After reverse: " << str << endl;

    return a.exec();
}


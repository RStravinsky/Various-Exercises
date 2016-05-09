#include <QCoreApplication>
#include <iostream>
#include <string>

/* --------------------------------------------------- /*
 *  Check if two words are anagrams.
 *  Time complexity: O(n)
/* --------------------------------------------------- */

using namespace std;

bool isAnagram(string &s1, string &s2)
{
    int count[256]={0};

    for(uint i=0;i<s1.length();++i)
        count[s1[i]-'a']++;

    for(uint i=0;i<s2.length();++i)
        count[s2[i]-'a']--;

    for(uint i=0;i<256;++i)
        if(count[i]!=0)
            return false;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout << "Write a word: ";
    cin >>  str;

    string anagram;
    cout << "Write a word to compare: ";
    cin >> anagram;

    if(isAnagram(str,anagram))
        cout << "are anagrams." << endl;
    else
        cout << "are NOT anagrams!" << endl;

    return a.exec();
}


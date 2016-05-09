#include <QCoreApplication>
#include <string>
#include <iostream>

using namespace std;

void showMatrix(bool table[][1000],int size)
{
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j)
            cout << table[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isPalindrom(string s)
{
    for(uint i=0;i<s.length()/2;++i)
        if(s[i]!=s[s.length()-i-1])
            return false;
    return true;
}

string longestPalindrome(string s)
{
    uint maxLen = 1;
    string longest = "";
    for(uint i=0;i<s.length();++i) {
        for(uint j=i+1;j<s.length();++j){
            string curr = s.substr(i,j+1);
            if(isPalindrom(curr)){
                if(curr.length()>maxLen){
                    maxLen = curr.length();
                    longest = curr;
                }
            }
        }
    }
    return longest;
}

string longestPalindromeDP(string s) {
    int n = s.length();
    int maxLen = 1;
    bool temp[100][100] = {false};
    int beg = 0;

    // one character
    for(int i=0;i<n;++i)
        temp[i][i]=true;

    for(int i=0;i<n-1;++i) {
        if(s[i]==s[i+1]){
            temp[i][i+1]=true;
            beg = i;
            maxLen = 2;
        }
    }

    for(int len=3 ; len<=n ; ++len){
        for(int i=0; i<n-len+1; ++i)
        {
            int j = i+len-1;
            if(s[i]==s[j] && temp[i+1][j-1])
            {
                temp[i][j]=true;
                beg=i;
                maxLen=len;
            }
        }
    }

    return s.substr(beg,maxLen);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << longestPalindromeDP("dsdaabaaad") << endl;
    cout << longestPalindrome("dsdaabaaad") << endl;

    return a.exec();
}


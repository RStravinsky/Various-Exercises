#include <QCoreApplication>
#include <iostream>
#include <string>

std::string commonSubstring(std::string s1, std::string s2)
{
    int match[s1.length()][s2.length()];
    int len1 = s1.length();
    int len2 = s2.length();
    int max = 0;
    std::string common = "";

    for(int i=0;i<len1;++i)
        for(int j=0;j<len2;++j)
        {
            if(s1[i]==s2[j]){
                if(i==0 || j==0) match[i][j]=1;
                else match[i][j] = match[i-1][j-1]+1;

                if(match[i][j]>max){
                    max = match[i][j];
                    common = s1.substr(i-max+1,max);
                }
                else if(match[i][j]==max)
                    common = s1.substr(i-max+1,max);
            }
            else
                match[i][j]=0;
        }

    return common;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << commonSubstring("YSDxAABBCCDDACExFAHSDH","BxAABBCCDDACEFxJDJSJS") << std::endl;

    return a.exec();
}


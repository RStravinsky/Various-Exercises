#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// classic
vector<string> difference(const vector<string> &v1,const vector<string> &v2)
{
    vector<string> diff;
    for(auto it1=v1.begin();it1!=v1.end();++it1)
    {
        bool isFound = false;
        string temp = *it1;
        for(auto it2=v2.begin();it2!=v2.end();++it2)
            if(temp==*it2) {
                isFound = true;
                break;
            }
        if(!isFound)
            diff.push_back(temp);
    }

    return diff;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> v1 = {"one","one","one","one","five","six","seven","eight"};
    vector<string> v2 = {"one","one","three","ten","five","six","eleven","ten"};

//    vector<string> classicDiff = difference(v1,v2);
//    for(auto elem: classicDiff)
//        cout << elem << endl;

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<string> setDiff;
    set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(setDiff));
    for(auto elem: setDiff)
        cout << elem << endl;

    return a.exec();
}


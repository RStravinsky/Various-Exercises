#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

bool findPair(vector<int> &v,int sum)
{
    int temp;
    bool binMap[200] = {false}; /*initialize hash map as 0*/

    for (int i = 0; i < v.size(); i++)
    {
        temp = sum - v[i];
        if (temp >= 0 && binMap[temp] == true){
            cout << "Pair with given sum " << sum << " is ("<<v[i]<<","<<temp<<")" << endl;
            return true;
        }
        binMap[v[i]] = true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    uint n;
    cout << "Enter size: ";
    cin >> n;

    srand(time(NULL));
    vector<int> vect;
    for(int i=0;i<n;++i){
        vect.push_back(rand()%9+1);
        cout << vect.at(i) << " ";
    }

    int number;
    cout << "Enter number: ";
    cin >> number;

    bool sumExist = findPair(vect,number);
    if(sumExist)
        cout << "Array has two elements with the given sum" << endl;
    else
        cout << "Array doesn't have two elements with the given sum" << endl;


    return a.exec();
}


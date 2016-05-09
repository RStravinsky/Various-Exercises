#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

vector<int> PrimeFactors(int number)
{
    int k = 2;
    vector<int> vect;
    while(number>1)
    {
        while(number%k==0){
            number = number / k;
            vect.push_back(k);
        }
        k++;
    }

    return vect;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter a number: ";
    cin >> number;

    vector<int> v = {PrimeFactors(number)};
    for(auto elem: v)
        cout << elem << " ";

    cout << endl;

    return a.exec();
}


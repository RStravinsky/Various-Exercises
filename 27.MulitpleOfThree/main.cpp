#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

bool isMultipleOfThree(int n)
{
    int temp;
    int sum = 0;
    while(n!=0)
    {
        temp = n%10;
        sum += temp;
        n/=10;
    }

    if(sum%3==0)
        return true;

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter number: ";
    cin >> number;

    bool isMultiple = isMultipleOfThree(number);
    if(isMultiple)
        cout << "Number is multiple of three" << endl;
    else
        cout << "Number is not multiple of three" << endl;


    return a.exec();
}


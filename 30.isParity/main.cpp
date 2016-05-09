#include <QCoreApplication>
#include <iostream>

using namespace std;

bool getParity(int number)
{
    uint count = 0;
    while(number!=0)
    {
        if(number&1) count++;
        number = number >> 1;
    }

    return !(count%2);
}


int getFirstBitPos(int number)
{
    uint count = 0;
    while(number!=0)
    {
        if(number&1) break;
        number = number >> 1;
        count++;
    }

    return count;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter number: ";
    cin >> number;

    if(getParity(number))
        cout << "Even number of 1-bits" << endl;
    else
        cout << "Odd number of 1-bits" << endl;


    cout << "First 1 bit from right: " << getFirstBitPos(number) << endl;

    return a.exec();
}

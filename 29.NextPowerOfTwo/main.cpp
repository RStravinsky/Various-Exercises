#include <QCoreApplication>
#include <iostream>

using namespace std;

uint nextPowerOfTwo(uint number)
{
    if(number && (!(number&(number-1))))
        return number;

    int count = 0;
    while(number!=0)
    {
        number = number >> 1;
        count++;
    }

    return 1<<count;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    uint number;
    cout << "Enter number: ";
    cin >> number;

    uint result = nextPowerOfTwo(number);
    cout << "Next or equal power of two is " << result << endl;

    return a.exec();
}


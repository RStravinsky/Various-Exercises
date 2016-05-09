#include <QCoreApplication>
#include <iostream>

using namespace std;

// iterative
long sum(int number)
{
    long sum = 0;
    int temp = 0;
    while(number!=0)
    {
        temp = number%10;
        sum += temp;
        number /= 10;
    }

    return sum;
}

//recursive
long sumRec(int number)
{
    return number == 0 ? 0 : number%10 + sumRec(number/10);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter number: ";
    cin >> number;

    cout << "Sum of digits: " << sum(number) << endl;
    cout << "Sum of digits: " << sumRec(number) << endl;

    return a.exec();
}


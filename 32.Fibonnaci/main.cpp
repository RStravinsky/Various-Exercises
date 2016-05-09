#include <QCoreApplication>
#include <iostream>

using namespace std;

void Fibonacci(int number)
{
    long long a = 0, b = 1;

    for(int i=0;i<number;++i)
    {
        cout << b << " ";
        b = b+a;
        a = b-a;
    }
    cout << endl;
}

int FibonacciRecursive(int number)
{
    if(number<3)
        return 1;
    else
        return FibonacciRecursive(number-1)+FibonacciRecursive(number-2);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter first number: ";
    cin >> number;

    Fibonacci(number);
    cout << "Recursive - Fibonacci " << FibonacciRecursive(number) << endl;

    return a.exec();
}


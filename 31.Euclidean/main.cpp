#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

int greatestDivisor(int a, int b)
{
    while(a!=b)
        if(a>b) a = a-b;
        else b = b-a;
    return a;
}

int greatestDivisorFaster(int a, int b) // optimalization
{
    int pom;
    while(b!=0)
    {
        pom = b;
        b = a%b;
        a = pom;
    }

    return a;
}

int greatestDivisorRecursive(int a, int b)
{
    if(a!=b)
        return greatestDivisorRecursive( a>b?a-b:a , b>a?b-a:b );
    else return a;
}

int lowestMultiple(int a,int b)
{
    return (a/greatestDivisorFaster(a,b))*b;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number1;
    cout << "Enter first number: ";
    cin >> number1;

    int number2;
    cout << "Enter second number: ";
    cin >> number2;

    cout << "Greatest common divisor of given numbers is " << greatestDivisorFaster(number1,number2) << endl;
    cout << "Recursive - Greatest common divisor of given numbers is " << greatestDivisorRecursive(number1,number2) << endl;
    cout << "Lowest multiple is " << lowestMultiple(number1,number2) << endl;

    return a.exec();
}


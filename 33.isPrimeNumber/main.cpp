#include <QCoreApplication>
#include <iostream>

using namespace std;

bool isPrimeNumber(int number)
{
    if(number < 2) return false;

    for(int i=2; (i*i)<=number; ++i){
        if(number % i == 0 )
            return false;
    }

    return true;
}

void allPrimeNumber(int number)
{
    for(int i=0;i<number;++i)
        if(isPrimeNumber(i))
            cout << i << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter a number: ";
    cin >> number;

    if(isPrimeNumber(number))
        cout << "Is prime number" << endl;
    else
        cout << "Is NOT a prime number" << endl;

    allPrimeNumber(number);

    return a.exec();
}


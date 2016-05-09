#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter a number: " << endl;
    cin >> number;

    cout << "Wartosc bezwzgledna: " << abs(number) << endl;

    return a.exec();
}

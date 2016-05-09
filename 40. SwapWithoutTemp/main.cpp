#include <QCoreApplication>
#include <iostream>

void swap(int &a,int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int first, second;
    std::cout << "Enter first and second number:" << std::endl;
    std::cin >> first;
    std::cin >> second;

    swap(first,second);
    std::cout << "After swap first = " << first << ", second = " << second << std::endl;

    return a.exec();
}


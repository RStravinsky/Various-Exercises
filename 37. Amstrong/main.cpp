#include <QCoreApplication>
#include <iostream>

using namespace std;

bool isAmstrongNumber(int number)
{
    int sum = 0;
    int temp;
    int remember = number;
    while(number!=0)
    {
        temp = number%10;
        sum+= (temp*temp*temp);
        number = number/10;
    }

    if(remember==sum)
        return true;

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number;
    cout << "Enter number: ";
    cin >> number;

    if(isAmstrongNumber(number))
        cout << "Given number is amstrong number" << endl;
    else
        cout << "Given number is NOT amstrong number" << endl;


    return a.exec();
}


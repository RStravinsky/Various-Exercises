#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

long long sum(int * arr,int N)
{
    long long sum = 0;
    for(int i=0;i<N;++i)
    {
        sum = sum*10;
        sum+=*(arr+i);
    }

    return sum;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int arraySize;
    cout << "Enter size: ";
    cin >> arraySize;

    srand(time(NULL));
    int array[arraySize];
    for(int i=0;i<arraySize;++i){
        array[i]=rand()%9 + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Number from array: " << sum(array,arraySize) << endl;


    return a.exec();
}


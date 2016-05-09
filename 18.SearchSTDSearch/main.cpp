#include <QCoreApplication>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    deque<string> d = {"Search", "algorithim", "is", "good", "or", "is", "good", "enoguh"};
    string tab[2] = {"is","good"};
    auto pos = search(d.begin(),d.end(),tab,tab+2);

    while(pos != d.end()){
        cout << "String \"is good\" fount at: " << distance(d.begin(),pos)+1 << endl;
        pos = search(++pos,d.end(),tab,tab+2);
    }

    return a.exec();
}


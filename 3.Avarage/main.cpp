#include <QCoreApplication>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Avarage
{
    private:
        int number;
        int sum;
    public:
    Avarage():number(0),sum(0){}

    void operator()(int elem){
    number++;
        sum += elem;
    }

    operator double(){
        return static_cast<double>(sum)/static_cast<double>(number);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    double avarage = for_each(v.begin(),v.end(),Avarage());
    cout << "Avarage is: " << avarage << endl;

    return a.exec();
}


#include <QCoreApplication>
#include <algorithm>
#include <iostream>
#include <list>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    list<int> l = {1,2,3,4,5,5,5,5,5,9};

    cout << "List: ";
    for(auto elem: l)
        cout << elem << " ";
    cout << endl;

    // std::find_if()
    list<int>::iterator pos1 = find_if(l.begin(),l.end(),bind(greater<int>(),std::placeholders::_1,4)); // if grater than 4
    if(pos1!=l.end()) {
        cout << "After find_if(): ";
        for_each(pos1,l.end(),[](int elem){cout << elem << " ";});

        //std::find_if_not()
        auto pos2 = find_if_not(pos1,l.end(),[](int element){return element==5;});
        if(pos2!=l.end())
            cout << "\nFirst element different than 5: " << *pos2 << endl;
        else
            cout << "\nOnly fives!" << endl;
    }

    return 0;
}


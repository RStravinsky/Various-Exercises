#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    list<int> l = {1,2,3,4,5,6,7,8,9,10};

    for(auto elem: l)
        cout << elem << " ";

    int value;
    cout << "\nEnter value for remove: ";
    cin >> value;

    list<int>::iterator pos = find(l.begin(),l.end(),value);
    if(pos!=l.end()) {
        l.erase(pos); // delete element
        for(auto elem: l)
            cout << elem << " ";
        cout << endl;
    }
    else
        cout << "not found" << endl;


    return 0;
}


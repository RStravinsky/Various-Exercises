#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    cout << "Enter size: ";
    cin >> N;

    vector<int> vect(N+1);

    srand(time(NULL));
    for(unsigned int i=0;i<vect.size()-1;++i){
        vect[i]=rand()%10+1;
        cout << vect[i] << " ";
    }
    cout << "\nLast element-guard: " << vect.back();

    int elem;
    cout << "\nEnter element to find: ";
    cin >> elem;

    vect.back() = elem;
    int i = 0;
    while (vect[i] != elem)
        i++;

    if(i!=N) cout << elem << " found at " << i << endl;
    else cout << elem << " not found" << endl;

    return 0;
}

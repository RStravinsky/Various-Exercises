#include <QCoreApplication>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int size;
    cout << "Enter size: ";
    cin >> size;

    srand(time(NULL));

    int tab[size];
    for(int i=0; i<size ; ++i){
        *(tab+i)=rand()%10 + 1;
        cout << *(tab+i) << " ";
    }


    int dominanta = 0;
    int counter=0;
    int max_counter=0;
    int max_dominata=0;

    for(int i=0; i<size; ++i)
    {
        counter=0;
        dominanta = *(tab+i);
        for(int j=0 ; j<size ; j++)
            if(dominanta==*(tab+j)) counter++;

        if(counter > max_counter)
            {
                max_counter = counter;
                max_dominata = dominanta;
            }
    }

    cout << endl << "Most common number: " << max_dominata << " - " << max_counter << " times" << endl;

    return a.exec();
}

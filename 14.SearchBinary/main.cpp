#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

enum class BinarySearch
{
    Upper,
    Lower,
    Normal
} ;

int commonBinarySearch(const vector<int> &v, const int&value,BinarySearch type)
{
     int left = 0;
     int right = v.size()-1;
     int result = -1;

     while(left <= right)
     {
         int pivot = (left+right)/2;

         if(v[pivot] == value) {
             if(type==BinarySearch::Normal) return pivot;
             else {
                 result = pivot;
                 if(type==BinarySearch::Lower) right = pivot-1;
                 if(type==BinarySearch::Upper) left = pivot+1;
             }
         }
         else if(v[pivot]>value)
             right = pivot-1;
         else
             left = pivot+1; // when v[pivot]<value
     }
     return result;
}

template<typename T>
int recursiveBinarySearch(const vector<T> &v, const T&value, int left, int right)
{
     // Termination condition: left index greater than right index
     if (left > right)
             return -1;

     int pivot = (left + right) / 2;

     if (v[pivot] == value)
             return pivot;

     else if (v[pivot] > value)
        return recursiveBinarySearch(v, value, left, pivot - 1);
     else
        return recursiveBinarySearch(v, value, pivot + 1, right);
}

template<typename Iterator, typename T>
Iterator IteratorBinarySearch(Iterator begin, Iterator end, const T&key)
{
    const Iterator notFound = end;

    while (begin < end)
    {
        const Iterator Middle = begin + (std::distance(begin,end)/2);

        if(*Middle == key)
            return Middle;
        else if(*Middle > key)
            end = Middle;
        else
            begin = Middle+1;
    }

    return notFound;
}

int countOfElement(const vector<int> v,int value)
{
    int first = commonBinarySearch(v,value,BinarySearch::Lower);
    int last = first;
    if(first == -1)
        return 0;
    else last = commonBinarySearch(v,value,BinarySearch::Upper);

    return last - first + 1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int N;
    cout << "Enter size: ";
    cin >> N;

    vector<int> vect(N);
    srand(time(NULL));
    for(unsigned int i=0;i<vect.size();++i){
        vect[i]=rand()%10+1;
    }

    sort(vect.begin(),vect.end());
    for(auto elem:vect)
        cout << elem << " ";

    int elem;
    cout << "\nEnter element to find: ";
    cin >> elem;

    cout << "Binary search normal: " << commonBinarySearch(vect,elem,BinarySearch::Normal) << endl;
    cout << "Recursive binary search normal: " << recursiveBinarySearch(vect,elem,0,vect.size()-1)  << endl;
    cout << "Binary search lower: " << commonBinarySearch(vect,elem,BinarySearch::Lower) << endl;
    cout << "Binary search upper: " << commonBinarySearch(vect,elem,BinarySearch::Upper) << endl;
    cout << "Count of element: " << countOfElement(vect,elem) << endl;

    //auto pos = IteratorBinarySearch(vect.begin(),vect.end(),elem);
    //*pos = 44;

    return 0;
}

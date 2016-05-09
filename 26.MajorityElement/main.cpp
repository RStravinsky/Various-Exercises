#include <QCoreApplication>
#include <iostream>
#include <string>

int isMajority(std::vector<int> v)
{
    // find element witch occurs the most
    int maxCount = 0;
    int dominant = 0;
    for(uint i=0;i<v.size();++i){
        int temp = v[i];
        int count = 0;
        for(uint j=0;j<v.size();++j)
            if(temp == v[j]) count++;

        if(count>maxCount)
        {
            maxCount = count;
            dominant  = temp;
        }
    }

    if(maxCount > v.size()/2)
        return dominant;

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> vect = {5,5,2,5,5,5,2,8,2,5};
    int dominant = isMajority(vect);

    if(dominant==0)
        std::cout << "NO majority element!" << std::endl;
    else
        std::cout << "Majority element is " << dominant << std::endl;

    return a.exec();
}


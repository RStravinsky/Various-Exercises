#include <QCoreApplication>
#include <iostream>
#include <bitset>

using namespace std;

unsigned int reverseBits(unsigned int num)
{
    unsigned int BITS = sizeof(num)*8;
    unsigned int reverse = 0;

    for(uint i=0; i<BITS;++i)
    {
        if(num&(1<<i))
            reverse |= 1 << (BITS - 1 - i);
    }
    return reverse;
}


int main(int argc, char *argv[])
{
    unsigned int number;
    cout << "Enter number: ";
    cin >> number;
    std::cout << "Number in binary = " << std::bitset<32>(number) << std::endl;

    cout << "Reversed number = " << std::bitset<32>(reverseBits(number)) << endl;

    return 0;
}


#include <iostream>

using namespace std;

int add(int a, int b)
{
    while(b)
    {
        int c = a & b;
        a = a^b;
        b = c << 1;
    }

    return a;
}

int subtract(int a, int b)
{
    while (b)
    {
        int c = (~a) & b;
        a = a ^ b;
        b = c << 1;
    }

    return a;
}

int multiply(int a, int b)
{
   if(b == 0)
     return 0;

   /* Add x one by one */
   if(b > 0 )
     return (a + multiply(a, b-1));

  /* the case where y is negative */
   if(b < 0 )
     return -multiply(a, -b);
}

int main(int argc, char *argv[])
{
    int a,b;
    cout << "Enter first value: ";
    cin >> a;

    cout << "Enter second value: ";
    cin >> b;

    cout << "Add= " << add(a,b) << endl;
    cout << "Subtract= " << subtract(a,b) << endl;
    cout << "Multiply= " << multiply(a,b) << endl;

    return 0;
}


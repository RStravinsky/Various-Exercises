#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int powerRecursive(int _base, int _exponent)
{
    return (_exponent==0) ? 1 :_base*powerRecursive(_base,--_exponent);
}

int power(int _base, int _exponent)
{       
    int power = 1;
    while (--_exponent >= 0)
        power *= _base;
    return power;
}


long long pot_szybkie(long long a, unsigned int n)
{
  long long w = 1;

  while(n!=0)
  {
    if (n%2 == 1) //jesli bit jest = 1
      w *= a;

    a*= a;
    n/=2; //skrócenie o jeden bit
  }
  return w;
}

int powerMinus(int _base, int _exponent)
{
    int temp;
    if( _exponent == 0)
       return 1;
    temp = power(_base, _exponent/2);
    if (_exponent%2 == 0)
        return temp*temp;
    else return _base*temp*temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int base;
    int exponent;

    cout << "Enter base = ";
    cin >> base;

    cout << "Enter exponent = ";
    cin >> exponent;

    cout << "Recursive value = " << powerRecursive(base,exponent) << endl;
    cout << "Value  = " << power(base,exponent) << endl;
    cout << "Recursive value2  = " << pot_szybkie(base,exponent) << endl;

    return a.exec();
}

#include <iostream>

using namespace std;

long long fpb(long long a,long long b)
{
    if(b == 0)
    {
      return a;
    } else {
      return fpb(b, a % b);
    }
}

long long kpk(long long a, long long b)
{
    return a*b/fpb(a,b);
}
int main()
{
    long long a,b,c,d,bb,aa,cc,dd;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

    bb = kpk(b,d);
    aa = bb/b*a;
    cc = bb/d*c;
    dd = aa+cc;

    while(fpb(dd,bb) != 1)
    {
      long long divisor = fpb(dd,bb);
      dd /= divisor;
      bb /= divisor;
    }

    printf("%lld %lld\n", dd, bb);
}

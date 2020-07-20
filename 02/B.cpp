#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

long long k;
long long res;
long long cnt = 0;
vector<long long> primess;
vector<long long> simpleSieve(long long n)
{
    vector<long long> primes;
    bool eliminated[n+1];
    memset(eliminated,0,n+1);
    for(int i = 2; i <= n; i++)
    {
      if(!eliminated[i])
      {
        cnt++;
        primes.push_back(i);
        primess.push_back(i);
        int j = i*i;
        while(j <= n){
          eliminated[j] = 1;
          j += i;
        }
      }
    }

    return primes;
}

void segmentedSieve(int n)
{
  int limit = sqrt(n)+1;
  vector<long long> primes = simpleSieve(limit);

  int low  = limit;
  int high = 2*limit;


  while(low < n)
  {

    if(high > n)
      high = n;

    bool eliminated[limit+1];
    memset(eliminated,0,sizeof(eliminated));

    for(int i = 0 ; i < primes.size(); i++)
    {

       int loLim = floor(low/primes[i]) * primes[i];
       if(loLim < low)
          loLim += primes[i];

       for(int j = loLim ; j < high ; j+=primes[i])
       {
           eliminated[j-low] = 1;
       }
    }

    for(int i = low; i < high ; i++)
    {
      if(!eliminated[i-low]){
        primess.push_back(i);
      }
    }

    low += limit;
    high += limit;

  }

}

int main()
{
    long long t;

    scanf("%lld", &t);
    segmentedSieve(1000000);
    while(t--)
    {
      scanf("%lld", &k);
      cnt = 0;
      printf("%lld\n", primess[k-1]);
    }
}

#include <iostream>
#include <vector>

using namespace std;

int fpb(int a, int b)
{
    if(b == 0)
    {
      return a;
    } else {
      return fpb(b, a%b);
    }
}

int kpk(int a, int b)
{
    return a*b/fpb(a,b);
}

int main()
{
    int n;
    vector<int> d;
    scanf("%d", &n);
    while(n--)
    {
       int x;
       scanf("%d", &x);
       d.push_back(x);
    }

    int res = d[0];
    for(int i = 1 ;i < d.size(); i++)
    {
       res = kpk(res,d[i]);
    }

    printf("%d\n", res);
}

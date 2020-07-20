#include <iostream>
#include <vector>

using namespace std;

int x,y;
int n;
vector<int>  arr;
int search(int x, int y)
{
  int kiri, kanan, tengah,h1,h2 = -1;
  kiri = 0;
  kanan = arr.size()-1;
  h1 = -1;

  if(x == y) return 0;

  while(kiri <= kanan && h1 == -1)
  {
    tengah = (kanan+kiri)/2;
    if(arr[tengah] > x)
    {
      kanan = tengah - 1;
      if(kiri == tengah || kanan == tengah)
        h1 = tengah;
    } else if(arr[tengah] < x)
    {
      kiri = tengah + 1;
      if(kiri == tengah || kanan == tengah)
        h1 = kiri;
    } else if(arr[tengah] == x){
      if(kanan != kiri)
      {
        kiri = tengah+1;
      }else{
        h1 = tengah + 1;
      }
    } else {
      h1 = tengah + 1;
    }
  }

  kiri = 0;
  kanan = arr.size() - 1;
  while(kiri <= kanan && h2 == -1)
  {
    tengah = (kanan+kiri)/2;
    if(arr[tengah] > y)
    {
      kanan = tengah - 1;
      if(kiri == tengah || kanan == tengah)
        h2 = tengah - 1;
    } else if(arr[tengah] < y)
    {
      kiri = tengah + 1;
      if(kiri == tengah || kanan == tengah)
        h2 = tengah;
    } else
    {
      if(kiri != kanan)
        kiri = tengah+1;
      else
      h2 = tengah;
    }
  }

  if(h1 < 0 || h2-h1+1 < 0) return 0;
  return h2-h1 + 1;
}

int main()
{

  scanf("%d", &n);

  for(int i = 1 ;i <= n ; i++)
  {
     int o;
     scanf("%d", &o);
     arr.push_back(o);
  }

  scanf("%d", &n);

  while(n--)
  {
     scanf("%d %d", &x, &y);
     cout<<search(x,y)<<endl;
  }

}

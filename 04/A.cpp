#include <iostream>
#include <vector>

using namespace std;
int ch[5] = {1,1,1,1,1};
string s[5] = {"identik", "diagonal kiri bawah", "horisontal", "vertikal", "diagonal kanan bawah"};
int n,m,n1,m1;
int arr[100][100];
int arr1[100][100];
void solve()
{

  for(int i = 0; i < n ;i++)
  {
    for(int j = 0 ; j < m ; j++)
    {
       //identik
       if(arr[i][j] != arr1[i][j])
         ch[0] = 0;
       //diagonal kiri bawah
       if(arr[i][j] != arr1[n-j-1][n-i-1])
         ch[1] = 0;
       //horizontal
       if(arr[i][j] != arr1[n-i-1][j])
         ch[2] = 0;
       //vertical
       if(arr[i][j] != arr1[i][m-j-1])
         ch[3] = 0;
       //diagonal kanan bawah
       if(arr[i][j] != arr1[j][i])
         ch[4] = 0;

    }
  }

}
int main()
{

    scanf("%d %d", &n, &m);


    for(int i = 0 ; i < n; i++)
    {
      for(int j = 0 ;j < m ; j++)
      {
        scanf("%d", &arr[i][j]);
      }
    }

    scanf("%d %d", &n1, &m1);

    for(int i = 0 ; i < n1; i++)
    {
      for(int j = 0 ; j < m1 ;j++)
      {
        scanf("%d", &arr1[i][j]);
      }
    }

  solve();

  for(int i = 0 ; i < 5; i++)
  {
    if(ch[i]){
      cout<<s[i]<<endl;
      return 0;
    }
  }

  cout<<"tidak identik\n";
  return 0;
}

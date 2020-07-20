#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortby(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b)
{
    return (a.second[2] > b.second[2]) || ((a.second[2] == b.second[2]) && (a.second[1] > b.second[1])) || ((a.second[2] == b.second[2] && (a.second[1] > b.second[1])));
}

int main()
{
  int n;

  scanf("%d", &n);
  while(n--)
  {
    int k,l;
    string s;
    scanf("%d %d", &k, &l);
    cin>>s;

    vector<pair<string,vector<int>>> b;
    for(int i = 0; i < k ; i++)
    {
      string id;
      int s1,s2,s3;
      cin>>id>>s1>>s2>>s3;
      vector<int> a = {s1,s2,s3};
      b.push_back(pair<string,vector<int>>(id,a));
    }

    sort(b.begin(), b.end(), sortby);

    bool found = false;
    for(int i =0 ;i < l ; i++)
    {
      if(b[i].first == s) found=true;
    }

    (found) ? printf("YA\n") : printf("TIDAK\n");

  }

  return 0;
}

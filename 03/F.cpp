#include <iostream>
#include <vector>

using namespace std;
int q;
string r;

void merge(vector<int> &numb, vector<string> &s, int aLeft, int aRight, int bLeft, int bRight);

void mergeSort(vector<int> &numb, vector<string> &s, int left, int right)
{
    if(left == right)
      return;
    else {
      int m = (left+right)/2;
      mergeSort(numb,s,left,m);
      mergeSort(numb,s,m+1,right);
      merge(numb,s,left,m,m+1,right);
    }
}

void merge(vector<int> &numb, vector<string> &s, int aLeft, int aRight, int bLeft, int bRight)
{

  int size = bRight - aLeft + 1;
  int aIndex = aLeft;
  int bIndex = bLeft;
  vector<int> tempNumb;
  vector<string>tempString;
  while(aIndex <= aRight && bIndex <= bRight)
  {
    int aStringSize = s[aIndex].length();
    int bStringSize = s[bIndex].length();

    int minSize = min(aStringSize, bStringSize);

    int state = true;
    for(int i = 0 ;i < minSize; i++)
    {
       if(s[aIndex][i] > s[bIndex][i]){
         state = false;
         break;
       }
       else if(s[aIndex][i] < s[bIndex][i]){
         state = true;
         break;
       }
    }

    if(state){
      tempNumb.push_back(numb[aIndex]);
      tempString.push_back(s[aIndex]);
      aIndex++;
    } else {
      tempNumb.push_back(numb[bIndex]);
      tempString.push_back(s[bIndex]);
      bIndex++;
    }
  }

  while(aIndex <= aRight){
    tempNumb.push_back(numb[aIndex]);
    tempString.push_back(s[aIndex]);
    aIndex++;
  }

  while(bIndex <= bRight)
  {
    tempNumb.push_back(numb[bIndex]);
    tempString.push_back(s[bIndex]);
    bIndex++;
  }

  for(int i =0 ; i < size; i++)
  {
    numb[aLeft + i] = tempNumb[i];
    s[aLeft + i] = tempString[i];

    if(tempString[i] == r)
      q = aLeft + i;
  }

}
int main()
{
  int n;

  scanf("%d", &n);
  vector<string> s;
  vector<int> numb;

  for(int i = 0; i < n ; i++)
  {
    int temp = 1;
    string x;
    cin >> x;
    s.push_back(x);
    for(int j = 0 ; j < i ; j++)
    {
      if(s[i] >= s[j])
        temp++;
    }

    cout<<temp<<endl;
  }



  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void m(vector<int> &arr,vector<string> &arrL, int aLeft, int aRight, int bLeft, int bRight);

void mergeSort(vector<int> &arr, vector<string> &arrL,int left, int right)
{
    if(left == right)
      return;
    else {
      mergeSort(arr,arrL,left, (left+right)/2);
      mergeSort(arr,arrL,(left+right)/2+1, right);
      m(arr,arrL,left,(left+right)/2, (left+right)/2+1, right);
    }
}

void m(vector<int> &arr,vector<string> &arrL, int aLeft, int aRight,int bLeft, int bRight)
{
    int size = bRight - aLeft + 1;

    vector<int> temp;
    vector<string> tempString;

    int aIndex = aLeft;
    int bIndex = bLeft;
    while((aIndex <= aRight) && (bIndex <= bRight))
    {
      if(arr[aIndex] < arr[bIndex])
      {
        temp.push_back(arr[aIndex]);
        tempString.push_back(arrL[aIndex]);
        aIndex++;
      } else if(arr[aIndex] > arr[bIndex]){
        temp.push_back(arr[bIndex]);
        tempString.push_back(arrL[bIndex]);
        bIndex++;
      } else {
        bool st = false;
        for(int i = 0 ;i < arrL[aIndex].size();i++)
        {

          if(arrL[aIndex][i] > arrL[bIndex][i])
          {
            st = true;
            break;
          } else if(arrL[aIndex][i] < arrL[bIndex][i])
          {
            st = false;
            break;
          }
        }

        if(st){
          temp.push_back(arr[bIndex]);
          tempString.push_back(arrL[bIndex]);
          bIndex++;
        } else {
          temp.push_back(arr[aIndex]);
          tempString.push_back(arrL[aIndex]);
          aIndex++;
        }
     }

    }

    while(aIndex <= aRight)
    {
      temp.push_back(arr[aIndex]);
      tempString.push_back(arrL[aIndex]);
      aIndex++;
    }

    while(bIndex <= bRight)
    {
      temp.push_back(arr[bIndex]);
      tempString.push_back(arrL[bIndex]);
      bIndex++;
    }

    for(int i = 0; i < size; i++)
    {
      arr[aLeft + i] = temp[i];
      arrL[aLeft + i] = tempString[i];
    }

}

int main()
{

    int n;

    scanf("%d", &n);
    vector<string> s;
    vector<int> ss;

    for(int i = 0 ; i < n ; i++)
    {
      string a;
      cin >> a;
      s.push_back(a);
      ss.push_back(a.length());
    }

    mergeSort(ss,s,0,n-1);

    for(int i = 0 ;i < n ;i++)
    {
      cout<<s[i]<<endl;
    }


    return 0;
}

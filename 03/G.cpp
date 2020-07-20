#include <iostream>
#include <math.h>
using namespace std;

void merge(double arr[], int aLeft, int aRight, int bLeft, int bRight);

void mergeSort(double arr[], int left, int right)
{
    if(left != right)
    {
      int mid = (left+right)/2;
      mergeSort(arr,left,mid);
      mergeSort(arr,mid+1,right);
      merge(arr,left,mid,mid+1,right);
    }
}

void merge(double arr[], int aLeft, int aRight, int bLeft, int bRight)
{
    int tIndex = 0;
    int aIndex = aLeft;
    int bIndex = bLeft;

    int size = bRight - aLeft + 1;
    double temp[size];
    while(aIndex <= aRight && bIndex <= bRight)
    {
       if(arr[aIndex] <= arr[bIndex])
       {
          temp[tIndex] = arr[aIndex];
          aIndex++;
       } else {
          temp[tIndex] = arr[bIndex];
          bIndex++;
       }

       tIndex++;
    }

    while(aIndex <= aRight)
    {
      temp[tIndex] = arr[aIndex];
      aIndex++;
      tIndex++;
    }

    while(bIndex <= bRight)
    {
      temp[tIndex] = arr[bIndex];
      bIndex++;
      tIndex++;
    }

    for(int i = 0 ;i < size; i++)
    {
      arr[aLeft + i] = temp[i];
    }
}

int main()
{

  int n;

  scanf("%d", &n);

  double arr[1000000];
  for(int i = 0 ;i < n ; i++)
  {
    scanf("%lf", &arr[i]);
  }

  double mean;
  mergeSort(arr,0,n-1);
  if(n % 2 == 0)
  {
    mean = (arr[n/2] + arr[n/2-1])/2.0;
  } else {
    mean = arr[n/2];
  }

  printf("%.1lf\n", mean);
  return 0;
}

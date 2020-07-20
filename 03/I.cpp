#include <iostream>

using namespace std;

void merge(int arr[], int aLeft, int aRight, int bLeft, int bRight);

void mergeSort(int arr[], int left, int right)
{
    if(left != right)
    {
      int mid = (left+right) >> 1;
      mergeSort(arr, left, mid);
      mergeSort(arr,mid+1, right);
      merge(arr, left, mid, mid+1, right);
    }
}

void merge(int arr[], int aLeft, int aRight, int bLeft, int bRight)
{
    int size = bRight - aLeft + 1;
    int tIndex = 0;
    int aIndex = aLeft;
    int bIndex = bLeft;

    int temp[size];
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

    for(int i =0 ;i < size ; i++)
    {
      arr[aLeft + i] = temp[i];
    }
}

int main()
{
  int arr[100001];

  int n,x;

  scanf("%d %d", &n, &x);
  for(int i = 0;i < n ; i++)
  {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr,0,n-1);

  printf("%d\n", arr[x-1]);

  return 0;
}

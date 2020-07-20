#include <iostream>

using namespace std;

void merge(double w[], double c[], double avg[], int aLeft, int aRight, int bLeft, int bRight);

void mergeSort(double w[], double c[], double avg[], int left, int right)
{
    if(left!=right)
    {
      int mid = (left+right) >> 1;
      mergeSort(w,c,avg,left,mid);
      mergeSort(w,c,avg,mid+1,right);
      merge(w,c,avg,left,mid,mid+1,right);
    }
}

void merge(double w[],double c[],double avg[],int aLeft,int aRight,int bLeft,int bRight)
{
    int tIndex = 0;
    int size = bRight - aLeft + 1;
    int aIndex = aLeft;
    int bIndex = bLeft;

    double tempW[size];
    double tempC[size];
    double tempAvg[size];

    while(aIndex <= aRight && bIndex <= bRight)
    {
      if(avg[aIndex] >= avg[bIndex])
      {
          tempW[tIndex] = w[aIndex];
          tempC[tIndex] = c[aIndex];
          tempAvg[tIndex] = avg[aIndex];
          aIndex++;
      } else {
          tempW[tIndex] = w[bIndex];
          tempC[tIndex] = c[bIndex];
          tempAvg[tIndex] = avg[bIndex];
          bIndex++;
      }

      tIndex++;
    }

    while(aIndex <= aRight)
    {
      tempW[tIndex] =  w[aIndex];
      tempC[tIndex] = c[aIndex];
      tempAvg[tIndex] = avg[aIndex];
      aIndex++;
      tIndex++;
    }

    while(bIndex <= bRight)
    {
      tempW[tIndex] = w[bIndex];
      tempC[tIndex] = c[bIndex];
      tempAvg[tIndex] = avg[bIndex];
      bIndex++;
      tIndex++;
    }

    for(int i = 0 ;i < size; i++)
    {
      w[aLeft + i] = tempW[i];
      c[aLeft + i] = tempC[i];
      avg[aLeft + i] = tempAvg[i];
    }
}

int main()
{
    int n,x;
    double w[10000],c[10000],avg[10000];
    scanf("%d %d", &n, &x);


    for(int i = 0 ;i < n ; i++)
    {
        scanf("%lf", &w[i]);
    }

    for(int i = 0 ;i < n ; i++)
    {
      scanf("%lf", &c[i]);
      avg[i] = c[i]/w[i];
    }

    mergeSort(w,c,avg,0,n-1);

    int xx = 0;

    double cc = 0;

    int ii = 0;

    while(x && w[n-1] > 0){
      if(w[ii] <= x){
          xx += w[ii];
          x -= w[ii];
          cc += avg[ii] * w[ii];
          w[ii] -= w[ii];
       } else {
          xx += x;
          cc += x * avg[ii];
          w[ii] -= x;
          x = 0;
       }

       if(!w[ii])
         ii++;
    }

  printf("%.5f\n", cc);
}

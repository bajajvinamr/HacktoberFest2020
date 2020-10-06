#include<stdio.h>
#include<stdlib.h>
#define n 10000
#include<time.h>
int main(){
 clock_t t;
    t = clock();
 int arr[n];
 int i,j,m,temp,swap=0,comp=0;
 for(i=0;i<n;i++)
    arr[i]= rand() ;
 for(i=1;i<n;i++)
 { m=arr[i];
   j=i-1;
   comp++;
   while(j>=0 && arr[j]>m)
   {swap++;
    arr[j+1]=arr[j];
    j--; }
    arr[j+1]=m;
 }
 for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
  printf("\n");
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("Run Time:%f\n",time_taken);
  printf("Number of swapping:%d\n Number of Comparison:%d\n ",swap,comp);
 }

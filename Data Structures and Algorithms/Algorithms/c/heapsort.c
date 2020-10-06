#include<stdio.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void heapify(int ar[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n&&ar[l]>ar[largest])
        largest = l;

    if(r<n&&ar[r]>ar[largest])
        largest = r;
    
    if(largest!=i)  
    {
        swap(&ar[i],&ar[largest]); heapify(ar,n,largest);
    }
}

void heapSort(int ar[], int n)
{
    for(int i=n/2-1; i>=0; i--)
        heapify(ar,n,i);
    
    for(int i=n-1; i>0; i--)
    {
        swap(&ar[0],&ar[i]);
        
        heapify(ar,i,0);
    }
}

void printArray(int ar[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    
    printf("\n");
}

int main()
{
    int ar[]={12,11,13,5,6,7};
    int n=sizeof(ar)/sizeof(ar[0]);

    heapSort(ar,n);

    printf("Sorted Array is: \n");
    
    printArray(ar,n);
    return 0;
}
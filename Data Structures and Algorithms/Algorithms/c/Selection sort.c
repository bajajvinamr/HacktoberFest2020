#include<stdio.h>
void selection_sort(int A[],int n)
{
    int i,j,minimum;        
    for(i=0;i<n-1;i++) 
    {
        minimum = i ;
        for(j=i+1;j<n;j++) 
        {
            if(A[j] < A[minimum])  
            {
                minimum = j ;
            }
        }
        int temp = A[minimum];
        A[minimum] = A[i];
        A[i] = temp;
    }
    printf("Sorted array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
int main()
{
    int N,A[100],i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    selection_sort(A,N);
}

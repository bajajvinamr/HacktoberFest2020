include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main() { int n;
    cout<<"Enter the number of elements ";
    cin>>n;
    int A[n] ;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    int i,j; int c=0,s=0;
        for(i=0;i<n;i++){

                if(A[i]<=A[i+1]){
                    c++;
                }
            if(A[i]>=A[i+1]){
                s++;
            }
            }
         int r=n-1;
        if(c==r||s==r){
            cout<<"the array is monotonic";
        }
        else
        cout<<"the array is not monotonic";
   return 0; }

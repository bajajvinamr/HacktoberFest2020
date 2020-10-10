#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
    int msf = INT_MIN, meh = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        meh = meh + a[i]; 
        if (msf < meh) 
            msf = meh; 
  
        if (meh < 0) 
            meh = 0; 
    } 
    return msf; 
} 
  
int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t-->0){
	       int n;
	       cin>>n;
	       int a[n],j=n-1;
	       for(int i=0;i<n;i++)
	        cin>>a[i];
	        while(j>0&&a[j]<=a[j-1]) j--;
	        while(j>0&&a[j]>=a[j-1]) j--;
	    std::cout <<j<< std::endl;
	}
	return 0;
}

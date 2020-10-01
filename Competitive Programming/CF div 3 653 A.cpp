#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t-->0){
	       int x,y,n;
	       cin>>x>>y>>n;
	       int d=n/x;
	       int m=n%x;
	       int ans;
	       if(m==y)
	            cout<<n<<"\n";
	       else if(m>y){
	           ans=x*d+y;
	           cout<<ans<<"\n";
	       }     
	       else{ d--;
	             ans=x*d+y;
	             cout<<ans<<"\n";
	       }
	}
	return 0;
}

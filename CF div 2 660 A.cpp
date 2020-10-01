#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t-->0){
	    int n;
	    std::cin >> n;
	    if(n<=30) {std::cout << "NO" << std::endl; continue;}
	     
	    int s=n-30;
	    if(s!=6&&s!=14&&s!=10)
	        cout<<"YES\n"<<"6 10 14 "<<s<<"\n"; 
	    else if(s==6)
	        if(n>31) cout<<"YES\n"<<"10 6 15 "<<n-31<<"\n";
	        else cout<<"NO\n";
	    else if(s==10)
	        if(n>31) cout<<"YES\n"<<"6 10 15 "<<n-31<<"\n";
	        else cout<<"NO\n";
	   else if(s==14)
	        if(n>31) cout<<"YES\n"<<"6 15 10 "<<n-31<<"\n";
	        else cout<<"NO\n";
	}
	return 0;
}

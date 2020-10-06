#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k,time=240;
	cin >> n>>k;
	time=240-k;
	int solve=((n*(n+1))/2)*5;
	if(solve<=time) cout << n;
	else {
	int i;
	for(i=n;i>0;i--){
		solve=solve-(5*i);
		if(solve<=time) break;
	}
	cout << i-1;	
	}
	return 0;
}

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	vector<int>v;
	int n,groups=1;
	cin >> n;
	for(int i=0;i<n;i++){
	int t;cin>>t;
	v.push_back(t);
	if(i>0){
		if(v[i]!=v[i-1]) groups++;
		}	
	}
	cout << groups;
	return 0;
}

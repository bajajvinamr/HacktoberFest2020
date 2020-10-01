#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
	vector<int>v;
	string s;
	cin >> s;
	int n=s.size();
	for(int i=0;i<n;i++){
		int t;
		if(s[i]!='+'){
		t=(int)s[i]-48;
		v.push_back(t);
	}}
	sort(v.begin(),v.end());
	n=v.size();
	for(int i=0;i<n;i++){
	if (i!=n-1)cout << v[i]<<"+";
	else cout<< v[i];
	}
	
	return 0;
}

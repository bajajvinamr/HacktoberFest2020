#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
	string s;
	int k;
	cin >> s;
	k=s.size();
	if(k>10){
	k=k-1;
	s=s[0]+to_string(k-1)+s[k];
	}
	cout <<s<<'\n';
	
	}
	return 0;
}

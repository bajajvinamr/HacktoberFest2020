#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
	string s;
	cin >> s;
	char v[]={'A','E','I','O','U','Y'};
	for(int i=0;i<s.size();i++){
		for(int j=0;j<6;j++){
			if(s[i]==v[j]) s.erase(i,1);
			}
		}
		int k=s.size();
	for(int i=0;i<2*k-1;i+2){
		s.insert(i,1,'.');
	}	
	cout << s;
	return 0;
}

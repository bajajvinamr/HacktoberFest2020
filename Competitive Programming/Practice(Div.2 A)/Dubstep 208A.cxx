#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
	vector<char>v;
	string s;
	cin >> s;
	int wub=0;
	for(int i=0;i<s.size();i++){
	if((s[i]=='W')&&(s[i+1]=='U')&&(s[i+2]=='B')){ 
		wub++;
		i=i+2;
		}
	else {
	if(wub!=0) v.push_back(' ');
	v.push_back(s[i]);
	wub=0;
	}
	}
	int letter=0;
	for(int i=0;i<v.size();i++){
	if((v[i]==' ')&&(letter==0)){
		
	}
	else{
		letter ++;
		cout << v[i];
		}
	}
	return 0;
}

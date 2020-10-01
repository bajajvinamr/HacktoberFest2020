#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	n=min(n,m);
	if(n%2==0) cout << "Malvika";
	else cout << "Akshat";

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,m;
	cin >> n>>m;
	vector<int>v;
	v[0]=1;
	v[1]=1;
	v[2]=1;
	for(int i=3;i<n;i++){
		v[i]=min(v[i-1],v[i-2]) + 1;
		}	
	int t=0;
	if((v[n-1]+1)%m==0)	cout << v[n-1] +1;
	else if((v[n-2]+1)%m==0) cout << v[n-2] +1;
	else cout << -1;
	return 0;
}

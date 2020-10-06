#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int j;
		cin >> j;
		v.push_back(j);
		}	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
				int k,m,n,o;
				k=min(v[i],v[i+1]);
				m=max(v[i],v[i+1]);
				n=min(v[j],v[j+1]);
				o=max(v[j],v[j+1]);
				if(((k<n)&&(n<m))&&(m<o)){cout << "yes";return 0; }
				else if((n<k)&&((k<o)&&(o<m))){cout << "yes";return 0; }
			}
		}
	cout << "no";
	return 0;
}

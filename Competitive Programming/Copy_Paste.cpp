#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t = 0;
	cin >> t;
	while(t--) {
		long int n,k,x;
		cin>>n>>k;
		long int v[n];
		for(long int i = 0; i < n; i++) {
			cin>>v[i];
		}
		sort(v,v+n);
		long int divide = v[0];
		long int sum = 0;
		for(int i = 1; i < n; i++) {
		    sum = sum + (k - v[i])/v[0];
		}
		cout<<sum<<endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	long long int n,k;
	cin >> n >> k;
	if((n&1) == 0){
		if(k<=n/2) cout << (2*k)-1;
		else cout << 2*(k-(n/2));
		}
	else {
		long long int t;
		t=((n/2)+1);
		if(k<=t) cout << (2*k)-1;
		else cout << 2*(k-t);		
	}
	return 0;
}

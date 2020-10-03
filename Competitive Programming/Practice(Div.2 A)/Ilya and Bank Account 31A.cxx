#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,sum1,sum2;
	cin >> n;
	if(n>0) cout << n;
	else {
		n=-n;
		sum1=n/10;
		sum2=((n/100)*10)+(n%10);
		cout << -1*(min(sum1,sum2));
		}
	return 0;	
}

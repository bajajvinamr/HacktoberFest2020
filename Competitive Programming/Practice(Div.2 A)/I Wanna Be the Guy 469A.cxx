#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	bitset<101>a;
	bitset<101>b;
	int n,p,q;
	cin  >> n;
	cin >> p;
	for(int i=1;i<=p;i++){
	int j;
	cin >> j;
	a[j]=1;
	}
	cin >> q;
	for(int i=1;i<=q;i++){
	int j;
	cin >> j;
	a[j]=1;
	}
		
	int count = 0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) break;
		else count ++;
	}
	if(count==n) cout << "I become the guy.";
	else cout << "Oh, my keyboard!" ;
	return 0;
}

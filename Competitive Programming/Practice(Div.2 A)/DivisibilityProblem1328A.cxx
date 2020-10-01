#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
	int a,b,k,l;
	cin >> a >> b;
	if(a%b==0) cout<<0<<'\n';
	else {
		k=a%b;
		l=b-k;
		cout << l<<'\n';	
		}
	}

return 0;
}

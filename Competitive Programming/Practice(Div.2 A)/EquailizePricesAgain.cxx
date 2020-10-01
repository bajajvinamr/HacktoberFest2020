#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
	int t;
	cin >> t;
	int sum=0;
	for(int j=0;j<t;j++){
	 int k;
	 cin >> k;
	 sum=sum+k;
	 }	
	 if(sum%t==0) sum=sum/t;
	 else sum=(sum/t)+1;
	 
	 cout << sum<<'\n';
	}
	return 0;
}

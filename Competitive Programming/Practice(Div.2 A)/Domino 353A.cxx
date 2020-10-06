#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,asum,bsum;
	asum=bsum=0;
	cin >> n;
	vector<int>a;
	vector<int>b;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		a.push_back(j);
		asum=asum+j;
		cin>>j;
		b.push_back(j);	
		bsum=bsum+j;
		}
	if((asum+bsum)%2==0){
		if(asum%2!=0){
			for(int i=0;i<n;i++){
				if((a[i]%2==0)&&(b[i]%2!=0)){ cout << 1; return 0;}
				else if((a[i]%2!=0)&&(b[i]%2==0)){cout << 1; return 0;}
				}
				cout << -1;return 0;
			}
		else cout << 0;
		}
	else cout << -1;
	return 0;
}

#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int>a(101);
	vector<int>b(101);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
	int t;
	cin >> t;
	a[i]=t;
	b[t]=i;
	}
	for(int i=1;i<=n;i++)cout << b[i]<<' ';
	return 0;
}

#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(int argc, char **argv)
{
	int n,m;
	cin >> n>>m;
	set<int>s;
	for(int i=0;i<n;i++){
	int k;
	cin >> k;
	for(int j=0;j<k;j++){
		int t;
		cin >> t;
		s.insert(t);
	}
	}
	int bulbs=0;
	for(int i=1;i<=m;i++){
	 if(s.count(i)) bulbs++;
	 else break;	
	}
	if(bulbs==m) cout<<"YES";
	else cout<<"NO";
	return 0;
}


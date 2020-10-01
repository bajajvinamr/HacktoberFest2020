#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,math,pe,coder;
	cin >> n;
	math=coder=pe=0;
	vector<int>c;
	vector<int>p;
	vector<int>m;
	for(int i=1;i<=n;i++){
		int j;
		cin >> j;
		if(j==1) {coder++;c.push_back(i);}
		else if(j==2) {math++;m.push_back(i);}
		else if(j==3) {pe++;p.push_back(i);}	
		}
		if((coder==0)||(pe==0)||(math==0)) cout << 0;
		else {
			int t,teams=0;
			teams=min(coder,pe);
			teams=min(teams,math);
			cout << teams << '\n';
			t=teams;
			for(int i=0;i<n;i++){
				if(t>0){
					cout << c[i]<<' '<<m[i]<<' '<<p[i]<<'\n';
					t--;
					}
				else return 0;	
				}
			}
	return 0;
}

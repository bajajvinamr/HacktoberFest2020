#include <iostream>
#include <vector>
using namespace std;
int main(){
		int n;
		cin >> n;
		vector<int>h;
		vector<int>g;
		for(int i=0;i<n;i++){
		int t=0;
		cin >>t;
		h.push_back(t);
		cin >> t;
		g.push_back(t);
		}
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
					if(h[i]==g[j]) count++;
					if(g[i]==h[j]) count++;
			}
		}
		cout<<count;
					
		return 0;
}

//Link to problem: https://www.codechef.com/COOK123B/problems/DECREM 
#include <iostream>
using namespace std;

int main() {
	int T,L,R; cin>>T;
	for(int i=0;i<T;i++){
	    cin>>L>>R;
	    if(R/L>1)cout<<"-1\n";
	    else cout<<R<<'\n';
	    
	}
	return 0;
}


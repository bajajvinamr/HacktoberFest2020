#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,sumx,sumy,sumz;
	sumx=sumy=sumz=0;
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin >> x;
		cin >> y;
		cin >> z;
		sumx=sumx+x;sumy=sumy+y;sumz=sumz+z;
		}
		if(sumx) cout << "NO";
		else if(sumy) cout << "NO";
		else if(sumz) cout << "NO";
		else cout << "YES";
	return 0;	
}

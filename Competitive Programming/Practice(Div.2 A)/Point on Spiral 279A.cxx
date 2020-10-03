#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,x,y,absx,absy;
	cin >> x>>y;
	if(x>0) absx=x;
	else absx=-x;
	if(y>0) absy=y;
	else absy=-y;
	n=max(absx,absy)-1;
	if((x==y)&&(x==0)) {cout << 0; return 0;}
	if((x==1)&&(y==0)) { cout<< 0;return 0;}
	if(x>0){
		if(y>=0){
		if(x<y) cout << (4*n) +1;
		else if(x>=y)cout << (4*n)+4;
		else if(y==0) cout << (4*n)+4;
		}
		else{
			if(x>=(-y)) cout << (4*n)+4;
			else if(x<(-y)) cout << (4*n)+3;
			}
		}
	else {
		if(y>0){ 
			if (y>(-x))cout << (4*n)+1;
			else if(y<=(-x)) cout << (4*n)+2;
			}
		else cout << (4*n)+3;
		}
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int x1,y1,x2,y2;
	cin >>x1>>y1>>x2>>y2;
	int delY,delX;
	delY=y2-y1;
	delX=x2-x1;
	if((delY==delX)||(delY==-delX)){
		cout << x1 <<' '<< y2 <<' '<< x2<<' '<<y1;
	}
	else if(x1==x2){
		if(delY>=0) cout << x1+delY <<' '<< y2 <<' '<< x1+delY<<' ' << y1;
		else cout << x1-delY << ' '<< y2<<' ' << x1-delY<<' ' << y1;
		}
	else if(y1==y2){
		if(delX>=0) cout<<x1<<' '<<y1+delX<<' '<<x2<<' '<<y1+delX;
		else cout<<x1<<' '<<y1-delX<<' '<<x2<<' '<<y1-delX;
		}
	else cout << -1;
	return 0;
}

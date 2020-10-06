#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int x,y,z,a,b,c;
	cin >> x >> y >> z >> a >> b >> c;
	int g,leftover;
	g=a-x;
	leftover=g+b+c-y;
	if(a<x) cout << "NO";
	else if((g+b)-y<0)cout << "NO";
	else if(leftover-z< 0)cout << "NO";
	else cout<<"YES";
  return 0;
}

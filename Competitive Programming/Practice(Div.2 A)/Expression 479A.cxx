#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int a,b,c,k,max;
	cin >> a >> b >> c;
	max=0;
	k=a*b*c;
	if(k>max) max=k;
	k=(a*b)+c;
	if(k>max) max=k;
	k=a+(b*c);
	if(k>max) max=k;
	k=(a+b)*c;
	if(k>max) max=k;
	k=a*(b+c);
	if(k>max) max=k;
	k=a+b+c;
	if(k>max) max=k;
	cout << max;
	return 0;
}

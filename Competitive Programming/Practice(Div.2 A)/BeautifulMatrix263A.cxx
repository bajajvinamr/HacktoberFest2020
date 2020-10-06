#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int i,j,row,col;
for(i=1;i<6;i++){
for(j=1;j<6;j++){
	int t;
	cin >> t;
	if(t==1){
	row=i;
	col=j;
	}
}	
}
	int k,l;
	k=3-row;
	l=3-col;
	if(k<0) k=-1*k;
	if(l<0)l=-1*l;
	cout<<(l+k);
return 0;	
}

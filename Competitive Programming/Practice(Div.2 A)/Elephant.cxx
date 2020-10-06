#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v(1000000);
//int path(int);

int main(){
		int d;
		cin >> d;
		int t;
//t=path(d);		
		v[0]=0;v[1]=v[2]=v[3]=v[4]=v[5]=1;
		for(int i=6;i<1000001;i++){
			v[i]=min({v[i-5],v[i-4],v[i-3],v[i-2],v[i-1]})+1;
		}
		cout << v[d];
		return 0;
}
/*int length=0;
int path (int d){
	if(d<=0) length=0;
	else
	length=min({path(d-5),path(d-4),path(d-3),path(d-2),path(d-1)})+1;
	return length;
	
}*/

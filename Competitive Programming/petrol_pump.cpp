#include<bits/stdc++.h>
using namespace std;
int maxi=INT_MAX;
int maxx(int a,int b)
{
	return (a>b)?a:b;
}
void calTime(int total,int sum,int i,vector<int> v1)
{
	
	if(maxx(sum,total-sum)<maxi)
	{
		maxi=maxx(sum,total-sum);
	}
	if(v1[i])
	 return;
	calTime(total,sum+v1[i],i+1,v1);
	calTime(total,sum,i+1,v1);
	return;
}
int main()
{
	int n,i=1,sum=0;
	string s;
	vector<int>v1;
	getline(cin,s,'\n');
	stringstream ss(s);
	while(ss>>n)
	{
		sum+=n;
		v1.push_back(n);
	}
	calTime(sum,0,0,v1);
	cout<<maxi;
}

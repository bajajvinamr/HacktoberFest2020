//Split the Str ing 
// link to question: https://www.codechef.com/COOK123B/problems/SPLITIT
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string S;
	int T, len;
	cin>>T;
	while(T>0)
	{	
		int flag = 0;
		cin>>S;
		len = S.length();
		for(int i=0;i<len-1;i++)
		{
			if(S[i]==S[len-1])
				flag++;
		}
		if(flag==0) cout<<"NO\n";
		else cout<<"YES\n";
		T--;
	 } 
}

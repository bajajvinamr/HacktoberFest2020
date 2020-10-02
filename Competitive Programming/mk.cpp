#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
bool sortt(const pair<int,string> &a,  
               const pair<int,string> &b) 
{ 
       return (a.first > b.first); 
} 
int checksum(int a){
    int sum=0;
    while(a){
        sum+=a%10;
        a/=10;
    }
    return sum;
}
signed main()
{
    fast
    int n,i;
    cin>>n;
    for(i=n; ;i++){
        if(checksum(i)%4==0){
            break;
        }
    }
    cout<<i<<endl;
}

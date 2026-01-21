#include<bits/stdc++.h>
using namespace std;
#define FOR(az,c)   for ( int (az)=0; (az)<(c); (az)++)
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
    cin>>n;
    int a[n];
    FOR(i,n)
    {
        cin>>a[i];
    }
    if(a[0]<a[n-1]){
        cout<<"YES"<<endl;
    }
   
    else {
    cout<<"NO"<<endl;
    }
 
    }
    
    return 0;
}

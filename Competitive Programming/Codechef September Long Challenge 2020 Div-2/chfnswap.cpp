#include<bits/stdc++.h>
typedef long long int lli;
typedef long double ld;
using namespace std;
lli a,b,l,r,dif;
lli check(){
    if(dif<a || dif>r)return 0;
    if(dif<b)return min(dif,r-b);
    return (r-dif);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli s=(n*(n+1))/2;
        if(s%2!=0){
            cout<<0<<"\n";
            continue;
        }
        ld k=(sqrt((ld)4*s+1.0)-1.0)/2.0;
        lli m=k,ans=0;
        lli sm=(m*(m+1))/2;
        dif=s/2-sm;
        a=1;
        b=m;
        l=m+1;
        r=n;
        lli lm=n-m;
        if(dif==0)ans+=((m*(m-1))/2+(lm*(lm-1))/2);
        else ans+=check();
        m--;
        sm=(m*(m+1))/2;
        dif=s/2-sm;
        a=1;
        b=m;
        l=m+1;
        r=n;
        lm=n-m;
        if(dif==0)ans+=((m*(m-1))/2+(lm*(lm-1))/2);
        else ans+=check();
        cout<<ans<<"\n";
    }
    return 0;
}
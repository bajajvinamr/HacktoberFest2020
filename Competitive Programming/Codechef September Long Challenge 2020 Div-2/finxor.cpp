#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,i,a[21],bit[20];
        cin>>n;
        lli x=2;
        for(i=1;i<21;i++){
            cout<<1<<" "<<x<<endl;
            x*=2;
            cin>>a[i];
        }
        lli sum=a[20]-n*pow(2,20);
        for(i=1;i<20;i++){
            lli y,x=pow(2,i);
            y=(sum-a[i]+(n*x))/2;
            lli temp=y/x;
            if(temp%2==0){
                bit[i]=0;
            }
            else{
                bit[i]=1;
            }
        }
        if(sum%2==0){
            bit[0]=0;
        }
        else{
            bit[0]=1;
        }
        lli ans=0,j=1;
        for(i=0;i<20;i++){
            ans+=(j*bit[i]);
            j*=2;
        }
        cout<<2<<" "<<ans<<endl;
        int check;
        cin>>check;
    }
}
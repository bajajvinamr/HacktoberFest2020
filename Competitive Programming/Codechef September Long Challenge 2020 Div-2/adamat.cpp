#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli a[n][n],i,j,k,f=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        lli arr[65]={};
        arr[0]=0;
        arr[1]=0;
        for(i=2;i<=n;i++){
            f=0;
            for(j=0;j<i;j++){
                if(a[j][i-1]!=j*n+i){
                    f=1;
                    break;
                }
            }
            if(f==1)arr[i]=0;
            else arr[i]=1;
        }
        lli ans=0;
        for(i=n;i>=2;i--){
            if(arr[i]!=1){
                for(j=i;j>=2;j--){
                    arr[j]==0?arr[j]=1:arr[j]=0;
                }
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
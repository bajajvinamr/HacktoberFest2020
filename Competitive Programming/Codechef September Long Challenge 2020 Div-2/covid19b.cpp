#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli v[n],i;
        for(i=0;i<n;i++)cin>>v[i];
        lli a[n][2],j,k,l,mm;
        lli inf[n][n];
        double time[n][n];
        for(i=0;i<n;i++){
            a[i][0]=-i;
            a[i][1]=v[i];
            for(j=0;j<n;j++){
                if(i==j){
                    inf[i][j]=1;
                    time[i][j]=0.0;
                }
                else{
                    inf[i][j]=0;
                    time[i][j]=-1.0;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if((a[i][0]-a[j][0])*(a[i][1]-a[j][1])>0){
                        time[i][j]=(double)(a[i][0]-a[j][0])/(double)(a[i][1]-a[j][1]);
                        inf[i][j]=1;
                    }
                    else time[i][j]=-1.0;
                }
            }
        }
        // for(i=0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         cout<<time[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        lli count=1,mx=1,mn=n;
        for(i=0;i<n;i++){
            count=1;
            for(j=0;j<n;j++){
                if(j!=i && time[i][j]>0){
                    count++;
                    for(k=0;k<n;k++){
                        if(k!=i && k!=j && time[j][k]>0 && inf[i][k]==0){
                            if(time[i][j]<time[j][k]){
                                count++;
                                inf[i][k]=1;
                                for(l=0;l<n;l++){
                                    if(l!=i && l!=j && l!=k && time[k][l]>0 && inf[i][l]==0){
                                        if(time[k][l]>time[j][k]){
                                            inf[i][l]=1;
                                            count++;
                                            for(mm=0;mm<n;mm++){
                                                if(mm!=i && mm!=j && mm!=k && mm!=l && time[l][mm]>0 
                                                && inf[i][mm]==0){
                                                    if(time[l][mm]>time[k][l]){
                                                        inf[i][mm]=1;
                                                        count++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //cout<<count<<" ";
            mx=max(count,mx);
            mn=min(count,mn);
        }
        cout<<mn<<" "<<mx<<endl;
    }
}
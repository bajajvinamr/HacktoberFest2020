#include <bits/stdc++.h>
# define ll long long int
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int brr[k];
        for(int i=0;i<k;i++)
            cin>>brr[i];
            sort(arr,arr+n,greater<int>());
            sort(brr,brr+k);
            set<int>s[k];
            int i=0;
            for(int i=0;i<k;i++){
                s[i].insert(arr[i]);
            }
            int j=k;
            for(int i=0;i<k;i++){
                for(int l=1;l+1<=brr[i];l++){
                    s[i].insert(arr[j]);
                    j++;
                }
            }
            long long int sum=0;
            for(int i=0;i<k;i++){
                auto it=s[i].begin();
                sum+=*it;
                it=s[i].end();
                it--;
                sum+=*it;
            }
            cout<<sum<<"\n";
    }
    
	return 0;
}
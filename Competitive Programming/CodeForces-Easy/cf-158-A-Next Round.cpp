#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k; cin >> n >> k;
    int ans=0;
    vector<int> val(n);
    for(int i = 0;i<n;i++) cin >> val[i];
    for(auto x: val){
        if(x>=val[k-1] && x > 0) ans+=1;
    }
    cout << ans << endl;

}

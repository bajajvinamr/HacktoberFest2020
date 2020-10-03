#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    for(int T = 0; T < t ; T++){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll a[n], pre[n + 1], suf[n + 1];
        pre[0] = 0, suf[n - 1] = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                pre[i + 1] = pre[i] + 1;
            else
                pre[i + 1] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1')
                suf[i - 1] = suf[i] + 1;
            else
                suf[i - 1] = 0;
        }
        // for(int i = 0; i <= n; i++)
        //     cout << pre[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= n; i++)
        //     cout << suf[i] << " ";
        // cout << endl;
        ll ans = 0;
        for(int i = 0; i < n - k + 1; i++){
            ans = max(ans, pre[i] + k + suf[i+k-1]);
        }
        cout << ans << endl;
    }
    return 0;
}

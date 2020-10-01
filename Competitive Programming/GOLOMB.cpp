#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll max_limit=2*10e6;
const ll MOD=1000000007;
const ll mod=1000000007;

ll golomb[max_limit+1],freq_sum[max_limit+1],sumsquares[max_limit+1];

ll power(ll a, ll p, ll m) {
	if(p == 0) return 1l;
	ll res = 1;
	while(p > 0) {
		if(p % 2) {
			res *= a;
			if(res > m){
				res %= m;
			}
		}
		a *= a;
		if(a > m) a %= m;
		p >>= 1;
	}
	return res;
}

ll add(ll a, ll b) {
	ll c = a + b;
	if(c >= mod) c -= mod;
	return c;
}

ll mul(ll a, ll b) {
    if(a >= mod) a %= mod;
    if(b >= mod) b %= mod;
	ll c = a * b;
	if(c >= mod) c %= mod;
	return c;
}

ll sub(ll a, ll b) {
	ll c = a - b + mod;
	if(c >= mod) c -= mod;
	return c;
}

ll binarysearch(ll R,ll start,ll end)
{
    ll mid = start + (end-start)/2;
    if(R>=freq_sum[mid-1] && R<=freq_sum[mid]) return mid-1;
    else if(R>=freq_sum[mid] && R<=freq_sum[mid+1]) return mid;
    else if(freq_sum[mid]>R) return binarysearch(R,start,mid-2);
    else return binarysearch(R,mid+1,end);
}

ll squares(ll R)
{
    ll index = binarysearch(R,1,max_limit);
    ll answer = power(index+1,2,MOD);
    answer = mul(answer,sub(R,freq_sum[index]));
    if(R==0) answer=0;
    ll res = add(sumsquares[index],answer);
    return res;
}

int32_t main()
{
    FASTIO;
    ll T;
    cin >> T;
    golomb[1] = 1;
    for(ll i=2;i<max_limit;i++)
        golomb[i] = 1 + golomb[i-golomb[golomb[i-1]]];

    freq_sum[1] = golomb[1];

    for(ll i=2;i<=max_limit;i++) freq_sum[i] = freq_sum[i-1] + golomb[i];
    sumsquares[1] = 1;

    for(ll i=2;i<=max_limit;i++)
    {
        ll temp = mul(power(i,2,MOD),golomb[i]);
        sumsquares[i] = add(temp,sumsquares[i-1]);
    }

    while(T--)
    {
        ll L,R;
        cin >> L >> R;
        ll answer = sub(squares(R),squares(L-1));
        cout << answer%MOD << '\n';
    }
    return 0;
}

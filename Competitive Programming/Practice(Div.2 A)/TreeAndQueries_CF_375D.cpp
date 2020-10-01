#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
#define all(a) a.begin(),a.e()
#define mod 1000000007
#define pi 3.141592653589
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod) ;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//(*****FOR USING ORDERED SET CHANGE INT*******)

const int maxN = 100001 ;

int BLK = 2000 ;

vi v[maxN] ;
int a[maxN], start[maxN], e[maxN], timer, ft[2*maxN] ;
int nodeF[maxN], eleF[maxN], FF[maxN] = {0}, ans[maxN] ;
int bucket[maxN], n, q, sz ;

struct query {
    int l, r, ind, k ;
};

query Q[maxN] ;

int getBLK(int n) {
    return (n+BLK-1)/BLK ;
}

void dfs(int n, int p) {
    ft[timer] = n ;
    start[n] = timer ;
    timer++ ;
    for(auto i : v[n]) {
        if(i != p) {
            dfs(i, n) ;
        }
    }
    e[n] = timer ;
    ft[timer] = n ;
    timer++ ;
}

void add(int inx) {
    int node = ft[inx] ;
    int col = a[node] ;
    nodeF[node]++ ;
    if(nodeF[node] == 2) {
        eleF[col]++ ;
        FF[eleF[col]]++ ;
        bucket[getBLK(eleF[col])]++ ;
        
        FF[eleF[col]-1]-- ;
        bucket[getBLK(eleF[col]-1)]-- ;
    }
}

void remove(int inx) {
    int node = ft[inx] ;
    int col = a[node] ;
    nodeF[node]-- ;
    if(nodeF[node] == 1) {
        eleF[col]-- ;
        FF[eleF[col]]++ ;
        bucket[getBLK(eleF[col])]++ ;

        FF[eleF[col]+1]-- ;
        bucket[getBLK(eleF[col]+1)]-- ;
    }
}

bool comp(query a, query b) {
    if(a.l/BLK != b.l/BLK) {
        return a.l/BLK < b.l/BLK ;
    }
    if(a.l/BLK % 2) 
        return a.r < b.r ;
    else 
        return a.r > b.r ;
}

int getans(int k, int n) {
    int ans = 0 ;
    int L = getBLK(k) ;
    int R = getBLK(n) ;
    if(L == R) {
        rep(i, k, n+1) ans += FF[i] ;
        return ans ;
    }
    rep1(i, k, L*BLK) {
        ans += FF[i] ;
    }
    rep(i, L+1, R) ans += bucket[i] ;
    rep(i, R*BLK+1, n+1) ans += FF[i] ;
    return ans ; 
}

signed main() {
    quickie
    cin >> n >> q ;
    rep(i, 1, n+1) cin >> a[i] ;
    rep(i, 0, n-1) {
        int a, b ;
        cin >> a >> b ;
        v[a].pb(b) ;
        v[b].pb(a) ;
    }
    timer = 1 ;
    dfs(1, -1) ;
    rep1(i, 1, q) {
        int a, k;
        cin >> a >> k;
        Q[i].l = start[a] ;
        Q[i].r = e[a] ;
        Q[i].k = k ;
        Q[i].ind = i ;
    }
    sort(Q+1, Q+q+1, comp) ;
    int ML = 0, MR = -1 ;
    rep(i, 1, q+1) {
        int L = Q[i].l ;
        int R = Q[i].r ;
        int ind = Q[i].ind ;
        int k = Q[i].k ;

        while(ML > L) {
            ML-- ;
            add(ML) ;
        }
        while(MR < R) {
            MR++ ;
            add(MR) ;
        }
        while(ML < L) {
            remove(ML) ;
            ML++ ;
        }
        while(MR > R) {
            remove(MR) ;
            MR-- ;
        }
        ans[ind] = getans(k, n) ;
    }
    rep(i, 1, q+1) cout << ans[i] << "\n" ;
}

int power(int x, int y) {
    int res = 1; x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
 

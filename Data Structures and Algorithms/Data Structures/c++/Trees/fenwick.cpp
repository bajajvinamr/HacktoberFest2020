#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include<numeric>
#include <string>
#include <vector>
#include <list>
#include <set>
#include<iomanip>
#include<unordered_map>
#include<climits>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
//#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ld long double
#define MOD 1000000007
#define mod 998244353
#define vi vector<int>
#define precise(i) fixed << setprecision(10) << i
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(a) a.begin(),a.end()
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fr1(i,n) for(int i=0;i<(n);i++)
#define fr2(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>   new_data_set;
/////////////////////////////////////////////////////////////////////
ll bit[200007],a[200007],n;
void update(int x,int data){
    for(;x<=n;x+=x&(-x)){
        bit[x]+=data;
    }
}

ll sum2(int r){
    ll sum=0;
    for(;r>0;r-=r&(-r)){
        sum+=bit[r];
    }
    return sum;
}
ll sum1(int l,int r){
    
    return sum2(r)-sum2(l-1);
}
int main()
{
    cin >> n ;
    fr2(i,1,n){
        cin >> a[i];
        update(i,a[i]);
    }
    
    return 0;
}

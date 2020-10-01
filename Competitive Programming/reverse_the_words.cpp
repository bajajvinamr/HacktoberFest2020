#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define mod 1000000009
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1]*i)%mod)
#define ncr(n, r) (n>=r?((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod):0LL)
// Program to reverse a string

void rev(string &s){
  int st=0;
  for(int en=0;en<s.length();en++){
    if (s[en] == ' ') {
            reverse(s.begin() + st, s.begin() + en);
            st = en + 1;
        }
  }
  reverse(s.begin() + st, s.end());
  reverse(s.begin(), s.end());
}
int main(){
  string s = "I want to programmmmmm";
  rev(s);
  cout<<"The reversed string is: "<<endl;
  cout<<s;
  return 0;
}

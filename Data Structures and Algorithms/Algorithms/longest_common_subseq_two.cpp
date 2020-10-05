//goal to find longest common subsequence of given two sequence
//n,m are the length of two sequence
#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n;
  long long a[n],i,j;
  for(i=0;i<n;i++)
    cin>>a[i];
  cin>>m;
  long long b[m];
  for(i=0;i<m;i++)
    cin>>b[i];
  long long c[n+1][m+1];
  for(i=0;i<=n;i++) {
    for(j=0;j<=m;j++) {
      if(i==0||j==0)
        c[i][j]=0;
      else if(a[i-1]==b[j-1])
        c[i][j]=c[i-1][j-1]+1;
      else
        c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
  }
  cout<<c[n][m];
  return 0;
}
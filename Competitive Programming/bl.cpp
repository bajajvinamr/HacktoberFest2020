#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n; cin>>n;
    if(n%2!=0 && n!=1 && n!=2 ){
     long long int a= (pow(n,2)-1)/2;
    cout<<a<<" "<<(a+1);}
    else if(n!=1 && n!=2){
    long long int z=(pow(n,2)/2)-1;
    cout<<(z-1)/2<<" "<<(z-1)/2+2;}
    else
    cout<<-1;
}


#include <iostream>
using namespace std;
int main()
{
  cout<<"enter n"<<endl;
  int n;
  cin>>n;
  int f=1;
  if(n==0)
  cout<<" ";
  else  
  for(int i=1;i<=n;i++)
  {
      f=f*i;
  }
    cout<<f;  
      
  
}

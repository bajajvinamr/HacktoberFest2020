#include "iostream"
using namespace std;

int main(){

int menu,n,i,j,k,a;
char repeat='y';
while(repeat=='y'){
cout<<"this program will create a triangular pattern with n as it's height"<<endl;
cout<<"1.pascal\n"<<"2.odd\n"<<"3.even\n"<<"choose the pattern: ";cin>>menu;

switch(int(menu)){
case 1: {
cout<<"give n: ";cin>>n;
for (i=0;i<n;++i){
    for (k=n;k>=i;--k){
        cout<<" ";
        }
    for (j=0;j<=i;++j){
        if(j==0){
        a=1;
    }
        else{
            a=a*(i+1-j)/j;
        }
        cout<<" ";
        cout<<a;
        cout<<"";
        }
        cout<<endl;
}
break;
}
case 2:{
cout<<"give n: ";cin>>n;
for(i=1;i<=n;++i){
 for(k=n;k>=i;--k){
        cout<<" ";
        }
        for (j=1;j<=i+(i-1);++j){
         cout<<"^";
        }
        cout<<endl;
}
break;
}
case 3:{
cout<<"give n: ";cin>>n;
for(i=1;i<=n;++i){
 for(k=n;k>=i;--k){
        cout<<" ";
        }
        for (j=1;j<=i+i;++j){
         cout<<"^";
        }
        cout<<endl;
}
break;
}
}
cout<<"do you want to repeat?(y/n): ";cin>>repeat;
}
}

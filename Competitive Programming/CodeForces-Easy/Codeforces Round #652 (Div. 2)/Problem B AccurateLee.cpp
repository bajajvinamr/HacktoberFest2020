#include <bits/stdc++.h>
# define ll long long int
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x=0;
        while(x!=-1){
            x=-1;
            for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1' && s[i+1]=='0'){
                x=i;
                break;
            }
        }
        if(x==-1)
        break;
        else{
            int z=-1;
            for(int i=x+2;i<s.size()-1;i++){
                if(s[i]=='1' && s[i+1]=='0'){
                    z=i;
                    break;
                }
            }
            if(z==-1){
               while(s[x+2]=='0'){
                s.erase(x+2,1);
            }
            int y=0;
            for(int i=x-1;i>=0;i--){
                if(s[i]=='1')
                y++;
                else break;
            }
            s.erase(x-y,y+1); 
            }
            else {
                while(s[x+2]=='0'){
                s.erase(x+2,1);
            }
            s.erase(x+1,1);
            int y=0;
            for(int i=x-1;i>=0;i--){
                if(s[i]=='1')
                y++;
                else break;
            }
            s.erase(x-y,y);
            }
            
        }
        }
    cout<<s<<"\n";    
    }
	return 0;
}
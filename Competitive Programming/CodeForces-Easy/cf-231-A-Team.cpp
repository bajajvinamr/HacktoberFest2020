#include <bits/stdc++.h>
using namespace std;
int main() {
    int quant; cin >> quant;
    int ans=0,re,k=0;
    while(quant--){
        for(int i = 0;i<3;i++){
            cin >> re;
            k+=re;
        }
        if(k>=2) ans+=1;
        k=0;

    }
    cout << ans << endl;
}

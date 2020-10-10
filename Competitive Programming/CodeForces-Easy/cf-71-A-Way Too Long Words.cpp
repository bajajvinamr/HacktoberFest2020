#include <bits/stdc++.h>
using namespace std;
int main() {
    int quant; cin >> quant;
    while(quant--){
        string p; cin >> p;
        if(p.size()>10) cout << p[0] << p.size()-2 << p[p.size()-1] << endl;
        else cout << p << endl;
    }
}

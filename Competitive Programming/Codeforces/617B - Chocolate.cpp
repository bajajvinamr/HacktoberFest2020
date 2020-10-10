#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int prev = -1;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (v == 1) {
            if (prev == -1) {
                result = 1;
            } else {
                result *= i - prev;
            }
            prev = i;
        }
    }
 
    cout << result << endl;
}
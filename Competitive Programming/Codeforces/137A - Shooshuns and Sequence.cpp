/*
Problem Statement: 

One day shooshuns found a sequence of n integers, written on a blackboard. The shooshuns can perform one operation with it, the operation consists of two steps:

Find the number that goes k-th in the current sequence and add the same number to the end of the sequence;
Delete the first number of the current sequence.
The shooshuns wonder after how many operations all numbers on the board will be the same and whether all numbers will ever be the same.
*/

/* Solution: */

/*
https://codeforces.com/problemset/problem/222/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pii pair<int, int>

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int val = v[m-1];
    for(int i = m; i < n; i++) {
        if(v[i] != val) {
            cout << -1 << endl;
            return 0;
        }
    }

    int i = m-2;
    while(i >= 0 && (v[i] == v[i+1]))
        i--;
    
    cout << i+1 << endl;
    return 0;
}
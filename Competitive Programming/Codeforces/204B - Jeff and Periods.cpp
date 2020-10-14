/*
Problem Statement: 

One day Jeff got hold of an integer sequence a1, a2, ..., an of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:

x occurs in sequence a.
Consider all positions of numbers x in the sequence a (such i, that ai = x). These numbers, sorted in the increasing order, must form an arithmetic progression.
Help Jeff, find all x that meet the problem conditions.

*/

/* Solution: */

/*
https://codeforces.com/problemset/problem/352/B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pii pair<int, int>

vector<vector<int>> v(100005);

int main() {
    int n, val, maxval = -1, diff;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> val;
        v[val].push_back(i);
        maxval = max(maxval, val);
    }

    vector<pii> ans;
    for(int i = 1; i <= maxval; i++) {
        if(v[i].size() > 0) {
            if(v[i].size() == 1) {
                ans.push_back({i, 0});
            } else {
                diff = v[i][1]-v[i][0];
                int j;
                for(j = 2; j < v[i].size(); j++) {
                    if(v[i][j]-v[i][j-1] != diff) {
                        break;
                    }
                }

                if(j == v[i].size())
                    ans.push_back({i, diff});
            }
        }
    }

    cout << ans.size() << endl;
    for(auto& a: ans) {
        cout << a.ff << " " << a.ss << endl;
    }

    return 0;
}
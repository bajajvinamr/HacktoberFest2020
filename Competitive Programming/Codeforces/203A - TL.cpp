/*
Problem Statement: 

Valera wanted to prepare a Codesecrof round. He's already got one problem and he wants to set a time limit (TL) on it.

Valera has written n correct solutions. For each correct solution, he knows its running time (in seconds). Valera has also wrote m wrong solutions and for each wrong solution he knows its running time (in seconds).

Let's suppose that Valera will set v seconds TL in the problem. Then we can say that a solution passes the system testing if its running time is at most v seconds. We can also say that a solution passes the system testing with some "extra" time if for its running time, a seconds, an inequality 2a ≤ v holds.

As a result, Valera decided to set v seconds TL, that the following conditions are met:

v is a positive integer;
all correct solutions pass the system testing;
at least one correct solution passes the system testing with some "extra" time;
all wrong solutions do not pass the system testing;
value v is minimum among all TLs, for which points 1, 2, 3, 4 hold.
Help Valera and find the most suitable TL or else state that such TL doesn't exist.
*/

/* Solution: */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int val, firstmin = INT_MAX, firstmax = INT_MIN, secondmin = INT_MAX;

    for(int i = 0; i < n; i++) {
        cin >> val;
        if(val < firstmin)
            firstmin = val;

        if(val > firstmax)
            firstmax = val;
    }

    for(int i = 0; i < m; i++) {
        cin >> val;
        if(val < secondmin)
            secondmin = val;
    }

    int temp = max(2*firstmin, firstmax);
    if(temp < secondmin) {
        cout << temp << endl;
    } else cout << -1 << endl;
}
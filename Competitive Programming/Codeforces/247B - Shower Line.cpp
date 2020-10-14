/*
Problem statement: 

Many students live in a dormitory. A dormitory is a whole new world of funny amusements and possibilities but it does have its drawbacks.

There is only one shower and there are multiple students who wish to have a shower in the morning. 
That's why every morning there is a line of five people in front of the dormitory shower door. As soon as the shower opens, the first person from the line enters the shower. After a while the first person leaves the shower and the next person enters the shower. 
The process continues until everybody in the line has a shower.

Having a shower takes some time, so the students in the line talk as they wait. 
At each moment of time the students talk in pairs: the (2i - 1)-th man in the line (for the current moment) talks with the (2i)-th one.

Let's look at this process in more detail. Let's number the people from 1 to 5. 
Let's assume that the line initially looks as 23154 (person number 2 stands at the beginning of the line). 
Then, before the shower opens, 2 talks with 3, 1 talks with 5, 4 doesn't talk with anyone. 
Then 2 enters the shower. While 2 has a shower, 3 and 1 talk, 5 and 4 talk too. Then, 3 enters the shower. 
While 3 has a shower, 1 and 5 talk, 4 doesn't talk to anyone. Then 1 enters the shower and while he is there, 5 and 4 talk. 
Then 5 enters the shower, and then 4 enters the shower.

We know that if students i and j talk, then the i-th student's happiness increases by gij and the j-th student's happiness increases by gji. 
Your task is to find such initial order of students in the line that the total happiness of all students will be maximum in the end. 
Please note that some pair of students may have a talk several times. 
In the example above students 1 and 5 talk while they wait for the shower to open and while 3 has a shower.

*/

/* Solution: */

/*
https://codeforces.com/problemset/problem/431/B
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
vector<vector<int>> v(5, vector<int>(5));

int get(int a, int b, int c, int d, int e) {
    return 
    (v[a][b] + v[b][a] + v[c][d] + v[d][c]) 
    + (v[b][c] + v[c][b] + v[d][e] + v[e][d]) 
    + (v[c][d] + v[d][c]) 
    + (v[e][d] + v[d][e]);
}

int main() {

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> v[i][j];

    vector<int> vv = {0, 1, 2, 3, 4};
    int maxans = get(vv[0], vv[1], vv[2], vv[3], vv[4]);

    while(next_permutation(vv.begin(), vv.end())) {
        maxans = max(maxans, get(vv[0], vv[1], vv[2], vv[3], vv[4]));
    }

    cout << maxans << endl;

    return 0;
}
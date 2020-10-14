/*
Problem Statement: 

A string is called a k-string if it can be represented as k concatenated copies of some string. 
For example, the string "aabaabaabaab" is at the same time a 1-string, a 2-string and a 4-string, but it is not a 3-string, a 5-string, or a 6-string and so on. Obviously any string is a 1-string.

You are given a string s, consisting of lowercase English letters and a positive integer k. 
Your task is to reorder the letters in the string s in such a way that the resulting string is a k-string.

*/

/* Solution: */

/*
https://codeforces.com/problemset/problem/219/A
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int k;
    string s, temp;
    cin >> k;
    cin >> s;

    int count[26] = {0};

    for(auto& c: s) 
        count[c-'a']++;

    for(int i = 0; i < 26; i++) {
        if(count[i] != 0) {
            if(count[i]%k != 0)
            {
                cout << -1 << endl;
                return 0;
            } 
            char c = 'a'+i;
            for(int  j = 0; j < count[i]/k; j++) {
                temp.push_back(c);
            }
        }
    }

    for(int i = 0; i < k; i++)
        cout << temp;
    cout << '\n';

    return 0;
}
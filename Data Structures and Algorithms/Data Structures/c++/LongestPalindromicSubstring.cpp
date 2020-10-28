/*
 Algorithm for getting Longest Palindromic substring of a string. 
 Time Complexity: O(n*n)
 Space Complexity: O(1)

 -------------------------------------
 This author of this piece of code is Mudassar Raza(https://github.com/mraza1312/)
 Suggestions are welcome.
*/

#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int i, j, len=0, maxlen=1, n=s.length();
    int beg=0, end=0;
    if(n<=1) return s;
    for(int k=0;k<n;k++){
    i=k-1; j=k+1; len=1;
    while(i>=0 && j<n && s[i]==s[j]) { len+=2; i--; j++;}
    if(len>maxlen) { maxlen=len; beg=i+1; end=j-1;}
    i=k; j=k+1; len=0;
    while(i>=0 && j<n && s[i]==s[j])  { len+=2; i--; j++; }
    if(len>maxlen) { maxlen=len; beg=i+1; end=j-1;}
    }   
    return s.substr(beg,maxlen);
}

int main() {
    string s; 
    cin>>s;
    string longestPalindromeSub = longestPalindrome(s);
    cout<<"The longestPalindromic Substring of "<<s<<" is: - "<<longestPalindromeSub;
    return 0;
}


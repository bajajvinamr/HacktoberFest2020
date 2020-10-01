/*this program is used to reverse the words in a string*/
#include<bits/stdc++.h>
using namespace std;
void reverseWords(string &s){
  int st=0;
  for(int en=0;en<s.length();en++){
    if (s[en] == ' ') {
            reverse(s.begin() + st, s.begin() + en);
            st = en + 1;
        }
  }
  reverse(s.begin() + st, s.end());
  reverse(s.begin(), s.end());
}
int main(){
  string s = "I want to program";
  reverseWords(s);
  cout<<"words reversed in string are"<<endl;
  cout<<s;
  return 0;
}
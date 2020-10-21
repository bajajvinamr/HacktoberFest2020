#include <cctype>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    char ch1[200],ch2[200];
    cin>>ch1>>ch2;
    int n = strlen(ch1);
    /*for(int i = 0; ch1[i] != '\0'; i++){
        n++;
    }*/
    for(int i = 0; i < n; i++){
        if(ch1[i] != ch2[n-i-1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}

#include <cctype>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int l = 0, u = 0;
    string ch;
    cin>>ch;
    for(int i = 0; ch[i] != '\0'; i++){
        if(islower(ch[i])){
            l++;
        }
        else{
            u++;
        }
    }
    if(u > l){
        for(int i = 0; ch[i] != '\0'; i++){
            ch[i] = (toupper(ch[i]));
        }
    }
    else{
        for(int i = 0; ch[i] != '\0'; i++){
            ch[i] = (tolower(ch[i]));
        }
    }
    cout<<ch;
    return 0;
}

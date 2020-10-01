#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n,c;
	cin >> n >>c;
	vector<int>v(n+1);
	int count=0;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		v[i]=t;
	}
	for(int i=0;i<n-1;i++)
        {
          if(v[i+1]-v[i]>c)
             count=0;
          else
             count++;
        }

	cout << count+1;
	return 0;
}

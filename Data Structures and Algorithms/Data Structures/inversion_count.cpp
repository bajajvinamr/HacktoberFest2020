#include<iostream>
using namespace std;

int merg(int a[], int s, int e){
	int mid = (s+e)/2;
	int temp[1000];
	int cnt = 0;
	int i = s; int j = mid+1; int k = s;

	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}
	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=e){
		temp[k++] = a[j++];
	}

	for(int i=0; i<=e; i++)
		a[i] = temp[i];

	return cnt;
}

int inversionSort(int a[], int s, int e){
	if(s>=e)
		return 0;
	int mid = (s+e)/2;
	int x = inversionSort(a,s,mid);
	int y = inversionSort(a,mid+1,e);
	int z = merg(a,s,e);
	return x+y+z;
}

int main(){
	int n;
	int a[1000];
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	// no. of cross invertions are ....
	cout<<"No. of Inversions it will take ";
	cout<< inversionSort(a,0,n-1);
	cout<<endl;
	 for(int i=0; i<n; i++)
	 	cout<<a[i]<< " ";
return 0;
}
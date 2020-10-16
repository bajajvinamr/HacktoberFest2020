#include<bits/stdc++.h>
using namespace std;


int part(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for(int j=low; j<=high-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return (i+1);
}

int partRandom(int arr[], int low, int high){
	srand(time(NULL));
	int random = low + (rand() % (high-low));
	swap(arr[random], arr[high]);

	return part(arr, low, high);
}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int pi = partRandom(arr, low, high);
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
	}

void print(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
  int n;
  cin >> n;
	int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
	quicksort(arr, 0, n-1);
	cout << "Sorted array is: " << endl;
	print(arr, n);
	return 0;
}

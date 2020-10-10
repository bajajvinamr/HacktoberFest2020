#include<stdio.h>
#define MAX 30

int BinarySearch(int bin[],int l, int h, int key) {
	int mid = (l+h)/2;
	if(bin[mid] == key) {
		return mid;
	}
	if(bin[mid] > key) {
		h = mid -1;
		return BinarySearch(bin, l, h, key);
	}
	else if(bin[mid] < key) {
		l = mid+1;
		return BinarySearch(bin, l , h, key);
	}
}

int main () {
	int bin[MAX];
	int n;
	printf("Enter the size of sorted array:\n");
	scanf("%d", &n);
	printf("Now enter the contents of sorted array:\n");
	for(int i = 0;i < n; i++) {
		scanf("%d",&bin[i]);
	}
	int key;
	printf("Enter the key you want to search:\n");
	scanf("%d", &key);
	int index = BinarySearch(bin, 0, (n-1), key);
	printf("Index of %d is %d\n", key, index);
	return 0;
}

// Bubble Sorting Algorithm

#include <iostream>
using namespace std;
void print(float[], int);
void sort(float[],int);
void swap (float& , float& );
int main()
{
    // Define an array of values to be sorted
    float a[] = {55.5, 22.5, 99.9,66.6, 44.4, 88.8, 33.3, 77.7};
    print(a,8);
    sort(a,8);
    cout << "\n";
    print(a,8);
}
void sort(float a[], int n){
     for(int i = 1; i < n ; i++)
      for(int j = 0; j < n-1 ; j++)
        if (a[j] > a[j+1]) swap(a[j],a[j+1]);
}
void print(float a[], int n){
    for(int i = 0; i < n ; i++)
    cout << a[i] << " ";
}
void swap (float& x, float& y)
{
    // exchanges values between x and y
    float temp = x;
    x = y;
    y = temp;
}
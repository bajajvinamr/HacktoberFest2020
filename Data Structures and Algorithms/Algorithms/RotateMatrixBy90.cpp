//In place rotation of a mtrix by 90 degrees anticlockwise
#include <bits/stdc++.h> 
using namespace std; 
#define R 4 
#define C 4 
void reverseColumns(int arr[R][C]) 
{ 
    for (int i = 0; i < C; i++) 
        for (int j = 0, k = C - 1; 
             j < k; j++, k--) 
            swap(arr[j][i], arr[k][i]); 
} 
void transpose(int arr[R][C]) 
{ 
    for (int i = 0; i < R; i++) 
        for (int j = i; j < C; j++) 
            swap(arr[i][j], arr[j][i]); 
} 

void printMatrix(int arr[R][C]) 
{ 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) 
            cout << arr[i][j] << " "; 
        cout << '\n'; 
    } 
} 

void rotate90(int arr[R][C]) 
{ 
    transpose(arr); 
    reverseColumns(arr); 
} 

int main() 
{ 
    int arr[R][C] = { { 1, 2, 3 }, 
                      { 4, 5, 6 }, 
                      { 7, 8, 9 } }; 
    rotate90(arr); 
    printMatrix(arr); 
    return 0; 
} 

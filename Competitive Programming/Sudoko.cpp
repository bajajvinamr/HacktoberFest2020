#include<bits/stdc++.h>
using namespace std;
#define n 9

bool isSafeInRow(int grid[n][n], int row, int num) {
	for(int i = 0; i < n; i++) {
		if(grid[row][i] == num) {
			return false;
		}
	}
	return true;
}
bool isSafeInColumn(int grid[n][n], int col, int num) {
	for(int i = 0; i < n; i++) {
		if(grid[i][col] == num) {
			return false;
		}
	}
	return true;
}
bool isSafeInGrid(int grid[n][n], int row, int col, int num) {
	
	int rowFactor = row - ( row % 3);
	int colFactor = col - ( col % 3);
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(grid[i + rowFactor][j + colFactor] == num) {
				return false;
			}
		}
	}
	
	return true;
	
}
bool isSafe(int grid[n][n], int row, int col, int num) {
	
	if((isSafeInRow(grid, row, num) && isSafeInColumn(grid, col, num)) && isSafeInGrid(grid, row, col, num)) {
		return true;
	}
	return false;
}
bool findEmptyLocation(int grid[n][n], int& row, int& col) {
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == 0){
				row =i;
				col = j;
				return true;
			}
		}
	}
	return false;
}
bool solveSudoko(int grid[n][n]) {
	
	int row, col;
	if(!findEmptyLocation(grid, row, col)) {
		return true;
	}
	
	for(int i = 1; i <= n; i++) {
		if(isSafe(grid, row, col, i)) {
			grid[row][col] = i;
			if(solveSudoko(grid)) {
				return true;
			}
			grid[row][col] = 0;	
		}
	}
	return false;
}

int main() {
	
	int grid[n][n];
	// take input as a string
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			string s;
			cin >> s;
			for(int j = 0; j < s.length(); j++) {
				grid[i][j] = s[j] - '0';
			}
		}
	}
	solveSudoko(grid);
	
	// print the grid
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

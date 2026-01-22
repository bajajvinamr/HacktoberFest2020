package Arrays;
//Write a program to initialize an integer array with values and check if a given number is present in the array or not. If the number is not found, 
//it will print -1 else it will print the index value of the given  number in the array


import java.util.*;

public class A3 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		System.out.println("Size of Array: ");
		int n = input.nextInt();
		System.out.println("Enter Element to Find: ");
		int k = input.nextInt();
		int pos = -1;
		int[] arr = new int[n];
		System.out.println("Enter Array: ");
		for(int i =0;i<n;i++) {
			arr[i] = input.nextInt();
			if(k==arr[i]) {
				pos = i;
			}	
		}
		System.out.println(pos);
	}
}

package Arrays;
// Write a program to initialize an integer array and find the maximum and minimum value of an array


import java.util.*;

public class A2 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		System.out.println("Size of Array: ");
		int n = input.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter Array: ");
		arr[0] = input.nextInt();
		int max = arr[0];
		int min = arr[0];
		
		for(int i =1;i<n;i++) {
			arr[i] = input.nextInt();
			if(arr[i]>max) {
				max = arr[i];
			}
			if(arr[i]<min) {
				min = arr[i];
			}
		}
		System.out.println("Max: "+max);

		System.out.println("Min: "+min);
	}
}
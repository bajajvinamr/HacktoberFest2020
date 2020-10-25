package Arrays;
// Write a program to find the largest 2 numbers and the smallest 2 numbers in the given array

import java.io.*;
import java.util.*;

public class A5 {
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter array with seperated space: ");
		String[] strr = br.readLine().split(" ");
		int[] arr = new int[strr.length];
		for(int i =0;i<strr.length;i++) {
			arr[i] = Integer.parseInt(strr[i]);
		}
		Arrays.sort(arr);
		System.out.print("Largest number 1: ");
		System.out.println(arr[(arr.length)-1]);

		System.out.print("Largest number 2: ");
		System.out.println(arr[(arr.length)-2]);

		System.out.print("Smallest number 1: ");
		System.out.println(arr[0]);

		System.out.print("Smallest number 1: ");
		System.out.println(arr[1]);
	}
}

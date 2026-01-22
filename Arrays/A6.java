package Arrays;
// Write a program to initialize an array and print them in a sorted fashion


import java.io.*;
import java.util.*;

public class A6 {
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter array with seperated space: ");
		String[] strr = br.readLine().split(" ");
		int[] arr = new int[strr.length];
		for(int i =0;i<strr.length;i++) {
			arr[i] = Integer.parseInt(strr[i]);
		}
		Arrays.sort(arr);
		StringBuffer sb = new StringBuffer();
		for(int j =0;j<arr.length;j++) {
			sb.append(arr[j]+" ");
		}
		System.out.println(sb);
		
		
		
	}
}

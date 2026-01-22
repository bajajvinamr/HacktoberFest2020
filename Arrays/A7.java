package Arrays;
//Write a program to remove the duplicate elements in an array and print

import java.io.*;
import java.util.*;

public class A7 {
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
		for(int j =0;j<arr.length-1;j++) {
			if(arr[j]!=arr[j+1]) {
				sb.append(arr[j]+" ");
			}
		}
		sb.append(arr[arr.length -1]);
		System.out.println(sb);
		
		
		
	}
}

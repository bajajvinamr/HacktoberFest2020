package Arrays;
//Write a program to print the element of an array that has occurred the highest number of times

import java.io.*;
import java.util.*;

public class A8 {
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter array with seperated space: ");
		String[] strr = br.readLine().split(" ");
		int[] arr = new int[strr.length];
		for(int i =0;i<strr.length;i++) {
			arr[i] = Integer.parseInt(strr[i]);
		}
		int start = 0;
		int end = 0;
		boolean flag = false;
		for(int i =0; i<arr.length-1;i++) {
			if(arr[i]==6) {
				start = i;
				for(int j = start+1;j<arr.length;j++) {
					if(arr[j]==7) {
						end = j;
						flag = true;
						break;
					}
				}
				break;
			}
		}
			int summ = 0;
			if(flag) {
				for(int p=0;p<start;p++) {
					summ+=arr[p];
				}
				for(int k=end+1;k<arr.length;k++) {
					summ+=arr[k];
				}
			}
			else {
				for(int l=0;l<arr.length;l++) {
					summ+=arr[l];
				}
			}
			System.out.println(summ);			
	}
}
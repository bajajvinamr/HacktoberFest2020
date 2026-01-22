package Arrays;
//Write a program to reverse the elements of a given 2*2 array. Four integer numbers needs to be passed as Command Line arguments.
import java.io.*;
import java.util.*;

public class A10 {
	public static void main(String args[])throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter array with seperated space: ");
		String[] strr = br.readLine().split(" ");
		if(strr.length==9){
			int count = 0;
			int maxx =0;
			int[][] arr = new int[3][3];
			for(int i =0;i<3;i++) {
				for(int j=0;j<3;j++) {
					arr[i][j]= Integer.parseInt(strr[count++]);
					if(arr[i][j]>maxx) {
						maxx = arr[i][j];
					}
				}
			}
			System.out.println("The given array is: ");
			for(int k =0;k<3;k++) {
				for(int l=0;l<3;l++) {
					System.out.print(arr[k][l]+" ");
				}
				System.out.println();
			}
			System.out.println("The biggest number in the given array is: "+maxx);
			
		}
		else {
			System.out.println("Please enter 9 integer nmumber");
		}
		
	}}
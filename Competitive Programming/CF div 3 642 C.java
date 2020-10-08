import java.math.BigInteger; 
import java.util.*;
import java.lang.*;
import java.io.*;
public class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		BigInteger a[]=new BigInteger[250000];
		a[0]=BigInteger.ZERO;
		for(int i=1;i<250000;i++){
		    a[i]=a[i-1].add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(i).multiply(BigInteger.valueOf(8))));
		}
		while(t-->0)
		{
		    int n=sc.nextInt();
            n=(n-1)/2;		  
            System.out.println(a[n]);
		}
		
	}
}

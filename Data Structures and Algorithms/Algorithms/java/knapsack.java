// This is a very famous problem which can be solved efficiently using greedy technique.

import java.util.*;
import java.lang.*;
class knapsack
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size");
		int n=sc.nextInt();
		int p[]=new int[n];
		int w[]=new int[n];
		System.out.println("Enter the profit");
		for(int i=0;i<n;i++)
		{
			p[i]=sc.nextInt();
		}
		System.out.println("Enter the weights");
		for(int i=0;i<n;i++)
		{
			w[i]=sc.nextInt();
		}
		System.out.println("Enter the max.weight");
		int h=sc.nextInt();
		double a[]=new double[n];
		for(int i=0;i<n;i++)
		{
			a[i]=p[i]/w[i];
		}
		
		for(int i=0;i<n-1;i++)
		{
			int max=i;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]>a[max])
				{
					max=j;
				}
			}
			double temp1=a[i];
			int temp2=w[i];
			int temp3=p[i];
			a[i]=a[max];
			w[i]=w[max];
			p[i]=p[max];
			a[max]=temp1;
			w[max]=temp2;
			p[max]=temp3;
		}
		double x[]=new double[n];
		double weight=0;
		for(int i=0;i<n;i++)
		{
			if(weight+w[i]<=h)
			{
				x[i]=1;
				weight=weight+w[i];

			}
			else
			{
				x[i]=(h-weight)/w[i];
				weight=h;
				break;
			}
			
		}
		double count=0;
		for(int i=0;i<n;i++)
		{
			count=count+p[i]*x[i];
		
		}
		System.out.println("max profit = "+ count);

		


	}
}
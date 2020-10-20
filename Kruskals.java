import java.util.*;
public class Kruskals
{
	static Scanner sc = new Scanner(System.in);
	static int[] a;
	static int[] store = new int[3];
	static int[][] a1,a2;
	public static void main(String[] args){
		int count=0;
		System.out.println("enter number of nodes");
        int n=sc.nextInt();
        a = new int[n+1];
        a1 = new int[n+1][n+1];
        a2 = new int[n+1][n+1];
        System.out.println("enter the matrix of "+n+" x "+n);
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=n;j++)
        	{
        		a1[i][j] = sc.nextInt();
        		a2[i][j] = 999;
        	}
        }
        while(count<n-1)
        {
        	store = findmin(n);
            a2[store[0]][store[1]] = store[2];
            a2[store[1]][store[0]] = store[2];
            count++;
        }
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=n;j++)
        	{
        		System.out.print(a2[i][j]+" ");
        	}
        	System.out.println("");
        }

	}
	public static int[] findmin(int n)
	{
       int[] store = new int[3];
       int x=0,y=0;
       store[0]=1;
       store[1]=1;
       store[2]=999;
       for(int i=1;i<=n;i++)
       {
       	for(int j=i;j<=n;j++)
       	{
       		int[] flag = findCycle(i,j);
       		if(a1[i][j]<store[2]&&!(flag[0]==1))
       		{
       			x=flag[1];
       			y=flag[2];
       			System.out.println(i+"    "+j);
       			store[2]=a1[i][j];
       			store[0]=i;
       			store[1]=j;
       		}
       	}
       }
       if(x>y)
       	a[y]=x;
       else
       	a[x]=y;
       a1[store[0]][store[1]]=999;
       return store;
	}
	public static int[] findCycle(int i ,int j)
	{
		int l=i,k=j;
		int[] store = new int[3];
		store[0]=1;store[1]=store[2]=0;
		int[] store1 = new int[3];
		store1[0]=0;
		if(i==j)
		{
			return store;
		}
         while(a[i]!=0)
         {
            l=i;
            i=a[l];
            l=i;
         }
         while(a[j]!=0)
         {
         	k=j;
         	j=a[k];
         	k=j;
         }
         store1[1]=k;
         store1[2]=l;
         if(a[k]==l)
         	return store;
         else
         {
         

         	return store1;
         }
	}
}
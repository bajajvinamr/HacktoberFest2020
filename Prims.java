import java.util.*;
public class Prims
{
	static ArrayList<Integer> visited=new ArrayList<>();
	static int[][] a;
	static int[][] b;
	static int n;
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.println("Enter number of nodes");
		int x=1,y=1;
		n = sc.nextInt();
		a= new int[n+1][n+1];
		b= new int[n+1][n+1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j] = sc.nextInt();
				b[i][j] = 999;
			}
		}
		visited.add(1);
		while(visited.size()<n)
		{
			int min = 999;
			for(int i=0;i<visited.size();i++)
			{
				int[] store = minimum(visited.get(i));
				if(store[0]<min)
				{
					min=store[0];
                    x=visited.get(i);
                    y=store[1];
				}
			}
			visited.add(y);
			b[x][y]=min;
			b[y][x]=min;
		}
		for(int k=1;k<=n;k++)
		{
			for(int l=1;l<=n;l++)
			{
				System.out.print(b[k][l]+"  ");
			}
			System.out.println("");
		}
	}
	public static int[] minimum(int node)
	{
		int min = 999;
		int[] store=new int[2];
		store[0]=min;
		for(int i=1;i<=n;i++)
		{
			if(a[node][i]<min&&!visited.contains(i))
			{
				min=a[node][i];
                store[0] = min;
                store[1] = i;
			}
		}
		return store;

	}
}
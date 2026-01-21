/*

	Title	:	To implement graph data structure using adjacency list and matrix and perform traversals on it.
	
*/


import java.util.*;

class node
{
	int data;
	node next;
	
	node(int d)
	{
		data=d;
	}
}

class graph
{
	node head[];
	int AdjMat[][];
	int n;
	int e;
	
	

	void createMat()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the no. of vertices: ");
		n=sc.nextInt();
		
		AdjMat=new int[n][n];
		
		
		int arr[]=new int[n];
		int data;
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter data for vertex: ");
			data=sc.nextInt();
			arr[i]=data;
			
		}
		
		System.out.println("Enter number of edges: ");
		e=sc.nextInt();
		
		for(int i=0;i<e;i++)
		{
			System.out.println("Enter two vertices to insert edge: ");
			int x=sc.nextInt();
			int y=sc.nextInt();
			int u=-1,v=-1;
			
			for(int k=0;k<n;k++)
			{
				if(x==arr[k])
				{
					u=k;
					break;
				}
				
			}
			for(int k=0;k<n;k++)
			{
			
				if(y==arr[k])
				{
					v=k;
					break;
				}
			}
			
			if((u==-1)||(v==-1))
			{
				System.out.println("Vertices not found! ");
				return;
			}
			
			insert(u,v);
			
		}
	

	
		System.out.println("\nAdjacency Matrix: \n");
	
	
		System.out.print("\t");
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+"\t");
		}
		System.out.println("\n____________________________________");
	
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+"\t|");
			for(int j=0;j<n;j++)
			{
				System.out.print(AdjMat[i][j]+"\t");
			}
			
			System.out.println();
		}
	
	
	
		BFS(arr);	
		
	}
	
	void insert(int u,int v)	
	{
		AdjMat[u][v]=1;	
		AdjMat[v][u]=1;	
	}


	void BFS(int arr[])
	{
		Queue<Integer> q=new LinkedList<Integer>();	
		Scanner sc= new Scanner(System.in);
		
		System.out.println("\nEnter the starting vertex: ");
		int s=sc.nextInt();
		int sidx=-1;
		
		int newarr[]=new int[n];
		
		for(int i=0;i<n;i++)
		{
			newarr[i]=arr[i];	
		}
		
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]==s)
			{
				sidx=i;
				break;
			}
		}
		
		if(sidx==-1)
		{
			System.out.println("Vertex not found!");
			return;
		}	
		
		newarr[sidx]=0;
		q.add(sidx);
		
		
		System.out.println("\nBFS result:");
		System.out.println("__________\n");
		
		while(!q.isEmpty())
		{
			int temp=q.remove();	
			System.out.print(arr[temp]+" ");
			
			for(int j=0;j<n;j++)
			{
				if((AdjMat[temp][j]==1)) //&& (AdjMat[j][temp]==1))
				{
					if(newarr[j]!=0)
					{
						newarr[j]=0;
						q.add(j);
					}
				}
			}
		
		
		}
		System.out.println("\n\n");
		
	}	

	void createList()
	{
		Scanner sc=new Scanner(System.in);
		int data;
		node temp;
	
		System.out.println("Enter the number of vertices: ");
		n=sc.nextInt();
		
		head=new node[n];

		for(int i=0;i<n;i++)
		{
			System.out.print("Enter data for vertex: ");
			data=sc.nextInt();
			
			temp=new node(data);	
			head[i]=temp;
			
		}
	

		System.out.println("Enter number of edges: ");
		e=sc.nextInt();
		
		for(int i=0;i<e;i++)
		{
			System.out.println("Enter two vertices to insert edge: ");
			int x=sc.nextInt();
			int y=sc.nextInt();
			int u=-1,v=-1;
			
			for(int k=0;k<n;k++)
			{
				if(x==head[k].data)
				{
					u=k;
					break;
				}
				
			}
			for(int k=0;k<n;k++)
			{
			
				if(y==head[k].data)
				{
					v=k;
					break;
				}
			}
			
			if((u==-1)||(v==-1))
			{
				System.out.println("Vertices not found! ");
				return;
			}
			
		
			node ptr=head[u];
			while(ptr.next!=null)
			{
				ptr=ptr.next;
			}
			temp=new node(head[v].data);
			ptr.next=temp;
		
		
			ptr=head[v];
			while(ptr.next!=null)
			{
				ptr=ptr.next;
			}
			temp=new node(head[u].data);
			ptr.next=temp;	
	
		}
	
	
		System.out.println("\nAdjacency List: \n");	
		for(int j=0;j<n;j++)
		{
			System.out.print(head[j].data+"\t----->   ");
			node ptr=head[j].next;
			while(ptr!=null)
			{
				System.out.print(" | "+ptr.data+" |-->");
				ptr=ptr.next;
			}
			System.out.print("NULL");	
			System.out.println();
		}
	
		DFS();
	}
	
	
	
	
	
	void DFS()
	{
		int Visited[]=new int[n];
		Stack<node> s=new Stack<node>();
		Scanner sc=new Scanner(System.in);
	
		System.out.println("\nEnter the starting vertex: ");
		int st=sc.nextInt();
	
		int stidx=-1;
		for(int k=0;k<n;k++)
		{
			if(st==head[k].data)
			{
				stidx=k;
				break;
			}
	
		}

		if(stidx==-1)
		{
			System.out.println("Vertex not found!");
			return;
		}



		System.out.println("\nDFS result : ");
		System.out.println("__________\n");
	
		Visited[stidx]=1;
		System.out.print(st+" ");
		s.push(head[stidx]);
	
	
		while(!s.isEmpty())
		{
			node v=s.peek();
			int vidx=0;
		
			for(int k=0;k<n;k++)
			{
				if(v.data==head[k].data)
				{
					vidx=k;
					break;
				}
			
			}
		
			int adjidx=0;
			node adj=head[vidx].next;
			while(adj!=null)
			{
			
				for(int k=0;k<n;k++)
				{
					if(adj.data==head[k].data)
					{
						adjidx=k;
						break;
					}
				
				}
		
				if(Visited[adjidx]==1)
				{
					adj=adj.next;
				}
				else
				{
					break;
				}
			}
		
			if(adj==null)
			{
				s.pop();
			}
			else
			{
				Visited[adjidx]=1;
				System.out.print(adj.data+" ");
				s.push(adj);
			}
		}
	
		System.out.println("\n\n");

	}
	
	
	
}

class Graph_Main
{
	public static void main(String args[])
	{
		graph g=new graph();
		
		Scanner sc=new Scanner(System.in);
		int ch;
		
		do
		{	
			System.out.println("------------");
			System.out.println("----MENU----");
			System.out.println("1.BFS");
			System.out.println("2.DFS");
			System.out.println("------------");
			System.out.println();
			
			System.out.println("Enter your choice: ");
			ch=sc.nextInt();
		
			switch(ch)
			{
				case 1:
						g.createMat();	
						break;
			
				case 2:	
						g.createList();	
						break;	
			}
			
		
		}while(ch>0&&ch<3);	
		
	}
}



/*

OUTPUT:


------------
----MENU----
1.BFS
2.DFS
------------

Enter your choice:
1
Enter the no. of vertices:
4
Enter data for vertex: 21
Enter data for vertex: 3
Enter data for vertex: 24
Enter data for vertex: 1
Enter number of edges:
4
Enter two vertices to insert edge:
21
3
Enter two vertices to insert edge:
21
1
Enter two vertices to insert edge:
24
1
Enter two vertices to insert edge:
21
24

Adjacency Matrix:

        21      3       24      1
____________________________________
21      |0      1       1       1
3       |1      0       0       0
24      |1      0       0       1
1       |1      0       1       0

Enter the starting vertex:
3

BFS result:
__________

3 21 24 1


------------
----MENU----
1.BFS
2.DFS
------------

Enter your choice:
2
Enter the number of vertices:
4
Enter data for vertex: 21
Enter data for vertex: 3
Enter data for vertex: 24
Enter data for vertex: 1
Enter number of edges:
4
Enter two vertices to insert edge:
21
3
Enter two vertices to insert edge:
21
1
Enter two vertices to insert edge:
24
1
Enter two vertices to insert edge:
21
24

Adjacency List:

21      ----->    | 3 |--> | 1 |--> | 24 |-->NULL
3       ----->    | 21 |-->NULL
24      ----->    | 1 |--> | 21 |-->NULL
1       ----->    | 21 |--> | 24 |-->NULL

Enter the starting vertex:
3

DFS result :
__________

3 21 1 24



*/

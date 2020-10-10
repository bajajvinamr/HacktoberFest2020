#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int adjMatrix[5][5];
    int parent[5];
    int Min;
    int u,v;
    int nEdges=1;
    int Cost=0;
    int i=0,j=0;

    cout<<"Enter a graph with 5 nodes:\n";
    for(int i=0;i<5;i++)
    {
        parent[i] = 0;
        for(int j=0;j<5;j++)
        {
            cin>>adjMatrix[i][j];
            if(adjMatrix[i][j]==0)
            {
                adjMatrix[i][j]=999;
            }

        }
    }
     for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
           cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
        while(nEdges<5)
        {
            Min=999;
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(adjMatrix[i][j]<Min)
                    {
                        Min=adjMatrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }


            if(parent[u]!=0)
            {
                u = parent[u];
            }
            if(parent[v]!=0)
            {
                v = parent[v];
            }

            if(u!=v)
            {
                nEdges++;
                Cost+=Min;
                cout<<u<<"->"<<v<<":"<<Min<<endl;

                //parent[v] = u;
            }
            adjMatrix[u][v] = 999;  /// For dirrected graph
			adjMatrix[v][u] = 999;  /// Replace both for undirected graph


        }
        cout<<"The Minimum cost is "<<Cost<<endl;

}

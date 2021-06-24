//Bell man ford algorithm is used to find the single source shortest path
//drawbacks - This algo cannot find the shortest path if the graph contains the negative cycle- rather it checks if the graph contains the negative cycle or not
#include<bits/stdc++.h>
using namespace std;
#define inf (int)1e9
class Edge
{
public:
	int src,dest,weight;
};
class Graph
{
public:
	int v,e;
	Edge *edge;
	Graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		edge = new Edge[e];
	}
	void addEdge(int u,int v,int w,int count)
	{
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight= w;
	}
	void printGraph()
	{
		for(int i=0;i<e;i++)
		{
			cout<<edge[i].src<<"-"<<edge[i].dest<<"---"<<edge[i].weight<<endl;
		}
	}
	void BellmanFord(int src)
	{
		int distance[v];
		for(int i=0;i<v;++i)
		{
			distance[i] = inf;
		}
		distance[src] = 0;

		//Relaxation code
		for(int i=1;i<=v-1;++i)
		{
			for(int j=0;j<e;++j)
			{
				int src= edge[j].src;
				int dest= edge[j].dest;
				int wt = edge[j].weight;

				//Relaxation check
				if((distance[src]!=inf)&&(distance[src]+wt < distance[dest]))
				{
					distance[dest] = distance[src] + wt;
				}
			}
		}
		//check for negative weight cycles
		for(int j=0;j<e;++j)
		{
			int src= edge[j].src;
			int dest= edge[j].dest;
			int wt = edge[j].weight;

			//Relaxation check
			if((distance[src]!=inf)&&(distance[src]+wt < distance[dest]))
			{
				cout<<"Cylce with negative weight is present"<<endl;
				return;
			}
		}
		for(int i=0;i<v;++i)
		{
			cout<<i<<"-"<<distance[i]<<endl;
		}
		return;
	}

};

//preparing graph
// v = 7 e = 10
/*
// here are the 10 edges with their weighs
1 2 6
1 3 5
1 4 5
3 2 -2
3 5 1
2 5 -1
4 3 -2
4 6 -1
6 7 3
5 7 3
*/
int main()
{
	int v,e;            
	cin>>v>>e;
	Graph g(v,e);
	for(int i=0;i<e;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w,i);
	}
	g.BellmanFord(1);
	return 0;
}
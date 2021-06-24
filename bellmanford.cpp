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
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}
	void addEdge(int u,int v,int w,int count)
	{
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight = w;
	}
	void BellManFord(int src)
	{
		int distance[v];
		for(int i=0;i<v;++i)
		{
			distance[i] = inf;  
		}
		distance[src] = 0;
		for(int i=1;i<=v;++i)
		{
			for(int j=0;j<e;++j)
			{
				int src = edge[j].src;
				int dest = edge[j].dest;
				int wt = edge[j].weight;
				if(distance[src] != inf && distance[src] + wt < distance[dest])
				{
					distance[dest] = distance[src] + wt;
				}
			}
		}
		for(int j=0;j<e;++j)
		{
			int src = edge[j].src;
			int dest = edge[j].dest;
			int wt = edge[j].weight;
			if(distance[src] != inf && distance[src] + wt < distance[dest])
			{
				cout<<"Negative weight cycle exist"<<endl;
				return;
			} 
		}
		for(int i=0;i<v;++i)
		{
			cout<<i+1<<"--"<<distance[i]<<endl;
		}
		return;
	}
};

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
	g.BellManFord(0);
}

// 0 1 6
// 0 2 5
// 0 3 5
// 2 1 -2
// 3 2 -2
// 1 4 -1
// 2 4 1
// 3 5 -1
// 4 6 3
// 5 6 3

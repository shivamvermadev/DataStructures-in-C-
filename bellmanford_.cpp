#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int source;
	int dest;
	int weight;
};

class Graph
{
	int v,e;
	Edge *edge;
public:
	Graph(int v,int e)
	{
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}

	void addEdge(int u,int v,int w,int i)
	{
		edge[i].source = u;
		edge[i].dest = v;
		edge[i].weight = w;
	}

	void bellManFordAlgo(int src)
	{
		map<int,int> dist;
		
		for(int i=0;i<=v;++i)
		{
			dist[i] = INT_MAX;
		}

		dist[src] = 0;
	
		for(int i=1;i<v;++i)
		{
			for(int j=0;j<e;++j)
			{
				int src = edge[j].source;
				int dest = edge[j].dest;
				int weight = edge[j].weight;
				if(dist[src] != INT_MAX && dist[src] + weight < dist[dest])
				{
					dist[dest] = dist[src] + weight;
				}
			}
		}
		for(int j=0;j<e;++j)
		{
			int src = edge[j].source;
			int dest = edge[j].dest;
			int weight = edge[j].weight;
			if(dist[src] != INT_MAX && dist[src] + weight < dist[dest])
			{
				dist[dest] = dist[src] + weight;
				cout<<"The graph has negative weight cycle ";
				return;
			}
		}
		for(int i=0;i<=v;++i)
		{
			cout<<i<<" is at distance of "<<dist[i]<<endl;
		}
	}
};
int main()
{
	int v,e;
	int s,d,w;
	cin>>v>>e;
	Graph g(v,e);
	for(int i=0;i<e;++i)
	{
		cin>>s>>d>>w;
		g.addEdge(s,d,w,i);
	}
	g.bellManFordAlgo(1);
}

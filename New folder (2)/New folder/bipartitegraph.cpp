#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph
{
	map<T,list<T> > adjList;
	public:
	void addEdge(T u,T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void showGraph()
	{
		for(auto i:adjList)
		{
			T node=i.first;
			cout<<node<<":";
			for(T neighbours:adjList[node])
			{
				cout<<neighbours<<"->";
			}
			cout<<endl;
		}
	}
	void bfs(T src)
	{
		queue<T> q;
		map<T,bool> visited;
		q.push(src);
		visited[src] = true;
		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<"->";
			q.pop();
			for(T neighbours:adjList[node])
			{
				if(!visited[neighbours])
				{
					visited[neighbours]= true;
					q.push(neighbours);
				}
			}
		}
	}
	bool isBipartite(T src)
	{

		bool ans = true;
		map<T,int> color;
		for(auto i:adjList)
		{
			T node = i.first;
			color[node]  = -1;
		}
		queue<T> q;
		q.push(src);
		color[src] = 0;
		while(!q.empty())
		{
			T node = q.front();
			for(T neighbours:adjList[node])
			{
				if(color[neighbours]==-1)
				{
					color[neighbours] = 1-color[node];
					q.push(neighbours);
				}
				else if(color[node] == color[neighbours])
				{
					ans = false;
					break;
				}
			}
		}
		return ans;
	}

};

int main()
{
	Graph<int> g;
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	bool ans = g.isBipartite(1);
	if(ans==true)
	{
		cout<<"yes it is";
	}
	else
	{
		cout<<"NO it is not";
	}
	// g.bfs(1);
	// g.showGraph();
}
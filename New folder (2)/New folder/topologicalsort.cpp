#include<bits/stdc++.h>
using namespace std;
template<class T>
class Graph
{
	map<T,list<T> > adjList;
	public:
	void addEdge(T u,T v,bool bidir=false)
	{
		adjList[u].push_back(v);
		if(bidir)
		{
			adjList[v].push_back(u);
		}
	}
	void dfshelper(T node,map<T,bool> &visited,list<T> &ordering)
	{
		visited[node] = true;
		for(T neighbour:adjList[node])
		{
			if(!visited[neighbour])
			{
				dfshelper(neighbour,visited,ordering);
			}
			ordering.push_front(node);
		}
	}
	void topologicalsort()
	{
		map<T,bool> visited;
		list<T> ordering;
		// dfshelper(src,visited,ordering);
		for(auto i:adjList)
		{
			T node = i.first;
			if(!visited[node])
			{
				dfshelper(node,visited,ordering);
			}
		}
		for(T i:ordering)
		{
			cout<<i<<"->";
		}
	}
	void showGraph()
	{
		for(auto i:adjList)
		{
			cout<<i.first<<"->";
			for(auto j:	i.second)
			{
				cout<<j<<"->";
			}
			cout<<endl;
		}
	}
	  void topologicalSortBFS()
  {
    queue<T> q;
    map<T,bool> visited;
    map<T,int> indegree;
    for(auto i:adjList)
    {
      T node = i.first;
      visited[node] = false;
      indegree[node] = 0;
    }
    for(auto i:adjList)
    {
      T node = i.first;
      for(T u:adjList[node])
      {
        indegree[u]++;
      }
    }
    for(auto i:adjList)
    {
      T node = i.first;
      if(indegree[node]==0)
      {
        q.push(node);
      }
    }
    while(!q.empty())
    {
      T node = q.front();
      cout<<node<<"->";
      q.pop();
      for(T neighbour:adjList[node])
      {
        indegree[neighbour]--;
        if(indegree[neighbour]==0)
        {
          q.push(neighbour);
        }
      }
    }
  }

};
int main()
{
	Graph<string> g;
	g.addEdge("English","pl");
	g.addEdge("math","pl");
	g.addEdge("pl","html");

	g.addEdge("pl","python");
	g.addEdge("pl","java");
	g.addEdge("html","css");
	g.addEdge("python","web");
	g.addEdge("java","web");
	g.addEdge("css","js");
	g.addEdge("js","web");
	g.addEdge("English","html");
	// g.showGraph();
	cout<<endl<<endl<<endl;
	// g.topologicalsort();
	g.topologicalSortBFS();
	return 0;
}
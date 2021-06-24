#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
	map<T,list<pair<T,int> > > m;
	public:
	void addEdge(T u,T v,int dist,bool bidir=true)
	{
		m[u].push_back(make_pair(v,dist));
		if(bidir)
		{
			m[v].push_back(make_pair(u,dist));
		}
	}
	void printGraph()
	{
		for(auto i:m)
		{
			cout<<i.first;
			for(auto neighbours:m[i.first])
			{
				cout<<"("<<neighbours.first<<","<<neighbours.second<<")";
			}
			cout<<endl;
		}
	}
	void dijkshtraSSTP(T src)
	{
		map<T,int> dist;

		//set all the distance to infinity 
		for(auto i:m)
		{
			dist[i.first] = INT_MAX;
		}
		//make set to find out node with min distance
		set<pair<int,T> > s; // set sort the element by default on the basis of the first parameter ie the int in this case
		dist[src] = 0;
		s.insert(make_pair(dist[src],src));
		while(!s.empty())
		{
			//find the pair at the front
			auto p = (*s.begin());
			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());

			//Iterate over the neighbours of the current node
			for(auto childPair : m[node])
			{
				if(nodeDist+childPair.second<dist[childPair.first])
				{
					//In set updation in not possible therefore we hava to remove the old pair and insert the new pair to simulate updation 
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end())
					{
						s.erase(f);
					}
					dist[dest] = nodeDist+childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}

		}
		for(auto d:dist)
		{
			cout<<d.first<<" is located at the distance of "<<d.second<<endl;
		}

	}
};

int main()
{
	Graph<int> g;
	g.addEdge(1,2,2);
	g.addEdge(1,3,4);
	g.addEdge(2,4,7);
	g.addEdge(2,3,1);
	g.addEdge(3,5,3);
	g.addEdge(5,4,2);
	g.addEdge(4,6,1);
	g.addEdge(5,6,5);
	// g.printGraph();
	g.dijkshtraSSTP(1);
	return 0;
}
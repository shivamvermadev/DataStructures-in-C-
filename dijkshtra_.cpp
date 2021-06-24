#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	map<T,list<pair<T,int> > > ajdlist;
public:
	void addEdge(int u,int v,int w,bool bidir = true)
	{
		ajdlist[u].push_back(make_pair(v,w));
		if(bidir)
		{
			ajdlist[v].push_back(make_pair(u,w));
		}
	}
	void showGraph()
	{
		for(auto i:ajdlist)
		{
			T node = i.first;
			cout<<node<<"->";
			for(auto j : ajdlist[node])
			{
				cout<<"("<<j.first<<", "<<j.second<<"),";//     <<endl;
			}
			cout<<endl;
		}
	}

	void dijkshtra(T src)
	{
		map<T,int> dist;
		for(auto i:ajdlist)
		{
			dist[i.first] = INT_MAX;
			for(auto j:ajdlist[i.first]) {
				dist[j.first] = INT_MAX;
			}
		}

		dist[src] = 0;
		set<pair<int,T> > s;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto p = *s.begin();
			T node = p.second;
			int nodedist = p.first;
			s.erase(s.begin());
			for(auto childPair:ajdlist[node])
			{
				if(nodedist + childPair.second < dist[childPair.first])
				{
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f != s.end())
					{
						s.erase(f);
					}
					dist[dest] = nodedist + childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		for(auto d:dist)
		{
			cout<<d.first<<" is located at a distance of "<<d.second<<endl;
		}
	}
	void dijkshtra_(T src)
	{
		map<T,int> dist;
		for(auto i:ajdlist)
		{
			dist[i.first] = INT_MAX;
		}

		set<pair<int,T> > s;
		dist[src] = 0;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto p = *s.begin();
			s.erase(s.begin());
			T node = p.second;
			int nodedist = p.first;
			for(auto i:ajdlist[node])
			{
				if(dist[node] + i.second < dist[i.first])
				{
					auto f = s.find(make_pair(dist[i.first],i.first));
					if(f != s.end())
					{
						s.erase(f);
					}
					dist[i.first] = dist[node] + i.second;
					s.insert(make_pair(dist[i.first],i.first));
				}
			}
		}
		for(auto d:dist)
		{
			cout<<d.first<<" is located at a distance of "<<d.second<<endl;
		}
	}
	void dijkshtra__(T src)
	{
		map<T,int> dist;
		set<pair<int,T> > s;
		for(auto i:ajdlist)
		{
			dist[i.first] = INT_MAX;
		}
		dist[src] = 0;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto p = *(s.begin());
			s.erase(s.begin());
			T u = p.second;
			int nodedist = p.first;
			for(auto i:ajdlist[u])
			{
				T v = i.first;
				int costUV = i.second;
				if(nodedist + costUV < dist[v])
				{
					auto f = s.find(make_pair(dist[v],v));
					if(f != s.end())
					{
						s.erase(f);
					}
					dist[v] = nodedist + costUV;
					s.insert(make_pair(dist[v],v));
				}
			}
		}

		for(auto d:dist)
		{
			cout<<d.first<<" is located at a distance of "<<d.second<<endl;
		}
	}
};


int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Graph<int> g;
    // g.addEdge(1, 2, 2);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 1);
    // g.addEdge(2, 4, 7);
    // g.addEdge(3, 5, 3);
    // g.addEdge(5, 4, 2);
    // g.addEdge(5, 6, 5);
    // g.addEdge(4, 6, 1);
    // g.showGraph();
    // g.dijkshtra(1);
   Graph<int> g;
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(4, 3, 2);
    g.addEdge(2, 3, -10);
    g.showGraph();
    g.dijkshtra(1); 
	g.dijkshtra(1);
	cout<<endl;
	// g.dijkshtra_(1);
	// cout<<endl;
	// g.dijkshtra__(1);
	return 0;
}
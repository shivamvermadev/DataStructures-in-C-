#include<bits/stdc++.h>
using namespace std;
#define int long long int

template<typename T> 
class Graph {
	unordered_map<T, list<T>> adjList;
	public:

	void addEdge(T u, T v, bool bidir = false) {
		adjList[u].push_back(v);
		if(bidir) {
			adjList[v].push_back(u);
		}
	}

	void showGraph() {
		for(auto i : adjList) {
			cout<<i.first<<"->";
			for(auto j : i.second) {
				cout<<j<<", ";
			}
			cout<<"\n";
		}
	}

	void bfs(T src) {
		unordered_map<T, bool> visited;

		visited[src] = true;
		queue<T> q;
		q.push(src);
		unordered_map<T, int> distance;
		unordered_map<T, T> parent;
		parent[src] = src;
		distance[src] = 0;

		while(q.empty() == false) {
			T node = q.front();
			cout<<node<<", ";
			q.pop();
			for(auto j : adjList[node]) {
				if(visited[j] == false) {
					distance[j] = 1 + distance[node];
					q.push(j);
					visited[j] = true;
					parent[j] = node;
				}
			}
		}
		cout<<'\n';

		for(auto i : distance) {
			cout<<i.first<<" "<<i.second<<"\n";
		}

		cout<<distance[36]<<"\n";

		T node = 36;


		while(node != src) {
			cout<<node<<"->";
			node = parent[node];
		}
		cout<<"->"<<node;

	}

	void dfsHelper(T src, unordered_map<T, bool> &visited, unordered_map<T, int> &distance) {
		cout<<src<<"->";
		visited[src] = true;
		for(auto j : adjList[src]) {
			if(visited[j] == false) {
				distance[j] = 1 + distance[src];
				dfsHelper(j, visited, distance);
			}
		}
	}

	void dfs(T src) {
		unordered_map<T, int> distance;
		distance[src] = 0;
		unordered_map<T, bool> visited;
		dfsHelper(src, visited, distance);

		cout<<"\n";
		for(auto i : distance) {
			cout<<i.first<<"-"<<i.second<<"\n";
		}
	}

	void connectedComponents(T src) {
		
		int ans = 1;

		unordered_map<T, bool> visited;
		unordered_map<T, int> distance;
		dfsHelper(src, visited, distance);

		for(auto i : adjList) {
			if(visited[i.first] == false) {
				ans++;
				dfsHelper(i.first, visited, distance);
			}
		}
		cout<<"\n";
		cout<<ans<<"\n";
	}

	void topologicalSortHelper(T src, unordered_map<T, bool> &visited, list<T> &ordering) {
		visited[src] = true;

		for(T j : adjList[src]) {
			if(visited[j] == false) {
				topologicalSortHelper(j, visited, ordering);
			}
		}
		ordering.push_front(src);
	}

	void topologicalSort(T src) {
		unordered_map<T, bool> visited;
		list<T> ordering;

		topologicalSortHelper(src, visited, ordering);
		for(auto i : ordering) {
			cout<<i<<"->";
		}
	}

	void topologicalSortBFSKahn(T src) {
		unordered_map<T, int> indegree;
		queue<T> q;
		unordered_map<T, bool> visited;

		for(auto i : adjList) {
			visited[i.first] = false;
			indegree[src] = 0;
		}

		for(auto i : adjList) {
			for(T node : i.second) {
				indegree[node]++;
			}
		}


		for(auto i : adjList) {
			T node = i.first;
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		while(q.empty() == false) {
			T node = q.front();
			cout<<node<<"->";
			q.pop();
			for(T neighbour : adjList[node]) {
				indegree[neighbour]--;
				if(indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}
	}

	void cycleDetection(T src) {

		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;
		queue<T> q;

		visited[src] = true;
		parent[src] = src;
		q.push(src);

		bool ans = false;
		while(q.empty() == false ) {
			T node = q.front();
			q.pop();

			for(T neighbour : adjList[node]) {
				if(visited[neighbour] == true && parent[node] != neighbour) {
					ans = true;
					break;
				}
				else if(visited[neighbour] == false) {
					q.push(neighbour);
					parent[neighbour] = node;
					visited[neighbour] = true;
				}
			}
		}
		if(ans) {
			cout<<"Cycle";
		}	
		else {
			cout<<"No cycle";
		}
	}
};

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// Graph<int> g;

	// int board[50] = {0};
	// board[2] = 13;
	// board[5] = 2;
	// board[9] = 18;
	// board[18] = 11;
	// board[17] = -13;
	// board[20] = -14;
	// board[24] = -8;
	// board[25] = -10;
	// board[32] = -2;
	// board[34] = -22;

	// for(int i=0;i<36;++i) {
	// 	for(int j=1;j<=6;++j) {
	// 		int u = i;
	// 		int v = i + j + board[i+j];
	// 		g.addEdge(u, v, false);
	// 	}
	// }
	
	// g.bfs(0);

	Graph<int> g;
	g.addEdge(1, 0, true);
	g.addEdge(1, 2, true);
	g.addEdge(2, 4, true);
	g.addEdge(0, 4, true);
	g.cycleDetection(1);
	// g.addEdge(3, 3, true);
	// g.addEdge(4, 3, true);
	// g.addEdge(3, 5, true);

	// g.addEdge(6, 7);
	// g.addEdge(8, 9);
	// g.connectedComponents(1);
	// g.dfs(1);

//   Graph<string> g;
//   g.addEdge("english","programming language");
//   g.addEdge("math","programming language");
//   g.addEdge("programming language","html");
//   g.addEdge("programming language","python");
//   g.addEdge("programming language","java");
//   g.addEdge("programming language","js");
//   g.addEdge("html","css");
//   g.addEdge("python","web dev");
//   g.addEdge("css","js");
//   g.addEdge("js","web dev");
//   g.addEdge("java","web dev");

	// g.topologicalSort("english");
	// cout<<"\n";
	// g.topologicalSortBFSKahn("english");
	// g.cycleDetection("english");

return 0;
}
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
  map<T,list<T> > m;

public:
  void addEdge(T u,T v)
  {
    m[u].push_back(v);
    m[v].push_back(u);
  }
  
  void showGraph()
  {
   for(auto i:m)
   {
    T node = i.first;
    cout<<node<<"->";
    for(auto j:m[node])
    { 
      cout<<j<<",";
    }
    cout<<endl;
   }
  }

  void BFS(T src)
  {
    map<T,int> dist;
    map<T,bool> visited;
    map<T,T> parent;

    queue<T> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    parent[src] = src;

    while(!q.empty())
    {
      T node = q.front();
  
      cout<<node<<",";

      q.pop();
      for(auto i:m[node])
      {
        if(visited[i] == false)
        {
          q.push(i);
          visited[i] = true;
          parent[i] = node;
          dist[i] = dist[node] + 1;
        }
      }
    }
    for(auto i:dist)
    {
      cout<<"distance of "<<src<<" from "<<i.first<<" is "<<i.second<<endl;
    }
  }

  void dfsHelper(T node,map<T,bool> &visited,list<T> &linearOrder)
  {
    visited[node] = true;
    cout<<node<<",";
    for(auto i:m[node])
    {
      if(visited[i] == false)
      {
        dfsHelper(i,visited,linearOrder);
      }
    }
    linearOrder.push_front(node);
  }
  
  void dfs()
  {
    map<T,bool> visited;
    int component = 0;
    list<T> linearOrder;

    for(auto i:m)
    {
      T node = i.first;
      if(visited[node] == false)
      {
        dfsHelper(node,visited,linearOrder);
        component++;
      }
    }
    // cout<<endl;
    // cout<<"The component is "<<component;
    cout<<endl;
    
    for(auto i:linearOrder)
    {
      cout<<i<<"->";
    }
  }
  void topologicalSortBFSKhans()
  {
    map<T,int> indegree;
    map<T,bool> visited;
    queue<T> q;

    for(auto i:m)
    {
      T node = i.first;
      visited[node] = false;
      indegree[node] = 0;
    }
    for(auto i:m)
    {
      T u = i.first;
      for(T v : m[u])
      {
        indegree[v]++;
      }
    }
    for(auto i:m)
    {
      T node = i.first;
      if(indegree[node] == 0)
      {
        q.push(node);
      }
    }
    while(!q.empty())
    {
      T node = q.front();
      q.pop();
      cout<<node<<"->";
      for(T neighbour : m[node])
      {
        indegree[neighbour]--;
        if(indegree[neighbour] == 0)
        {
          q.push(neighbour);
        }
      }
    }
  }

  bool cycleDetectionBFS_undirectedGraph(T src)
  {
    queue<T> q;
    map<T,bool> visited;
    map<T,T> parent;
    visited[src] = true;
    parent[src] = src;
    q.push(src);

    while(!q.empty())
    {
      T node = q.front();
      q.pop();
      for(auto neighbour : m[node])
      {
        if(visited[neighbour]==true && parent[node] != neighbour)
        {
          return true;
        } 
        else
        {
          q.push(neighbour);
          parent[neighbour] = node;
        }
      }
    }
    return false;
  }

  void newDFSHelper(T node,map<T,bool> &visited)
  {
    visited[node] = true;
    for(auto i:m[node])
    {
      if(visited[i]==false)
       newDFSHelper(i,visited);
    }
  }

  bool stronglyConnectedComponents()
  {
    map<T,bool> visited;
    for(auto i:m)
    {
      T node = i.first;
      if(visited[node] == false)
        newDFSHelper(node,visited);
    }
    return true;
  }

  bool isBipartiteGraph(T src)
  {
    queue<T> q;
    q.push(src);
    map<T,int> colors;
    for(auto i:m)
    {
      colors[i.first] = -1;
    }
    colors[src] = 0;
    bool ans = true;
    while(!q.empty())
    {
      T node = q.front();
      q.pop();
      for(auto v:m[node])
      {
        if(colors[v] == -1)
        {
          colors[v] = 1+colors[node];
          q.push(v);
        }
        else if(colors[v] == colors[node])
        {
          ans = false;
          break;
        }
      }
    }
    return ans;
  }
  bool isCyclicHelper(T node,map<T,bool> &visited,T parent)
  {
    visited[node] = true;
    // parent[]
    for(T neighbour : m[node])
    {
      if(!visited[neighbour])
      {
        bool ans = isCyclicHelper(neighbour,visited,parent);
        if(ans)
          return true;
      }
      else if(neighbour != parent)
        return true;
    }
    return false;
  }
  bool cycleDetectionDFS()
  {
    map<T,bool> visited;
    // T parent;

    for(auto i:m)
    {
      T node = i.first;
      // parent[node] = node;
      if(visited[node] == false)
      {
        bool ans = isCyclicHelper(node,visited,node);
        if(ans)
          return true;
      }
    }
    return false;
  }
};


int main()
{
  // Graph<int> g;
  // g.addEdge(1,2);
  // g.addEdge(1,3);
  // g.addEdge(2,3);
  // g.addEdge(3,2);
  // g.addEdge(3,4);
  // g.addEdge(7,8);
  // g.showGraph();

  // cout<<endl;
  // g.BFS(1);
  // g.dfs();

  // Graph<string> g;
  // g.addEdge("english","programming language");
  // g.addEdge("math","programming language");
  // g.addEdge("programming language","html");
  // g.addEdge("programming language","python");
  // g.addEdge("programming language","java");
  // g.addEdge("programming language","js");
  // g.addEdge("html","css");
  // g.addEdge("python","web dev");
  // g.addEdge("css","js");
  // g.addEdge("js","web dev");
  // g.addEdge("java","web dev");

  // g.dfs();
  // cout<<endl;
  // g.topologicalSortBFSKhans();
  // cout<<endl;
  // g.cycleDetectionBFS_undirectedGraph(1)?cout<<"Yes cycle is present":cout<<"No cycle is not present";

  Graph<int> g;
  g.addEdge(1,4);
  g.addEdge(2,4);
  g.addEdge(2,5);
  g.addEdge(3,4);
  g.addEdge(3,5);
  cout<<g.isBipartiteGraph(1);
  cout<<endl;
  cout<<g.cycleDetectionDFS();


  
  return 0;
}
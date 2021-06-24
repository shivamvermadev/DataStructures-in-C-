#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
  int V;
  map<T,list<T> > adjList;
  public:
  void addEdge(T u,T v,bool bidir=true)
  {
    adjList[u].push_back(v);
    if(bidir)
    {
      adjList[v].push_back(u);
    }
  }
  void showGraph()
  {
    for(auto i:adjList)
    {
      cout<<i.first<<"->";
      for(int j:i.second)
      {
        cout<<j<<"->";
      }
      cout<<endl;
    }
  }
  void SSTP(T src,T dest)      //single source shortest path
  {
    map<T,T> parent;
    map<T,int> dist;
    queue<T> q;
    for(auto i:adjList)
    {
      dist[i.first] = INT_MAX;
    }
    parent[src] = src;
    dist[src] = 0;
    q.push(src);
    while(!q.empty())
    {
      T node = q.front();
      // cout<<node<<"->";
      q.pop();
      for(auto neighbour:adjList[node])
      {
        if(dist[neighbour]==INT_MAX)
        {
          q.push(neighbour);
          dist[neighbour] = dist[node]+1;
          parent[neighbour] = node;
        }
      }
    }
    // for(auto i:adjList)
    // {
    //   T node = i.first;
    //   cout<<"distance of "<<node<<" from "<<src<<" is"<<dist[node]<<endl;
    // }
    cout<<"The distance is "<<dist[dest]<<endl<<endl<<endl;
    T temp = dest;
    while(temp!=src)
    {
      cout<<temp<<"<-";
      temp = parent[temp];
    }
    cout<<src<<endl;
  } 
  void DFShelper(T node, map<T,bool> &visited)
  {
    visited[node] = true;
    cout<<node<<"->";
    for(T neighbour:adjList[node])
    {
      if(!visited[neighbour])
      {
        DFShelper(neighbour,visited);
      }
    }
  }
  void DFS(T src)
  {
    int component = 1;
    map<T,bool> visited;
    DFShelper(src,visited);
    for(auto i:adjList)
    {
      T node = i.first;
      if(!visited[node])
      {
        DFShelper(node,visited);
        component++;
      }
    }
    cout<<"The component are "<<component<<endl;
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
  bool cycleDetection(T src)
  {
    map<T,bool> visited;
    map<T,T> parent;
    queue<T> q;
    q.push(src);
    parent[src] = src;
    visited[src] = true;
    while(!q.empty())
    {
      T node = q.front();
      q.pop();
      for(T neighbour : adjList[node])
      {
        if(visited[neighbour] == true && parent[node]!=neighbour)
        {
          return true;
        }
        else if(!visited[neighbour])
        { 
          visited[neighbour]=true;
          parent[neighbour] = node;
          q.push(neighbour);
        }
      }
    }
    return false;
  }
  bool cycleDetectionDFSHelper(T node,map<T,bool> &visited,T parent)
  {
    visited[node] = true;
    for(T neighbour:adjList[node])
    {
      if(!visited[neighbour])
      {
        // parent[neighbour] = node;
        bool ans = cycleDetectionDFSHelper(neighbour,visited,node);
        if(ans)
          return true;
      }
      else if(neighbour != parent)
      {
        return true;
      }
    }
    return false;
  }
  bool cycleDetectionDFS()
  {
    map<T,bool> visited;
  
    for(auto i:adjList)
    {
      T node = i.first;
      if(!visited[node]){
        bool ans = cycleDetectionDFSHelper(node,visited,node);
        if(ans)
          return true;
      }
    }
    return false;
  }
  void transposeTheGraph()
  {
    map<T,list<T> > transposeList;
    for(auto i:adjList)
    {
      T node = i.first;
      for(T neighbour : adjList[node])
      {
        transposeList[neighbour].push_back(node);
      }
    }
    for(auto i:transposeList)
    {
      T node = i.first;
      cout<<node<<"->";
      for(T neighbour:transposeList[node])
      {
        cout<<neighbour<<"->";
      }
      cout<<endl;
    }
  }
};
int main()
{
  Graph<int> g;

  // g.addEdge(1,0,true);
  // g.addEdge(1,2,true);
  // g.addEdge(2,4,true);
  // g.addEdge(0,4,true);
  g.addEdge(1,3);
  g.addEdge(3,4);
  g.addEdge(1,2);
  g.addEdge(2,5);
  // g.addEdge(1,2);
  // g.addEdge(1,4);
  // g.addEdge(2,3);
  // g.addEdge(3,4);
  // g.showGraph();
  // g.DFS(0);
  // bool ans = g.cycleDetectionDFS();
  // if(ans==true)
  // {
  //   cout<<"Cycle is present";
  // }
  // else
  // {
  //   cout<<"Cycle is not present";
  // }
  g.showGraph();
  cout<<endl<<endl<<endl;
  // g.transposeTheGraph();
  return 0;
}
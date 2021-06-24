#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
   map<T,list<T> > adjList;
   public:
   
   void addEdge(T u,T v)
   {  
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }

   void show()
   {
      for(auto i : adjList)
      {
         T node = i.first;
         cout<<node<<"->";
         for(auto j:i.second)
         {
            cout<<j<<",";
         }
         cout<<endl;
      }
   }
   void bfs(T src)
   {
      queue<T> q;
      map<T,int> dist;
      map<T,bool> visited;
      q.push(src);
      visited[src] = true;
      dist[src] = 0;
      while(!q.empty())
      {
         T node = q.front();
         cout<<node<<",";
         q.pop();
         for(auto j:adjList[node])
         {
            if(!visited[j])
            {
               q.push(j);
               visited[j] = true;
               dist[j] = 1 + dist[node];
            }
         }
      }
      cout<<endl<<"distance between src and other nodes are"<<endl;
      for(auto i:dist)
      {
         cout<<i.first<<"--"<<i.second<<endl;
      }
   }
   void dfsHelper(T node,map<T,bool> &visited,list<T> &l)
   {
      cout<<node<<",";
      visited[node]  =true;
      for(auto i:adjList[node])
      {
         if(!visited[i])
         {
            dfsHelper(i,visited,l);
         }
      }
      l.push_front(node);
   }
   void dfs()
   {
      map<T,bool> visited;
      list<T> l;
      for(auto i:adjList)
      {
         if(!visited[i.first])
         {
            dfsHelper(i.first,visited,l);
         }
      }
      cout<<endl;
      for(auto i:l)
      {
         cout<<i<<",";
      }
   }

   void bfsKahnTopologicalSort()
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

      for(auto i : adjList)
      {
         T node = i.first;
         for(T j : adjList[node])
         {
            indegree[j]++;
         }
      }
      for(auto i:adjList)
      {
         T node = i.first;
         if(indegree[node] == 0)
            q.push(node);
      }

      while(!q.empty())
      {
         T node = q.front();
         q.pop();
         cout<<node<<"->";
         for(T node : adjList[node])
         {
            indegree[node]--;
            if(indegree[node] ==0)
            {
               q.push(node);
            }
         }
      }
   }
   bool cycleDetectionBFS(T src)
   {
      map<T,bool> visited;
      map<T,T> parent;
      queue<T> q;

      parent[src] = src;
      visited[src] = true;
      q.push(src);   
      
      while(!q.empty())
      {
         T node = q.front();
         q.pop();
         for(T j : adjList[node])
         {
            if(visited[j]==true && parent[node] != j)
            {
               return true;
            }
            else if(visited[j] == false)
            {
               visited[j] = true;
               parent[j] = node;
               q.push(j);
            }
         }
      }
      return false;
   }
   bool isBipartite(T src)
   {
      map<T,int> color;
      queue<T> q;
      q.push(src);
      for(auto i : adjList)
      {
         color[i.first] = -1;
      }
      bool ans = true;
      color[src]  = 0;
      while(!q.empty())
      {
         T node = q.front();
         q.pop();
         for(T j : adjList[node])
         {
            if(color[j] == -1)
            {
               color[j] = 1 - color[node];
               q.push(j);
            }
            else if(color[j] == color[node])
            {
               ans = false;
               break;
            }
         }
      } 
      return ans;
   }
};

int main(int argc, char const *argv[])
{
   Graph<int> g;
   g.addEdge(1,2);
   g.addEdge(1,3);
   g.addEdge(2,4);
   g.addEdge(3,4);
   g.addEdge(2,3);
   // g.show();
   // g.bfs(0);
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
  // g.bfsKahnTopologicalSort();
   // cout<<g.cycleDetectionBFS(0);
   cout<<g.isBipartite(1);
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template<typename T>
class Graph
{
    map<T,list<T> > adjlist;
public:
    void addEdge(T u,T v)
    {
        adjlist[u].push_back(v);
        // adjlist[v].push_back(u);
    }
    void addedge(T u,T v)
    {
        adjlist[u].push_back(v);
        // adjlist[v].push_back(u);
    }
    
    void show()
    {
        for(auto i:adjlist)
        {
            T node = i.first;
            cout<<node<<"->";
            for(auto j:adjlist[node])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
 
    void bfs(T src)
    {
        map<T,int> dist;
        dist[src] = 0;
        queue<T> q;
        map<T,bool> visited;
        map<T,T> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<",";
            for(auto child:adjlist[node])
            {
                if(visited[child] == false)
                {
                    dist[child] = 1 + dist[node];
                    visited[child] = true;
                    parent[child] = node;
                    q.push(child);
                }
            }
        }
        for(auto i:dist)
        {
            cout<<"distance of "<<i.first<<" from "<<src<<" is"<<i.second<<endl;
        }
    }

    void dfsHelper(T node,std::map<T, bool> &visited)
    {
        cout<<node<<endl;
        visited[node] = true;
        for(auto j : adjlist[node])
        {
            if(visited[j] == false)
            {
                dfsHelper(j,visited);
            }
        }
    }

    void dfs()
    {
        int connectedComponent = 0;
        map<T,bool> visited;
        for(auto i:adjlist)
        {
            if(visited[i.first] == false){
                dfsHelper(i.first,visited);
                connectedComponent++;
            }
        }
      cout<<"connectedComponent "<<connectedComponent<<endl;
    }

    void topologicalHelper(T node,map<T,bool> &visited,list<T> &ordering)
    {
        visited[node] = true;
        for(auto j : adjlist[node])
        {
            if(!visited[j])
                topologicalHelper(j,visited,ordering);
        }
        ordering.push_front(node);
    }

    void dfsTopologicalSort()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto i:adjlist)
        {
            T node = i.first;
            if(visited[node] == false)
            {
                topologicalHelper(node,visited,ordering);
            }
        }
        for(auto i:ordering)
        {
            cout<<i<<"->";
        }
    }

    void topologicalSortKhans()
    {
        map<T,int> indegree;
        queue<T> q;

        for(auto i:adjlist)
        {
            indegree[i.first] = 0;
        }

        for(auto i:adjlist)
        {
            T u = i.first;
            for(auto v : adjlist[u])
            {
                indegree[v]++;
            }
        }

        for(auto i:adjlist)
        {
            if(indegree[i.first] == 0)
            {
                q.push(i.first);
            }
        }

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto j:adjlist[node])
            {
                indegree[j]--;
                if(indegree[j] == 0)
                {
                    q.push(j);
                }
            }
        }
    }

    bool cycleDetectionBFS(T src)
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,T> parent;
        q.push(src);
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour : adjlist[node])
            {
                if(visited[neighbour] == true && parent[node] != neighbour)
                {
                    return true;
                }
                
                else if(visited[neighbour] == false)
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = node;
                }
            }
        }
        return false;
    }

    void stronglyConncetedDFS(T node,map<T,bool> &visited,int &count)
    {
        count++;
        visited[node] = true;
        for(auto i : adjlist[node])
        {
            if(!visited[i])
            {
                stronglyConncetedDFS(i,visited,count);
            }
        }
    }

    bool stronglyConnceted()
    {
        int noOfNodes = 0;
        for(auto i:adjlist){
            noOfNodes++;
        }
        cout<<"No of nodes "<<noOfNodes<<endl;
        int count=0;
        for(auto i:adjlist)
        {
            count=0;
            T node = i.first;
            map<T,bool> visited;
            stronglyConncetedDFS(node,visited,count);
            if(count != noOfNodes)
            {
                cout<<"Count "<<count<<endl;
                return false;
            }
        }
        return true;
    }
    
    void stronglyConnectedKosaRajusAlgorithm(){
        map<T,list<T> > tempAdjList;
        
        for(auto i:adjlist)
        {
            T node = i.first;
            for(auto j : adjlist[node])
            {
                tempAdjList[j].push_back(node);
            }
        }
        
        for(auto i:adjlist)
        {
            T node = i.first;
            cout<<node<<"->";
            for(auto j : adjlist[node])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
        
        cout<<endl;

        for(auto i:tempAdjList)
        {
            T node = i.first;
            cout<<node<<"->";
            for(auto j : tempAdjList[node])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    
    bool isBipartite(T src)
    {
        map<T,int> color;
        for(auto i:adjlist)
        {
            color[i.first] = -1;
        }
        queue<T> q;
        color[src] = 0;
        q.push(src);
        while(!q.empty())
        {
            T u = q.front();
            q.pop();
            for(auto v:adjlist[u])
            {
                if(color[v] == -1)
                {
                    color[v] = 1 - color[u];
                }
                else if(color[v] == color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{    

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Graph<int> g;
    // g.addedge(1,2);
    // g.addedge(2,3);
    // g.addedge(3,4);
    // g.addedge(4,1);
    // g.addedge(4,5);
    // g.addedge(5,6);
    // g.addedge(6,4);
    // g.addedge(1,2);
    // g.addedge(1,3);
    // g.addedge(2,3);
    // g.addedge(2,4);
    // g.addedge(3,4);
    // g.addedge(3,5);
    // g.addedge(5,6);
    // g.addedge(7,8);
    // g.show();
    // cout<<endl;
    // g.bfs(1);
    // cout<<endl;
    // g.dfs();

  //    Graph<string> g;
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
  //   g.dfsTopologicalSort();
  //   cout<<endl;
  //   g.topologicalSortKhans();
    // cout<<g.cycleDetectionBFS(1);

    // cout<<g.stronglyConnceted()<<endl;    
    // g.stronglyConnectedKosaRajusAlgorithm();
    g.addedge(1,2);
    g.addedge(2,1);
    g.addedge(1,4);
    g.addedge(4,1);
    g.addedge(2,3);
    g.addedge(3,2);
    g.addedge(4,3);
    g.addedge(3,4);
    cout<<g.isBipartite(1);

    return 0;
}
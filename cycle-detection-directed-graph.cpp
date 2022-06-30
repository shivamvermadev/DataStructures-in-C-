#include <bits/stdc++.h>
using namespace std;
#define int long long int

unordered_map<int, list<int>> adjList;

bool cycleDetectionDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool ans = cycleDetectionDFS(neighbour, visited, recStack);
            if (ans)
                return true;
        }
        else if (recStack[neighbour] == true)
        {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}

bool findCylceInDirectedGraph()
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> recStack;

    for (auto i : adjList)
    {
        int node = i.first;
        if (visited[node] == false)
        {
            bool ans = cycleDetectionDFS(node, visited, recStack);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
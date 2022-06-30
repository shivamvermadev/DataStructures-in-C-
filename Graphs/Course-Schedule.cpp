#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
public:
    unordered_map<int, list<int>> adjList;

    unordered_map<int, bool> recStack;
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
    
    // Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }

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
                    return false;
                }
            }
        }
        return true;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    return 0;
}
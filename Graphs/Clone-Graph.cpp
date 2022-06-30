#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) { // using BFS
        if(node == NULL) {
            return NULL;
        }
        
        map<Node*, Node*> visited;
        queue<Node*> q;

        q.push(node);
        
        Node *node1 = new Node;
        node1->val = node->val;
        visited[node] = node1;
        
        while(q.empty() == false) {
            Node *temp = q.front();
            q.pop();
            
            Node *ptr = visited[temp];
            
            for(auto i : temp->neighbors) {
                
                if(visited.find(i) == visited.end()) {
                    Node *neighbour = new Node;
                    neighbour->val = i->val;
                    q.push(i);
                    ptr->neighbors.push_back(neighbour);
                    visited[i] = neighbour;
                }
                else {
                    Node *correspondingNode = visited[i];
                    ptr->neighbors.push_back(correspondingNode);
                }
            }
        }
        return visited[node];      
    }
};
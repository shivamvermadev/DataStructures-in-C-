#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left, *right;
};


//Leetcode
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) {
            return v;
        }
        
        stack<pair<TreeNode*, int>> s1, s2;
        
        s1.push(make_pair(root, 0));
        map<int, vector<int>> m;
        
        while(s1.empty() == false || s2.empty() == false) {
            
            while(s1.empty() == false) {
                pair<TreeNode*, int> temp = s1.top();
                s1.pop();
                
                int level = temp.second;
                TreeNode *node = temp.first;
                
                m[level].push_back(node->val);
                
                if(node->left) {
                    s2.push(make_pair(node->left, level + 1));
                }
                if(node->right) {
                    s2.push(make_pair(node->right, level + 1));
                }
            }
            
            while(s2.empty() == false) {
                pair<TreeNode*, int> temp = s2.top();
                s2.pop();
                
                int level = temp.second;
                TreeNode *node = temp.first;
                
                m[level].push_back(node->val);
                
                if(node->right) {
                    s1.push(make_pair(node->right, level + 1));
                }
                if(node->left) {
                    s1.push(make_pair(node->left, level + 1));
                }
                
            }
        }
        for(auto i : m) {
            v.push_back(i.second);
        }
        return v;
    }
};

//----------------------------- GFG
vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if(root == NULL) {
        return v;
    }
    stack<Node*> s1, s2;
    
    s1.push(root);
    
    
    while(s1.empty() == false  || s2.empty() == false) {
        while(s1.empty() == false) {
            Node *top = s1.top();
            v.push_back(top->data);
            
            s1.pop();
            if(top->right) {
                s2.push(top->right);
            }
            if(top->left) {
                s2.push(top->left);
            }
        }
        
        while(s2.empty() == false) {
            Node *top = s2.top();
            v.push_back(top->data);
            
            s2.pop();
            if(top->left) {
                s1.push(top->left);
            }
            if(top->right) {
                s1.push(top->right);
            }
        }
    }

}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    
    

return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int

/**
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Link - https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        map<TreeNode*, unsigned long long> m;
        
        m[root] = 0;
        int ans = 0;
        
        while(q.empty() == false) {
            
            int sz = q.size();
            
            unsigned long long start = 0;
            unsigned long long end = 0;
            int i = 1;
            
            while(i <= sz) {
                
                TreeNode *node = q.front();
                q.pop();
                
                if(i == 1) {
                    start = m[node];
                }
                
                if(i == sz) {
                    end = m[node];
                }
                
                if(node->left) {
                    q.push(node->left);
                    unsigned long long s = m[node];
                    s = s * 2 + 1;
                    m[node->left] = s;
                }
                
                if(node->right) {
                    q.push(node->right);
                    unsigned long long s = m[node];
                    s = s* 2 + 2;
                    m[node->right] = s;
                }
                
                i++;
            }
            
            int x = end - start + 1;
            ans = max(ans, x);
            
        }
        return ans;
    }
};


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}
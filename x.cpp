#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

TreeNode *createNode(int x) {
    TreeNode *root = new TreeNode;
    root->val = x;
    root->left = root->right = NULL;
    return root;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode *createNode(int x) {
        TreeNode *root = new TreeNode;
        root->val = x;
        root->left = root->right = NULL;
        return root;
    }
    
    TreeNode *f(int inS, int inE, int poS, int poE, vector<int> &in, vector<int> &po) {
        if(inS > inE) {
            return NULL;
        }
        
        int rootData = po[poE];
        
        int index = -1;
        for(int i=inS;i<=inE;++i) {
            if(in[i] == rootData) {
                index = i;
                break;
            }
        }
        
        int leftInS = inS;
        int leftInE = index - 1;
        int rightInS = index + 1;
        int rightInE = inE;
        
        int leftPoS = poS;
        int leftPoE = leftInE - leftInS + leftPoS;
        int rightPoS = leftPoE + 1;
        int rightPoE = poE - 1;
        
        TreeNode *root = createNode(rootData);
        root->left = f(leftInS, leftInE, leftPoS, leftPoE, in, po);
        root->left = f(rightInS, rightInE, rightPoS, rightPoE, in, po);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n = in.size();
        
        return f(0, n-1, 0, n-1, in, po);
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    TreeNode *root = createNode(-10);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);


    Solution s;
    vector<int> in{9,3,15, 20, 7};    
    vector<int> po{9,15, 7, 20, 3};
    s.buildTree(in, po);    

    

return 0;
}
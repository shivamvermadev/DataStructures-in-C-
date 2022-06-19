#include<bits/stdc++.h>
using namespace std;
#define int long long int


struct TreeNode {
    int val;
    TreeNode *left, *right;
};



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
        int c = (leftInE - leftInS + 1);
        int leftPoE = poS + c - 1; 
        int rightPoS = poS + c;
        int rightPoE = poE - 1;
        
        TreeNode *root = createNode(rootData);
        root->left = f(leftInS, leftInE, leftPoS, leftPoE, in, po);
        root->right = f(rightInS, rightInE, rightPoS, rightPoE, in, po);
        
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
    
    
    

return 0;
}
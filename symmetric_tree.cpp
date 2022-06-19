#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    bool f(TreeNode *root1, TreeNode *root2) {
        if((root1 == NULL && root2 != NULL) 
           || (root1 != NULL && root2 == NULL))  {
            return false;
        }
        if(root1 == NULL && root2 == NULL) {
            return true;
        }
        
        if(root1->val == root2->val) {
            return f(root1->left, root2->right) && f(root1->right, root2->left);
        }
        else{ 
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL) {
            return true;
        }
        
        return f(root, root);
        
        
    }
};

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    

return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.

    pair<int, bool> balancedHelper(Node *root) {
        if(root == NULL) {
            pair<int, bool> p;
            p.first = 0;
            p.second = true;
            return p;
        }

        pair<int, bool> lp = balancedHelper(root->left);
        pair<int, bool> rp = balancedHelper(root->right);

        int height = max(lp.first, rp.first) + 1;

        bool isbalance = (abs(lp.first - rp.first) <= 1) && (lp.second && rp.second);

        return make_pair(height, isbalance);
    }

    bool isBalanced(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        pair<int, bool> ans = balancedHelper(root);
        return ans.second;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
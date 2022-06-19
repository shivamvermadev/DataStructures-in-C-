#include <bits/stdc++.h>
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
    int bal = true;
    int balancedHelper(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = balancedHelper(root->left);
        int rh = balancedHelper(root->right);
        int gap = abs(lh - rh);

        if (gap > 1)
        {
            bal = false;
        }

        int totalHeight = max(lh, rh) + 1;
        return totalHeight;
    }

    bool isBalanced(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        balancedHelper(root);
        return bal;
        //  Your Code here
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
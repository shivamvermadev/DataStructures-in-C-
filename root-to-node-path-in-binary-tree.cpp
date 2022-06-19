#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

bool find(TreeNode *root, TreeNode *target, vector<TreeNode *> &v)
{
    if (root == NULL)
    {
        return false;
    }

    if (root == target)
    {
        v.push_back(target);
        return true;
    }

    bool findInLeft = find(root->left, target, v);
    if (findInLeft)
    {
        v.push_back(root);
        return true;
    }

    bool findInRight = find(root->right, target, v);
    if (findInRight)
    {
        v.push_back(root);
        return true;
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
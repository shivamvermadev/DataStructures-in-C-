#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int val;
    Node *left;
    Node *right;
};

vector<int> inorderTraversal(Node *cur)
{
    vector<int> v;
    stack<Node *> s;
    while (true)
    {
        if (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            if (s.empty() == true)
            {
                break;
            }

            Node *top = s.top();
            s.pop();

            v.push_back(top->val);
            if (top->right)
            {
                cur = top->right;
            }
        }
    }

    return v;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Node *root = NULL;
    inorderTraversal(root);

    return 0;
}
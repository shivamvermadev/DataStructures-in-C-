#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    stack<Node *> s1, s2;

    s1.push(root);

    while (s1.empty() == false || s2.empty() == false)
    {
        while (s1.empty() == false)
        {
            Node *top = s1.top();
            v.push_back(top->data);

            s1.pop();
            if (top->right)
            {
                s2.push(top->right);
            }
            if (top->left)
            {
                s2.push(top->left);
            }
        }

        while (s2.empty() == false)
        {
            Node *top = s2.top();
            v.push_back(top->data);

            s2.pop();
            if (top->left)
            {
                s1.push(top->left);
            }
            if (top->right)
            {
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
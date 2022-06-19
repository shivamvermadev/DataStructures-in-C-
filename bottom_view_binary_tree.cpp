#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> bottomView(Node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push(make_pair(root, 0));

    while (q.empty() == false)
    {
        pair<Node *, int> p = q.front();
        q.pop();

        Node *temp = p.first;
        int level = p.second;

        m[level] = temp->data;
        if (temp->left)
        {
            q.push(make_pair(temp->left, level - 1));
        }
        if (temp->right)
        {
            q.push(make_pair(temp->right, level + 1));
        }
    }

    for (auto i : m)
    {
        v.push_back(i.second);
    }
    return v;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    return 0;
}
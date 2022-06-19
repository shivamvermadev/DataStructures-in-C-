#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node *left, *right;
};

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL || r2 == NULL) {
            return false;
        }
        
        bool ans = (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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
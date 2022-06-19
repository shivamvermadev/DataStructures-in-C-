#include<bits/stdc++.h>
using namespace std;
#define int long long int


class Solution {
public:
    int longestValidParenthesesWithTwoStack(string &s) {
        stack<char> sc;
        stack<int> si;
        
        si.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();++i) {
            if(s[i] == '(') {
                sc.push('(');
                si.push(i);
            }
            else if(s[i] == ')' && sc.empty() == false) {
                sc.pop();
                si.pop();
                ans = max(ans, i - si.top());
            }
            else if(s[i] == ')') {
                si.push(i);
            }
        }
        return ans;
    }

    int longestValidParenthesesWithOneStack(string &s) {
        
        stack<int> si;
        
        si.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();++i) {
            if(s[i] == '(') {
                si.push(i);
            }
            else {
                si.pop();
                if(si.empty() == true) {
                    si.push(i);
                }
                else {
                    ans = max(ans, i - si.top());
                }
            }
        }
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
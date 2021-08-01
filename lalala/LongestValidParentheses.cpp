#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)  //cross-border visit, to be fixed, but was accepted anyway
    {
        int n = s.length();
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '(')
                dp[i] = 0;
            else if (s[i - 1] == '(')
                dp[i] = dp[i - 2] + 2;
            else if (s[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main()
{
    string a = "()";
    cout << ((Solution *)NULL)->longestValidParentheses(a) << endl;
}
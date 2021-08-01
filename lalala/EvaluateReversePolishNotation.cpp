#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int opt1 = st.top();
                st.pop();
                int opt2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    int ans = opt1 + opt2;
                    st.push(ans);
                }
                else if (tokens[i] == "-")
                {
                    int ans = opt2 - opt1;
                    st.push(ans);
                }
                else if (tokens[i] == "*")
                {
                    int ans = opt1 * opt2;
                    st.push(ans);
                }
                else
                {
                    int ans = opt2 / opt1;
                    st.push(ans);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
int main()
{
    vector<string> s = {"2", "1", "+", "3", "*"};
    cout << ((Solution *)NULL)->evalRPN(s) << endl;
}
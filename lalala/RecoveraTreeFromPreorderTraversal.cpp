/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *recoverFromPreorder(string s)
    {
        stack<TreeNode*> st;
        int pos=0,depth=0;
        while(pos<s.size())
        {
            depth=0;
            while(s[pos]!='\0'&&s[pos]=='-')
            {
                pos++;
                depth++;
            }
            int v;
            while(pos<s.size()&&isdigit(s[pos]))
            {
                v=v*10+(s[pos]-'0');
                pos++;
            }
            TreeNode *t=new TreeNode(v);
            if(depth==st.size())
            {
                if(!st.empty())
                {
                    st.top()->left=t;
                }
            }
            else
            {
                while(st.size()!=depth)
                {
                    st.pop();
                }
                st.top()->right=t;
            }
            st.push(t);
        }
        while(st.size()>1)
        {
            st.pop();
        }
        return st.top();
    }
};
int main()
{
    
}
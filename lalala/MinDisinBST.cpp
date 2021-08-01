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
    vector<int> ans;

public:
    void mido(TreeNode *root)
    {
        if (root->left != nullptr)
            mido(root->left);
        ans.push_back(root->val);
        if (root->right != nullptr)
            mido(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        mido(root);
        int res = 0x7fffffff;

        for (int i = 1; i < ans.size(); i++)
            res = min(res, ans[i] - ans[i - 1]);
        return res;
    }
};
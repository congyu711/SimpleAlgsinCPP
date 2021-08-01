#include <bits/stdc++.h>
using namespace std;
class tree
{
public:
    int val;
    tree *left, *right;
    tree() : val(0), left(nullptr), right(nullptr){};
};
class Solution2
{
public:
    void flatten(tree *root)
    {
        tree *p = root;
        while(p!=nullptr)
        {
            if(p->left!=nullptr)
            {
                tree *pp=p->left;
                while(pp->right!=nullptr)
                {
                    pp=pp->right;
                }
                pp->right=p->right;
                p->right=pp;
                p->left=nullptr;
            }
            p=p->right;
        }
    }
};
class Solution3
{
public:
    //encodeing uft-8
    /*  left=nullptr,节点用right指针形成和先序遍历顺序一样的链表
    关于如何思考复杂递归算法的一点个人想法
    1退出条件
    2当前做什么
    3递归顺序
    
    1当然是nullptr返回
    2当递归到某个子树的时候,想要把他下面的节点都变成先序遍历顺序然后插好
    这就要先递归后操作，保证子节点都是完成flatten的
    并且保存一下根节点,到上一层可以直接连接到根节点上
    3对于每一次调用flatten(tree *root),要做到把
                root
                /   \
            left    right
    变成 root - left - right
    因此 先把右子树的根节点连接到左子树先序遍历最后一个节点
        再把左子树的根节点连接到root的right指针上
    用last记住右子树的根节点,然后递归flatten到左子树的最后一个节点, root->right=last,
    完成left->right部分.

*/
    tree *last = nullptr;
    void flatten(tree *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = last;
        last = root;
    }
};
class Solution1
{
public:
    void flatten(TreeNode *root)
    {
        auto v = vector<TreeNode *>();
        auto stk = stack<TreeNode *>();
        TreeNode *node = root;
        while (node != nullptr || !stk.empty())
        {
            while (node != nullptr)
            {
                v.push_back(node);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        int size = v.size();
        for (int i = 1; i < size; i++)
        {
            auto prev = v.at(i - 1), curr = v.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }
};
int main()
{
}
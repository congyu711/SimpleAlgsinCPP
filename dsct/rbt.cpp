#include <bits/stdc++.h>
#include <fstream>
const bool RED = true;
const bool BLACK = false;
using namespace std;
using namespace chrono;
class bst
{
public:
    int val, key;
    bst *lson, *rson;
    int sz;
    bool clr;
    bst(int k, int v, int n, bool color) : key(k), val(v), sz(n), clr(color)
    {
        lson = nullptr;
        rson = nullptr;
    }
};
bst *binarysearchtree;

int vec_left[100] = {0};
void Display(const bst *root, int ident = 0)
{
    if (ident > 0)
    {
        for (int i = 0; i < ident - 1; ++i)
        {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident - 1] ? "├── " : "└── ");
    }

    if (!root)
    {
        printf("(null)\n");
        return;
    }

    printf("%d\n", root->key);
    if (!root->lson && !root->rson)
    {
        return;
    }

    vec_left[ident] = 1;
    Display(root->lson, ident + 1);
    vec_left[ident] = 0;
    Display(root->rson, ident + 1);
}
int getsz(bst *root)
{
    if (root == nullptr)
        return 0;
    return root->sz;
}
bst *rotateLeft(bst *h)
{
    bst *x = h->rson;
    if (h == binarysearchtree)
        binarysearchtree = x;
    h->rson = x->lson;
    x->lson = h;
    x->clr = h->clr;
    h->clr = RED;
    x->sz = h->sz;
    h->sz = getsz(h->lson) + getsz(h->rson) + 1;
    return x;
}
bst *rotateRight(bst *h)
{
    bst *x = h->lson; //x can't be nullptr
    if (h == binarysearchtree)
        binarysearchtree = x;
    h->lson = x->rson;
    x->rson = h;
    x->clr = h->clr;
    h->clr = RED;
    x->sz = h->sz;
    h->sz = getsz(h->lson) + getsz(h->rson) + 1;
    return x;
}
void flipcolor(bst *root)
{
    //if root is a 4-node, its l/rson can't be null
    root->clr = RED;
    // if (root->lson!=nullptr)
    root->lson->clr = BLACK;
    // if (root->rson!=nullptr)
    root->rson->clr = BLACK;
}
void delflipcolor(bst *root)
{
    root->clr = BLACK;
    root->lson->clr = RED;
    root->rson->clr = RED;
}
bool isred(bst *h)
{
    if (h == nullptr)
        return false;
    return h->clr == RED;
}
int getval(bst *root, int key)
{
    if (root == nullptr)
        return -1; //doesn't exist
    else if (key == root->key)
        return root->val;
    else if (key > root->key)
        return getval(root->rson, key);
    else
        return getval(root->lson, key);
}
//find node a with key==_key, and if val!=_val,update it,
//  if a doesn't exist, create a new node
bst *_put(bst *root, int _key, int _val)
{
    if (root == nullptr)
        return new bst(_key, _val, 1, RED);
    if (root->key > _key)
        root->lson = _put(root->lson, _key, _val);
    else if (root->key < _key)
        root->rson = _put(root->rson, _key, _val);
    else
        root->val = _val;
    if (isred(root->rson) && !isred(root->lson))
        root = rotateLeft(root);
    //use Short-circuit operator(if root->lson==nullptr or root->lson->lson==nullptr)
    if (isred(root->lson) && isred(root->lson->lson))
        root = rotateRight(root);
    if (isred(root->lson) && isred(root->rson))
        flipcolor(root);
    //root->sz=root->lson->sz+root->rson->sz+1;
    root->sz = getsz(root->lson) + getsz(root->rson) + 1;
    return root;
}
void put(bst *root, int _key, int _val)
{
    root = _put(root, _key, _val);
    root->clr = BLACK;
}
bst *balance(bst *root)
{
    if (isred(root->rson))
        root = rotateLeft(root);
    if (isred(root->rson) && !isred(root->lson))
        root = rotateLeft(root);
    if (isred(root->lson) && isred(root->lson->lson))
        root = rotateRight(root);
    if (isred(root->lson) && isred(root->rson))
        flipcolor(root);
    root->sz = getsz(root->lson) + getsz(root->rson) + 1;
    return root;
}
//suppose h.clr is red and clr of h.sons are black
//we need to change one of h.sons.clr red
bst *delmin_moveRedLeft(bst *h)
{
    delflipcolor(h);
    if (isred(h->rson->lson))
    {
        h->rson = rotateRight(h->rson);
        h = rotateLeft(h);
    }
    return h;
}
bst *delmin(bst *h)
{
    if (h->lson == nullptr)
        return nullptr;
    if (!isred(h->lson) && !isred(h->lson->lson))
        h = delmin_moveRedLeft(h);
    h->lson = delmin(h->lson);
    return balance(h);
}
void delmin()
{
    if (!isred(binarysearchtree->lson) && !isred(binarysearchtree->rson))
        binarysearchtree->clr = RED;
    binarysearchtree = delmin(binarysearchtree);
    if (binarysearchtree->lson != nullptr && binarysearchtree->rson != nullptr)
        binarysearchtree->clr = BLACK;
}
//delmax need to find nodes in right sub-tree
bst *delmax_moveRedLeft(bst *h)
{
    delflipcolor(h);
    if (!isred(h->lson->lson))
        h = rotateRight(h);
    return h;
}
bst *delmax(bst *h)
{
    if (isred(h->lson))
        h = rotateRight(h);
    if (h->rson == nullptr)
        return nullptr;
    if (!isred(h->rson) && !isred(h->rson->lson))
        h = delmax_moveRedLeft(h);
    h->rson=delmax(h->rson);
    return balance(h);
}
void delmax()
{
    if (!isred(binarysearchtree->lson) && !isred(binarysearchtree->rson))
        binarysearchtree->clr = RED;
    binarysearchtree = delmax(binarysearchtree);
    if (binarysearchtree->lson != nullptr && binarysearchtree->rson != nullptr)
        binarysearchtree->clr = BLACK;
}
bst *bstmin(bst *root) //return pointer
{
    if (root->lson == nullptr)
        return root;
    return bstmin(root->lson);
}
int bstminKey(bst *root)
{
    return bstmin(root)->key;
}
bst *bstfloor(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->key == _key)
        return root;
    else if (root->key > _key)
        return bstfloor(root->lson, _key);
    else
    {
        bst *t = bstfloor(root->rson, _key);
        if (t == nullptr)
            return root;
        else
            return t;
    }
}
bst *bstceil(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->key == _key)
        return root;
    else if (root->key < _key)
        return bstceil(root->rson, _key);
    else
    {
        bst *t = bstceil(root->lson, _key);
        if (t == nullptr)
            return root;
        else
            return t;
    }
}
//notice! rank of the smallest num is 0
bst *bstselect(bst *root, int k)
{
    if (root == nullptr)
        return nullptr;
    int t = root->lson == 0 ? 0 : root->lson->sz;
    if (t > k)
        return bstselect(root->lson, k);
    else if (t < k)
        return bstselect(root->rson, k - t - 1);
    else
        return root;
}
int bstrank(int _key, bst *root)
{
    if (root == nullptr)
        return 0;
    else if (root->key > _key)
        return bstrank(_key, root->lson);
    else if (root->key < _key)
    {
        int lsz = root->lson == nullptr ? 0 : root->lson->sz;
        return lsz + 1 + bstrank(_key, root->rson);
    }
    else
    {
        int lsz = root->lson == nullptr ? 0 : root->lson->sz;
        return lsz;
    }
}
// bst *bstdelmin(bst *root)
// {
//     if (root->lson == nullptr)
//         return root->rson;
//     root->lson = bstdelmin(root->lson);
//     root->sz = getsz(root->lson) + getsz(root->rson) + 1;
//     return root;
// }
// bst *bstdel(bst *root, int _key)
// {
//     if (root == nullptr)
//         return nullptr;
//     if (root->key > _key)
//         root->lson = bstdel(root->lson, _key);
//     else if (root->key < _key)
//         root->rson = bstdel(root->rson, _key);
//     else
//     {
//         if (root->lson == nullptr)
//             return root->rson;
//         if (root->rson == nullptr)
//             return root->lson;
//         bst *t = root;
//         root = bstmin(root->rson);
//         root->rson = bstdelmin(t->rson);
//         root->lson = t->lson;
//     }
//     root->sz = getsz(root->lson) + getsz(root->rson) + 1;
//     return root;
// }
void midorderprint(bst *root = binarysearchtree)
{
    if (root == nullptr)
        return;
    midorderprint(root->lson);
    cout << root->key << ' ' << root->sz << endl;
    midorderprint(root->rson);
}
//find nodes(lo<=key<=hi) and put them into res.
void keys(bst *root, int lo, int hi, queue<bst *> &res)
{
    if (root == nullptr)
        return;
    if (lo < root->key)
        keys(root->lson, lo, hi, res);
    if (root->key >= lo && root->key <= hi)
        res.push(root);
    if (hi > root->key)
        keys(root->rson, lo, hi, res);
}


int main()
{
    mt19937 gen(time(nullptr));
    auto start=system_clock::now();

    const int N=4e4;
    binarysearchtree = new bst(1,1,1,RED);
    for (int i = 2; i <= N; i++)
    {
        put(binarysearchtree,i,1);
    }
    auto end=system_clock::now();
    auto d = duration_cast<microseconds>(end - start);
    cout << "build bst: " << double(d.count()) * microseconds::period::num / microseconds::period::den << endl;
    // Display(binarysearchtree);
}
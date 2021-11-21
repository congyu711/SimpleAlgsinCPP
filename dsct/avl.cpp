#include <bits/stdc++.h>
#include <fstream>
using namespace std;
using namespace chrono;
class bst
{
public:
    int val, key;
    bst *lson, *rson;
    int sz,h,cnt;
    bst() : val(0), key(0), sz(0)
    {
        lson = nullptr;
        rson = nullptr;
        h=1;
        cnt=1;
    }
    bst(int v, int k) : val(v), key(k), sz(0)
    {
        lson = nullptr;
        rson = nullptr;
        h=cnt=1;
    }
    bst(int k, int v, int n) : key(k), val(v), sz(n)
    {
        lson = nullptr;
        rson = nullptr;
        h=cnt=1;
    }
};
void update(bst *root)
{
    int lsz = root->lson == nullptr ? 0 : root->lson->sz;
    int rsz = root->rson == nullptr ? 0 : root->rson->sz;
    int lh=root->lson==nullptr?0:root->lson->h;
    int rh=root->rson==nullptr?0:root->rson->h;
    root->sz=lsz+rsz+root->cnt;
    root->h=max(lh,rh)+1;
}
int geth(bst *h)
{
    return h==nullptr?0:h->h;
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
bst *rotateL(bst *h)
{
    bst *ls=h->lson,*rs=h->rson;
    h->rson=rs->lson;
    rs->lson=h;
    update(h);
    update(rs);
    return rs;
}
bst *rotateR(bst *h)
{
    bst *ls=h->lson,*rs=h->rson;
    h->lson=ls->rson;
    ls->rson=h;
    update(h);
    update(ls);
    return ls;
}


//find node a with key==_key, and if val!=_val,update it,
//  if a doesn't exist, create a new node
bst *put(bst *root, int _key, int _val)
{
    if (root == nullptr)
        return new bst(_key, _val, 1);
    if (root->key > _key)
        root->lson = put(root->lson, _key, _val);
    else if (root->key < _key)
        root->rson = put(root->rson, _key, _val);
    else
        root->val = _val;
    update(root);
    if(geth(root->lson)-geth(root->rson)>1)
    {
        auto e=root->lson;
        if(geth(e->lson)>=geth(e->rson))
        {
            root=rotateR(root);
        }
        else
        {
            e=rotateL(e);
            root=rotateR(root);
        }
    }
    else if(geth(root->rson)-geth(root->lson)>1)
    {
        auto e=root->rson;
        if(geth(e->rson)>=geth(e->lson))
        {
            root=rotateL(root);
        }
        else
        {
            e=rotateR(e);
            root=rotateL(root);
        }
    }
    return root;
}
bst *bstmin(bst *root) //return pointer
{
    if (root->lson == nullptr)
        return root;
    return bstmin(root->lson);
}
int bstminkey(bst *root)
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
bst *bstdelmin(bst *root)
{
    if (root->lson == nullptr)
        return root->rson;
    root->lson = bstdelmin(root->lson);
    update(root);
    return root;
}
bst *bstdel(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    if (root->key > _key)
        root->lson = bstdel(root->lson, _key);
    else if (root->key < _key)
        root->rson = bstdel(root->rson, _key);
    else
    {
        if (root->lson == nullptr)
            return root->rson;
        if (root->rson == nullptr)
            return root->lson;
        bst *t = root;
        root = bstmin(root->rson);
        root->rson = bstdelmin(t->rson);
        root->lson = t->lson;
    }
    update(root);
    return root;
}
void midorderprint(bst *root)
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

int vec_left[100] = {0};
void Display(bst *root, int ident)
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
int main()
{
    mt19937 gen(time(nullptr));
    auto start=system_clock::now();

    const int N=10;
    bst *binarysearchtree = new bst(1, 1);
    for (int i = 2; i <= N; i++)
    {
        binarysearchtree=put(binarysearchtree,i,i);
        Display(binarysearchtree,0);
    }
    auto end=system_clock::now();
    auto d = duration_cast<microseconds>(end - start);
    cout << "build bst: " << double(d.count()) * microseconds::period::num / microseconds::period::den << endl;
    
}
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
class node
{
public:
    int v, sz, cnt;
    node *ls, *rs;
    node(int _v, int _sz, int _cnt) : v(_v), sz(_sz), cnt(_cnt)
    {
        ls = rs = nullptr;
    }
};

node *bstroot;
void updatesz(node *h)
{
    int lsz = h->ls == nullptr ? 0 : h->ls->sz, rsz = h->rs == nullptr ? 0 : h->rs->sz;
    h->sz = h->cnt + lsz + rsz;
}
node *findv(node *h, int v)
{
    if (h == nullptr)
        return nullptr; //doesn't exist
    if (v == h->v)
        return h;
    else if (v > h->v)
        return findv(h->rs, v);
    else
        return findv(h->ls, v);
}
node *put(node *h, int v)
{
    if (h == nullptr)
        return new node(v, 1, 1);
    else if (h->v == v)
    {
        h->cnt++;
        return h;
    }
    else if (h->v > v)
        h->ls = put(h->ls, v);
    else if (h->v < v)
        h->rs = put(h->rs, v);
    updatesz(h);
    return h;
}
void midorderprint(node *h)
{
    if (h == nullptr)
        return;
    midorderprint(h->ls);
    for (int i = 0; i < h->cnt; i++)
        cout << h->v << ' ';
    midorderprint(h->rs);
}

int vec_left[100] = {0};
void Display(node *h, int ident)
{
    if (ident > 0)
    {
        for (int i = 0; i < ident - 1; ++i)
        {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident - 1] ? "├── " : "└── ");
    }

    if (!h)
    {
        printf("(null)\n");
        return;
    }

    printf("%d\n", h->v);
    if (!h->ls && !h->rs)
    {
        return;
    }

    vec_left[ident] = 1;
    Display(h->ls, ident + 1);
    vec_left[ident] = 0;
    Display(h->rs, ident + 1);
}
int main()
{
    auto start = system_clock::now();
    mt19937 gen(time(nullptr));
    const int N = 1e7;
    for (int i = 1; i <= N; i++)
    {
        auto e = gen() % 2333;
        // auto e=i;
        bstroot = put(bstroot, e);
    }
    auto end1 = system_clock::now();
    auto d = duration_cast<microseconds>(end1 - start);
    cout << "build bst: " << double(d.count()) * microseconds::period::num / microseconds::period::den << endl;
    for (int i = 1; i <= N; i++)
    {
        findv(bstroot, i);
    }
    auto end2 = system_clock::now();
    d = duration_cast<microseconds>(end2 - end1);
    cout << "random search: " << double(d.count()) * microseconds::period::num / microseconds::period::den << endl;
    // Display(bstroot,0);
}
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int inline read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int son[N][2], key[N], prt[N]; //儿子，值，随机的优先级;
int sz[N], cnt;
int add(int x)
{
    sz[++cnt] = 1;
    key[cnt] = x;
    prt[cnt] = rand();
    return cnt;
}
int merge(int x, int y)
{
    if(x==0)    return y;
    if(y==0)    return x;
    if (prt[x] < prt[y])
    {
        son[x][1] = merge(son[x][1], y);
        sz[x] = 1 + sz[son[x][0]] + sz[son[x][1]];
        return x;
    }
    else
    {
        son[y][0] = merge(x, son[y][0]);
        sz[y] = 1 + sz[son[y][0]] + sz[son[y][1]];
        return y;
    }
}
void split(int h, int k, int &x, int &y) //h为当前节点,k-key,x<=key,y>k
{
    if (!h)
        x = y = 0;
    else
    {
        if (key[h] <= k)
        {
            x = h;
            split(son[h][1], k, son[h][1], y);
        }
        else
        {
            y = h;
            split(son[h][0], k, x, son[h][0]);
        }
        sz[h] = sz[son[h][1]] + 1 + sz[son[h][0]];
    }
}
int _rank(int h, int k) //第k位
{
    if (k == sz[son[h][0]] + 1)    return h;
    if(k<=sz[son[h][0]])    return _rank(son[h][0],k);
    else    return _rank(son[h][1],k-sz[son[h][0]]-1);
}
int main()
{
    srand(time(NULL));
    int n;
    n = read();
    int root = 0;
    int x , y, z = 0;
    for (int i = 1; i <= n; i++)
    {
        int q, xx;
        q = read(), xx = read();
        if (q == 1)
        {
            split(root, xx, x, y);
            root = merge(merge(x, add(xx)), y);
        }
        if (q == 2)
        {
            split(root, xx, x, z);
            split(x, xx - 1, x, y);
            y = merge(son[y][0], son[y][1]);
            root = merge(merge(x, y), z);
        }
        if (q == 3)
        {
            split(root, xx - 1, x, y);
            printf("%d\n", sz[x] );
            root = merge(x, y);
        }
        if (q == 4)
        {
            printf("%d\n", key[_rank(root, xx)]);
        }
        if (q == 5)
        {
            split(root, xx, x, y);
            printf("%d\n", key[_rank(y, 1)]);
            root = merge(x, y);
        }
    }
}
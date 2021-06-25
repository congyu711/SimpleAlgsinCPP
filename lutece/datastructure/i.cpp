#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
const LL N = 2e5 + 10;
LL x[N << 1];
struct lines
{
    LL l, r, h, c; //左端点，右端点，高度坐标,c上边为-1，下边为1
} line[N << 1];
bool cmp(lines &a, lines &b)
{
    return a.h < b.h;
}
//segment tree
class node
{
public:
    LL l, r, sum, len, sumodd, lenodd;
};
node z[N << 2];

void update(LL rt)
{
    if (z[rt].sum)
        z[rt].len = x[z[rt].r + 1] - x[z[rt].l];
    else if (z[rt].r == z[rt].l)
        z[rt].len = 0;
    else
        z[rt].len = z[rt << 1].len + z[rt << 1 | 1].len;
}
void pushdown(int rt)
{
    if (z[rt].sumodd && z[rt].l != z[rt].r)
    {
        z[rt << 1].sumodd ^= 1, z[rt << 1 | 1].sumodd ^= 1;
        z[rt << 1].lenodd = x[z[rt << 1].r + 1] - x[z[rt << 1].l] - z[rt << 1].lenodd;
        z[rt << 1 | 1].lenodd = x[z[rt << 1 | 1].r + 1] - x[z[rt << 1 | 1].l] - z[rt << 1 | 1].lenodd;
        z[rt].sumodd = 0;
    }
}
void build(LL l, LL r, LL rt)
{
    z[rt].l = l, z[rt].r = r;
    z[rt].len = z[rt].lenodd = z[rt].sumodd = z[rt].sum = 0;
    if (l == r)
        return;
    LL mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    update(rt);
}
void modify(LL ml, LL mr, LL rt, LL v)
{
    LL _l = z[rt].l, _r = z[rt].r + 1;
    if (x[_l] >= mr || x[_r] <= ml)
        return;
    if (ml <= x[_l] && x[_r] <= mr)
    {
        z[rt].sum += v;
        update(rt);
        z[rt].sumodd ^= 1;
        z[rt].lenodd = x[_r] - x[_l] - z[rt].lenodd;
        return;
    }
    pushdown(rt);
    modify(ml, mr, rt << 1, v);
    modify(ml, mr, rt << 1 | 1, v);
    update(rt);
    z[rt].lenodd = z[rt << 1].lenodd + z[rt << 1 | 1].lenodd;
}

//end segtree
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    LL a, b, c, d;
    for (LL i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        x[i * 2 - 1] = min(a, c), x[i * 2] = max(a, c);
        line[i * 2 - 1].l = min(a, c), line[i * 2 - 1].r = max(a, c), line[i * 2 - 1].h = min(b, d), line[i * 2 - 1].c = 1;
        line[i * 2].l = min(a, c), line[i * 2].r = max(a, c), line[i * 2].h = max(b, d), line[i * 2].c = -1;
    }
    n <<= 1;                           //因为x和line都是每次插入两个元素，直接把n*2比较方便
    sort(line + 1, line + n + 1, cmp); //把所有矩形的边按照高度排序
    sort(x + 1, x + n + 1);
    LL len = unique(x + 1, x + n + 1) - x - 1;
    build(1, len - 1, 1);
    LL ans = 0;
    for (LL i = 1; i < n; i++) //第i条边和第i+1条边形成区间，最后一条不用考虑了
    {
        modify(line[i].l, line[i].r, 1, line[i].c);
        // for (int i = 1; i <= 10; i++)
        // {
        //     cout << x[z[i].l] << x[z[i].r + 1] << "---" << z[i].sumodd << ' ' << z[i].lenodd << endl;
        // }
        // cout << endl;
        ans += 1LL * (line[i + 1].h - line[i].h) * z[1].len;
        ans -= 1LL * (line[i + 1].h - line[i].h) * z[1].lenodd;
    }
    cout << ans << endl;
}
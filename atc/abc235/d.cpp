#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
typedef long long LL;
const LL inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
LL n, m;
LL a;
queue<LL> q;
LL dis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> n;
    m = pow(10, (LL)log10(n) + 1) - 1;
    q.push(1);
    while (q.size())
    {
        LL u = q.front();
        q.pop();
        if (u > 10 && (u % 10 != 0))
        {
            LL d = log10(u);
            LL b = u % 10;
            LL c = u / 10;
            LL v = pow(10, d) * b + c;
            // cout << "asdf" << u << ' ' << v << endl;
            if (dis[v] == 0 && v <= m)
            {
                dis[v] = dis[u] + 1;
                if (v == n)
                {
                    cout << dis[v] << endl;
                    return 0;
                }
                q.push(v);
            }
        }
        LL v = u * a;
        if (v <= m && dis[v] == 0)
        {
            dis[v] = dis[u] + 1;
            if (v == n)
            {
                cout << dis[v] << endl;
                return 0;
            }
            q.push(v);
        }
    }
    cout << -1 << endl;
}
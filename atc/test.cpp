#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vl vector<long long>
#define vpl vector<pair<long long, long long>>
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
template <typename T>
void printVector(const T &t)
{
    if (t.size() > 0)
        cout << t[0];
    else
    {
        cout << "\n";
        return;
    }
    fore(i, 1, t.size())
    {
        cout << " " << t[i];
    }
    cout << "\n";
}
using ll = long long;
const int mode = 0;

// MST is a matroid problem. It is greedy. We can always add any/all edges of
// the cheapest flavor until they help no more, then we move on. Since
// everything is cyclic, things work out nicely. We must add n-1 edges
// guaranteed. When we can add some edges, they reduce everything by some clean
// factor.

struct edge
{
    int diff;
    ll cost;
    void read()
    {
        cin >> diff >> cost;
    }
};

bool cmp(edge &a, edge &b)
{
    return a.cost < b.cost;
}

ll gcd(ll a, ll b)
{
    while (b)
    {
        // a, b = b, a % b;
        ll tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<edge> E(m);
    fore(i, 0, m) E[i].read();
    sort(E.begin(), E.end(), cmp);

    ll totalcost = 0;
    for (auto e : E)
    {
        ll x = (e.diff) % n;
        if (x == 0)
            continue;
        ll g = gcd(n, x);
        ll cyclesize = n / g;
        totalcost += e.cost * g * (cyclesize - 1);
        n = g;
        if (n == 1)
            break;
    }

    if (n > 1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << totalcost << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;

    if (mode == 0)
    {
        solve();
    }
    else
    {
        cin >> t;
        while (t--)
        {
            solve();
        }
    }
}

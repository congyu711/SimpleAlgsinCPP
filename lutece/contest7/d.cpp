#include <bits/stdc++.h>
using namespace std;
const int N = 555;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,m,a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].pop_back(b);
    }
    for(int i=1;i<=n;i++)
    {

    }
}
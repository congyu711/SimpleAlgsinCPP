#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n,m;
pair<LL,LL> e[N];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>e[i].second>>e[i].first;
    sort(e+1,e+m+1);
    
}
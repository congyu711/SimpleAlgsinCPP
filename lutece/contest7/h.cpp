#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int a[N];
vector<pair<int,int> > adj[N];
int a,b;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(make_pair(i+1,b));   
    }
    
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
LL n,m;
map<int,vector<int> > mp;
int a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        mp[a].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(mp[a].size()<b)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<mp[a][b-1]<<endl;
    }
}
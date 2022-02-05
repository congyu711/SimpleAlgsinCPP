#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
pair<int,int> c[1<<17];
bool f[1<<17];
LL ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    n=(1<<n)-1;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i].first;
        c[i].second=i;
    }
    sort(c+1,c+n+1);
    // for(int i=1;i<=n;i++)   cout<<c[i].first<<' '<<c[i].second<<endl;
    for(int i=1;i<=n;i++)
    {
        int u=c[i].second;
        if(!f[u])
        {
            // cout<<"!f[u]   "<<c[i].first<<' '<<u<<endl;
            f[u]=1;
            ans+=c[i].first;
            for(int j=1;j<=n;j++)
            {
                if(!f[c[j].second]||j==i)   continue;
                f[c[j].second^u]=1;
            }
        }
    }
    cout<<ans<<endl;
}
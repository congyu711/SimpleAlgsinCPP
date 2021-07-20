#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
int n,m;
int a[111][111];
    bool ck[111];
vector<int> cl[111];
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    int idx=0;
    for(int k=1;k<n;k++)
    {
        vector<pair<int,int> > tmp;
        for(int i=1;i<=m;i++)
            tmp.push_back(make_pair(a[i][k]-a[i][n],i));
        sort(tmp.begin(),tmp.end(),cmp);
        
        int sumn=0,sum=0;
        int res=m;
        for(int i=0;i<m;i++)
        {
            int c=tmp[i].second;
            sumn+=a[c][n];
            sum+=a[c][k];
            cl[k].push_back(c);
            // cout<<sumn<<' '<<sum<<endl;
            if(sumn>sum)
            {
                res=i;
                cl[k].pop_back(); break;
            }
        }
        if(res>ans)
        {
            idx=k;
            ans=res;
        }
        // ans=max(ans,res);
        // cout<<k<<' '<<res<<endl;
    }
    cout<<m-ans<<endl;

    for(auto e:cl[idx]) ck[e]=1;
    for(int i=1;i<=m;i++)   if(!ck[i])  cout<<i<<' ';
    cout<<endl;
}
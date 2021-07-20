#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
const LL inf = 1e9;
const int mod = 1e9 + 7;
int n;
int cnt;
vector<int> f,g;
bool check(int mid)
{
    cnt++;
    cout<<"> "<<mid<<endl;
    cout.flush();
    int c;
    cin>>c;
    return c;
}
bool vis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(nullptr));
    cin>>n;
    int l=0,r=inf,mid;
    while(l+1<r) 
    {
        mid=l+r>>1;
        if(check(mid))
            l=mid;
        else    r=mid;
    }
    int maxx=l+1;
    g.push_back(maxx);
    int c;
    for(int i=1;i<=min(n,59-cnt);i++)
    {
        int t=rand()%n+1;
        while(vis[t])
        {
            t=rand()%n+1;
        }
        vis[t]=1;
        cout<<"? "<<t<<endl;
        cout.flush();
        cin>>c;
        g.push_back(c);
        
    }
    sort(g.begin(),g.end());
    for(int i=0;i<g.size();i++)
    {
        for(int j=i+1;j<g.size();j++)
        {
            f.push_back(g[j]-g[i]);
        }
    }
    int d=0;
    for(auto e:f)
    {
        if(e!=0)
        {
            d=__gcd(d,e);
        }
    }
    // cout<<maxx<<endl;
    // for(auto e:f)   cout<<e<<' ';cout<<endl;
    cout<<'!'<<' ';
    cout<<maxx-(n-1)*d<<' ';
    cout<<d<<endl;
}
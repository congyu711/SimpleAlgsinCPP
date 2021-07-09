#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=260;
char a[N][N];
int mp[N][26];
int n,m;
LL ans;
#ifdef CONGYU
    ifstream ccin("testcase.in");
#endif
bool equal(int i,int j)
{
    for(int k=0;k<26;k++)
        if(mp[i][k]!=mp[j][k])  return false;
    return true;
}
bool chk(int i)
{
    bool f=0;
    for(int k=0;k<26;k++)
    {
        if(mp[i][k]%2==1)
        {
            if(f==0)    f=1;
            else return false;
        }
    }
    return true;
}
void manacher(int L,int R)
{
    int n=R-L+1;
    vector<int> odd(n),even(n);
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int k=(i>r)?1:min(odd[l+r-i],r-i);
        while(i-k>=0&&i+k<n&&equal(i-k+L,i+k+L))    k++;
        odd[i]=k--;
        ans+=odd[i];
        if(i+k>r)
        {
            l=i-k;
            r=i+k;
        }
    }
    // for(auto e:odd) cout<<e<<' ';
    // cout<<endl;
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int k=(i>r)?0:min(even[l+r-i+1],r-i+1);
        while(i-k-1>=0&&i+k<n&&equal(i-k+L-1,i+k+L))    k++;
        even[i]=k--;
        ans+=even[i];
        if(i+k>r)
        {
            l=i-k-1;
            r=i+k;
        }
    }
    // for(auto e:even)    cout<<e<<' ';
    // cout<<endl; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    for(int l=1;l<=m;l++)
    {
        for(int r=l;r<=m;r++)
        {
            for(int i=1;i<=n;i++)
            {
                int t=a[i][r]-'a';
                mp[i][t]++;
            }
            vector<pair<int,int> > seg;
            for(int i=1;i<=n;i++)
            {
                if(!chk(i))  continue;
                else
                {
                    int j;
                    for(j=i+1;j<=n+1;j++)
                    {
                        if(j==(n+1)||(j<=n&&!chk(j)))
                            {seg.push_back(make_pair(i,j-1));break;}
                    }
                    i=j;
                }
            }
            // cout<<"qujian"<<l<<' '<<r<<endl;
            // for(auto e:seg) cout<<e.first<<' '<<e.second<<endl;
            // cout<<endl;
            for(auto e:seg)
            {
                manacher(e.first,e.second);
            }
        }
        memset(mp,0,sizeof(mp));
    }
    cout<<ans<<endl;
}
//01trie上的kruskal
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n;
int trie[N*30][2],tot;
void insert(int x)
{
    int rt=0;
    for(int i=30;i>=0;i--)
    {
        int xx=((x>>i)&1);
        if(trie[rt][xx]==0) trie[rt][xx]=++tot;
        rt=trie[rt][xx];
    }
}
LL edge(int l,int r,int dep)
{
    if(dep<0)   return 0LL;
    if(l==0||r==0)  return 0x7fffffffffffLL;
    if((trie[l][0]&&trie[r][0])||(trie[l][1]&&trie[r][1]))
        return min(edge(trie[l][0],trie[r][0],dep-1),edge(trie[l][1],trie[r][1],dep-1));
    else
        return min(edge(trie[l][0],trie[r][1],dep-1),edge(trie[l][1],trie[r][0],dep-1))+(1LL<<(dep));
}
LL solve(int rt,int dep)
{
    if(trie[rt][0]==0&&trie[rt][1]==0)  return 0LL;
    if(dep<0)   return 0LL;
    LL res=0;
    if(trie[rt][0]!=0)  res+=solve(trie[rt][0],dep-1);
    if(trie[rt][1]!=0)  res+=solve(trie[rt][1],dep-1);
    // LL res=solve(trie[rt][0],dep-1)+solve(trie[rt][1],dep-1);
    if(trie[rt][0]&&trie[rt][1])    res+=edge(trie[rt][0],trie[rt][1],dep-1)+(1LL<<(dep));
    // cout<<s<<"----"<<dep<<" "<<res<<endl;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++)   cin>>tmp,insert(tmp);
    cout<<solve(0,30)<<endl;
}
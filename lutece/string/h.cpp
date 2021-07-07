#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
string pat[N],txt;
int n;
int trie[N][26],tot;
int fail[N],ans[N];
int cnt[N];
vector<int> adj[N];
vector<int> endhere[N];
queue<int> q;
#ifdef CONGYU
    ifstream ccin("testcase.in");
#endif

void _insert(const string &str,int idx)
{
    int u=0;
    for(int i=0;i<str.length();i++)
    {
        if(!trie[u][str[i]-'a'])    trie[u][str[i]-'a']=++tot;
        u=trie[u][str[i]-'a'];
    }
    endhere[u].push_back(idx);
}
LL dfs(int u,int fa)
{
    LL res=0;
    res+=cnt[u];
    for(auto v:adj[u])
    {
        if(v==fa)   continue;
        res+=dfs(v,u);
    }
    if(endhere[u].size())
    {
        for(auto e:endhere[u])
            ans[e]+=res;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>pat[i];
    cin>>txt;
    for(int i=1;i<=n;i++)
        _insert(pat[i],i);
    for(int i=0;i<26;i++)
        if(trie[0][i]!=0)   q.push(trie[0][i]);
    while(!q.empty())
    {
        int tmp=q.front();q.pop();
        for(int i=0;i<26;i++)
        {
            if(trie[tmp][i]!=0) 
                fail[trie[tmp][i]]=trie[fail[tmp]][i],
                q.push(trie[tmp][i]);
            else    trie[tmp][i]=trie[fail[tmp]][i];
        }
    }
    for(int i=0;i<=tot;i++) {adj[fail[i]].push_back(i);}
    int u=0;
    for(int i=0;i<txt.length();i++)
    {
        u=trie[u][txt[i]-'a'];
        cnt[u]++;
    }
    dfs(0,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
}
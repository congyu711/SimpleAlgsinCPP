#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=3e5+10;
LL n;
LL trie[N*32][2],tot;
LL rcnt[32][2];
vector<LL> idx[N*30];
void insert(LL x,LL id)
{
    LL rt=0;
    for(LL i=31;i>=0;i--)
    {
        LL xx=((x>>i)&1);
        if(trie[rt][xx]==0) trie[rt][xx]=++tot;
        rt=trie[rt][xx];
        idx[rt].push_back(id);
    }
}

void precal(LL rt,LL d)
{
    if(trie[rt][0]) precal(trie[rt][0],d-1);
    if(trie[rt][1]) precal(trie[rt][1],d-1);
    if(!(trie[rt][0]&&trie[rt][1])) return;
    LL cnt=0,res=0;
    for(auto l:idx[trie[rt][0]])
    {
        while(cnt<idx[trie[rt][1]].size()&&idx[trie[rt][1]][cnt]<l)   cnt++;
        res+=cnt;
    }
    rcnt[d][0]+=res;
    rcnt[d][1]+=(1LL*idx[trie[rt][0]].size()*idx[trie[rt][1]].size());
    rcnt[d][1]-=res;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(LL i=1;i<=n;i++)
    {
        LL tmp;
        cin>>tmp;
        insert(tmp,i);
    }
    precal(0,31);
    LL x=0,ANS=0;
    for(LL i=31;i>=0;i--)
    {
        if(rcnt[i][0]>rcnt[i][1])
        {
            ANS+=rcnt[i][1];
            x+=(1LL<<i);
        }
        else
        {
            ANS+=rcnt[i][0];
        }
    }
    cout<<ANS<<' '<<x<<endl;
}
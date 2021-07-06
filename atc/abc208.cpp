#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6+10;
map<LL,LL> mp[20];
string n;
LL k;
LL dfs(int pos,LL fr,bool lim,bool l0)
{
    if(pos==-1)
    {
        if(fr>k)    return 0;
        else return 1;
    }
    if(!lim&&!l0&&mp[pos].count(fr))   return mp[pos][fr];

    if(!lim)
    {
        if(fr==0)
        {
            LL res=1;
            for(int i=0;i<=pos;i++) res*=10;
            return mp[pos][fr]=res;
        }
        if(fr>k)
        {
            LL res1=1,res2=1;
            for(int i=0;i<=pos;i++) res1*=10,res2*=9;
            return mp[pos][fr]=(res1-res2);
        }
    }
    LL res=0;
    int up=lim?(n[pos]-'0'):9;
    for(int i=0;i<=up;i++)
    {
        if(l0&(!i)) res+=dfs(pos-1,fr,lim&(i==(n[pos]-'0')),l0&(!i));
        else res+=dfs(pos-1,fr*i,lim&(i==(n[pos]-'0')),l0&(!i));
    }
    if(!l0&&!lim)   mp[pos][fr]=res;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    stack<char> st;
    for(auto e:n)   st.push(e);
    n.clear();
    while(!st.empty()){n+=st.top();st.pop();}
    cout<<dfs(n.length()-1,1,1,1)-1<<endl;
}
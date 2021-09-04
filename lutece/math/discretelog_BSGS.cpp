#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//https://oi-wiki.org/math/number-theory/bsgs/


int main()
{
    LL a,b,x,p;//a^x==b(mod p)
    cin>>a>>p>>b;
    unordered_map<LL,LL> hashtable;
    LL sp=ceil(sqrt(p));
    LL rhs=b%p;
    hashtable[rhs]=0;
    for(int i=1;i<=sp;i++)
    {
        rhs*=a;
        rhs%=p;
        hashtable[rhs]=i;
        // cout<<rhs<<' '<<i<<endl;
    }
    vector<LL> ans;
    LL lhs=1,mul=pow(a,sp);
    LL pos;
    for(int i=1;i<=sp;i++)
    {
        lhs*=mul;
        lhs%=p;
        if(hashtable.find(lhs)!=hashtable.end())
        {
            LL res=i*sp-(hashtable.find(lhs))->second;
            if(res>0)   ans.push_back(res);
        }
    }
    for(auto e:ans) cout<<e<<endl;
}
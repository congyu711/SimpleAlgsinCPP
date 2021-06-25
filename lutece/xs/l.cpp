#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
int n,k,q;
string s;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    cin>>s;
    
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
        // cout<<d1[i]<<endl;
    }
    LL ans=1;
    sort(d1.begin(),d1.end(),cmp);
    // for(auto e:d1)  cout<<e<<endl;
    priority_queue<int> pq;
    for(auto e:d1)
    {
        if(e!=0)   pq.push((((e-1)*2)+1));
    }
    for(int i=1;i<=q;i++)
    {
        if(pq.empty())
        {
            cout<<-1<<endl;
            return 0;
        }
        int c=pq.top();
        pq.pop();
        // cout<<c<<endl;
        ans*=c;
        ans%=mod;
        if(c!=1)    pq.push(c-2);
    }
    cout<<ans<<endl;
}
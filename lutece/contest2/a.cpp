#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;
LL n;
LL a[1010];
vector<LL> f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=10000;i++)
    {
        LL c= i*i;
        if(c>33000) break;
        f.push_back(c);
    }
    // for(auto e:f)   cout<<e<<' ';
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        bool ff=0;
        for(auto e:f)
        {
            if(a[i]>=e&&a[i]<=2*e&&(a[i]%((int)sqrt(e))==0))
            {
                cout<<1<<endl;
                ff=1;
                break;
            }
        }
        if(ff==0)    cout<<0<<endl;
    }
}
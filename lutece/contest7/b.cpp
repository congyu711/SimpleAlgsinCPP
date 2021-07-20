#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
const LL inf = INTMAX_MAX;
const int mod = 1e9 + 7;



void solve()
{
    string s;
    cin>>s;
    map<char,int> cnt;
    for(auto e:s)
    {
        cnt[e]++;
    }
    int ud=min(cnt['U'],cnt['D']);
    int lr=min(cnt['L'],cnt['R']);
    if(lr==0&&ud==0)    ;
    else if(lr==0)   ud=1;
    else if(ud==0)  lr=1;
    cout<<(ud+lr)*2<<endl;
    for(int i=1;i<=ud;i++)  cout<<"U";
    for(int i=1;i<=lr;i++)  cout<<"R";
    for(int i=1;i<=ud;i++)  cout<<"D";
    for(int i=1;i<=lr;i++)  cout<<"L";
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
}
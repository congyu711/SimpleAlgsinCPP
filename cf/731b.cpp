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
    int l=-1,r=-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a')   l=r=i;
    }
    if(l==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<s.length();i++)
    {
        char c=(char)('a'+i);
        bool f=0;
        if(l>0&&s[l-1]==c)
        {
            l--;
            f=1;
        }
        else if(r<(s.length()-1)&&s[r+1]==c)
        {
            r++;
            f=1;
        }
        if(f==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
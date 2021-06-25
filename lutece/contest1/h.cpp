#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
char d[12][12];
void solve()
{
    int first;
    cin>>first;
    int cnt=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        {
            cin>>d[i][j];
            if(d[i][j]=='.')    cnt++;
        }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}
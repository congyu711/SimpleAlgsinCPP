//https://codeforces.com/contest/1509/problem/A
#include<bits/stdc++.h>
using namespace std;

int t;
void solve()
{
    int n;
    cin>>n;
    vector<int> ji,ou;
    int tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        if(tmp%2)   ji.push_back(tmp);
        else ou.push_back(tmp);
    }
    for(auto e:ji)
        cout<<e<<' ';
    for(auto e:ou)
        cout<<e<<' ';
    cout<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        solve();
    }
}

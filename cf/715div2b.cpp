//https://codeforces.com/contest/1509/problem/B
#include<bits/stdc++.h>
using namespace std;

int t;
void solve()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    int numt=0,numm=0;
    if(a[0]=='M'||a[n-1]=='M')
    {
        cout<<"NO"<<endl;
        return ;
    }
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='T')numt++;
        else numm++;
    }
    if(numm*2!=numt)
    {
        cout<<"NO"<<endl;
        return ;
    }
    vector<int> leftp(n,0),leftm(n,0);
    leftp[0]=1;
    for(int i=1;i<a.length();i++)
    {
        if(a[i]=='T'){leftp[i]=leftp[i-1]+1;leftm[i]=leftm[i-1];}
        else {leftp[i]=leftp[i-1];leftm[i]=leftm[i-1]+1;}
    }
    vector<int> rightp(n,0),rightm(n,0);
    rightp[n-1]=1;
    for(int i=n-2;i>0;i--)
    {
        if(a[i]=='T'){rightp[i]=rightp[i+1]+1;rightm[i]=rightm[i+1];}
        else {rightp[i]=rightp[i+1];rightm[i]=rightm[i+1]+1;}
    }
    for(int i=0;i<=n-1;i++)
    {
        if(leftp[i]<leftm[i]||rightp[i]<rightm[i])
        {
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        solve();
}

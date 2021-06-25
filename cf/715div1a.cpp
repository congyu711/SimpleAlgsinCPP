#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
/*
this code got wa on testcase 2
because when n=3
001111
110110
000000
diff12=diff13=diff23=4>3

int diff12, diff23, diff13;
void solve()
{
    diff12 = diff23 = diff13 = 0;

    string a[4];
    int n;
    cin >> n;
    char c;
    for (int i = 1; i <= 3; i++)
        cin >> a[i];
    vector<int> ans(3 * n+2, 0);
    for (int i = 0; i <= 2 * n - 1; i++)
    {
        if (a[1][i] != a[2][i])
            diff12++;
        if (a[1][i] != a[3][i])
            diff13++;
        if (a[2][i] != a[3][i])
            diff23++;
    }

    cout<<12<<' '<<diff12<<endl;
    cout<<13<<' '<<diff13<<endl;
    cout<<23<<' '<<diff23<<endl;
    int aa, bb;

    if (diff12 <= n)
        aa = 1, bb = 2;
    else if (diff23 <= n)
        aa = 2, bb = 3;
    else
        aa = 1, bb = 3;
    int cnt = 0;
    cout<<"ab"<<aa<<bb<<endl;
    for (int i = 0; i <= n * 2 - 1; i++)
    {
        if (a[aa][i] == a[bb][i])
        {
            ans[cnt++] = a[aa][i] - '0';
            //cout<<ans[cnt-1]<<endl;
        }
        else
        {
            ans[cnt++] = a[aa][i] - '0';
            ans[cnt++] = a[bb][i] - '0';
            //cout<<ans[cnt-1]<<endl;
        }
    }
    for(int i=0;i<3*n;i++)  cout<<ans[i];
    cout << endl;
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
*/
string getans(string a,string b,char c)
{
    string ans;
    vector<int> posa={-1},posb={-1};
    int n=a.length()/2;
    for(int i=0;i<2*n;i++)
    {
        if(a[i]==c) posa.push_back(i);
        if(b[i]==c) posb.push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=posa[i]+1;j<posa[i+1];j++)
            ans+=a[j];
        for(int j=posb[i]+1;j<posb[i+1];j++)
            ans+=b[j];
        ans+=c;
    }
    for(int j=posa[n]+1;j<n*2;j++)
        ans+=a[j];
    for(int j=posb[n]+1;j<n*2;j++)
        ans+=b[j];
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> more0,more1;
    string a;
    for (int i = 0; i < 3; i++)
    {
        int cnt0=0,cnt1=0;
        cin >> a;
        for(auto e:a)
            if(e=='0') cnt0++;
        if(cnt0>=n)   more0.push_back(a);
        else more1.push_back(a);
    }
    if(more1.size()>=2) cout<<getans(more1[0],more1[1],'1')<<endl;
    else cout<<getans(more0[0],more0[1],'0')<<endl;
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
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll cnt0 = 0, cntp = 0;
    for (ll i = 0; i < n; i++)
        if (s[i] == '0')
            cnt0++;
    for (ll i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            cntp++;
    if(cntp==0)
    {
        if(cnt0==1||cnt0%2==0)  cout<<"BOB"<<endl;
        else cout<<"ALICE"<<endl;
        return;
    }
    if (cntp == 1&&cnt0==2)
    {
        cout << "DRAW" << endl;
        return;
    }
    cout << "ALICE" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
}

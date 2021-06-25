//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N = 1e5 + 10;
int arr[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int ans = 0, chafen = 0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > 0)
            break;
        ans++;
        if(i!=1)
        chafen=min(chafen,arr[i]-arr[i-1]);
    }
    if (ans == n)
    {
        cout << ans << endl;
        return;
    }
    if(arr[ans+1]<=chafen)
    {
        cout<<ans+1<<endl;
        return;
    }
    cout<<ans<<endl;
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

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, k;
int arr[N];
LL getans(int l, int r, int len, int num) //len 数周长度 num书的个书
{
    LL res = 0;
    while (num > 1)
    {
        LL e=1;
        e*=len;
        e*=(num-1);
        res += e;
        len = arr[r - 1] - arr[l + 1];  l++, r--;
        num -= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("a.in");
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);

    LL ans = 0;
    ans += getans(1, n, arr[n] - arr[1], k);
    cout << ans << endl;
    //baoli
    // int res=0;
    // do
    // {
    //     int e=0;
    //     for(int i=1;i<=k;i++)
    //     {
    //         for(int j=i;j<=k;j++)
    //             e+=abs(arr[i]-arr[j]);
    //     }
    //     res=max(e,res);
    // } while (next_permutation(arr+1,arr+n+1));
    // cout<<res<<endl;
}

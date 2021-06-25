#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if ((n - 1) / 2 < k)
        {    cout << -1 << endl;continue;}
        for(int i=1;i<=n-k;i++)
        {
            if(i<=k) cout<<i<<' '<<n-i+1<<' ';
            else cout<<i<<' ';
        }
        cout<<endl;
    }
}
// 5
// 1 0
// 5 2
// 6 6
// 2 1
// 6 1

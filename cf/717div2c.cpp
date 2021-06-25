//
#include <bits/stdc++.h>
using namespace std;

int arr[105];
long long int sum;
vector<int> ans;
bool dp[101][200002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2!=0)
    {
        cout << 0 << endl;
        return 0;
    }
    bool flag = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum / 2; j++)
        {
            dp[i][j] = (j >= arr[i - 1] && dp[i - 1][j - arr[i - 1]]) || dp[i - 1][j];
        }
        if (dp[i][sum / 2] == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int gcd = arr[1];
    for (int i = 2; i <= n; i++)
        gcd = __gcd(gcd, arr[i]);
    for (int i = 1; i <= n; i++)
        arr[i] /= gcd;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] % 2)
        {
            cout << 1 << endl;
            cout << i << endl;
            return 0;
        }
    }
}
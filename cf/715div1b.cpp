//https://codeforces.com/contest/1508/problem/B
#include <bits/stdc++.h>
using namespace std;

int t;
void solve()
{
    long long n, k;
    cin >> n >> k;
    if (n < 62 && k > 1LL << (n - 1))
    {
        cout << "-1\n";
        return;
    }
    stack<int> t;
    vector<int> arr = {0};
    k--;
    while (k)
    {
        if (k % 2)
            t.push(1);
        else
            t.push(0);
        k >>= 1;
    }
    while (!t.empty())
    {
        arr.push_back(t.top());
        t.pop();
    }
    map<int, int> mp;
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] == 1)
        {
            int st = i - 1;
            while (i < arr.size() - 1 && arr[i + 1] == 1)
                i++;
            mp[st] = i;
        }
    int ad = n - arr.size();
    for (int i = 1; i <= ad; i++)
        cout << i << ' ';
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 1)
            for (int k = mp[i - 1]; k >= i - 1; k--)
                cout << ad + k + 1 << ' ';
        else
            if (i < arr.size() - 1 && arr[i + 1] == 1)
                ;
            else
                cout << i + ad + 1 << ' ';
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    solve();
}

//
#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    int cnt = 0;
    vector<int> arr(t - 1, 0);
    long long int p = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (__gcd(t, i + 1) == 1)
        {
            cnt++;
            arr[i] = i + 1;
            p *= arr[i];
            p %= t;
        }
    }
    if (p != 1)
    {
        cnt--;
        arr[p - 1] = 0;
    }
    cout<<cnt<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << ' ';
    }
}

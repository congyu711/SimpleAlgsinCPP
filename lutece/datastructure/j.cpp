#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n;
int a[N], num[N];
int cnt[N];
int sza, szb;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num + 1, num + 1 + n);
    int un = unique(num + 1, num + 1 + n) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1, num + 1 + un, a[i]) - num;
    int ans=0;
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;
    priority_queue<int> pq;
    for(int i=1;i<=un;i++)
        pq.push(cnt[i]);
    while(pq.size()>=3)
    {
        int f1=pq.top();
        pq.pop();
        int f2=pq.top();
        pq.pop();
        int f3=pq.top();
        pq.pop();
        if(f1>0&&f2>0&&f3>0) ans++;
        if(f1-1>0)
        pq.push(f1-1);
        if(f2-1>0)
        pq.push(f2-1);
        if(f3-1>0)
        pq.push(f3-1);
    }
    cout<<ans<<endl;
}
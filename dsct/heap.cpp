#include <bits/stdc++.h>
using namespace std;
int N, n = 30, k;
vector<int> h(n + 2);
void up(int x)
{
    while (x > 1 && h[x] < h[x / 2])
    {
        swap(h[x], h[x / 2]);
        x /= 2;
    }
}
void down(int x)
{
    while (x * 2 <= n)
    {
        int t = x * 2;
        if (t + 1 <= n && h[t + 1] < h[t])
            t++;
        if (h[t] >= h[x])
            break;
        swap(h[x], h[t]);
        x = t;
    }
}
void build()
{
    for(int i=n;i>=1;i--)
        down(i);
}
int main()
{
    ifstream fin("heap.in");
    fin >> N >> n;
    for (int i = 1; i <= n; i++)
    {
        fin>>h[i];
    }
    build();
    for(int i=n+1;i<=N;i++)
    {
        fin>>h[n+1];
        if(h[n+1]>h[1])
            swap(h[n+1],h[1]);
        down(1);
    }
    for(int i=1;i<=n;i++)   cout<<h[i]<<' ';
}
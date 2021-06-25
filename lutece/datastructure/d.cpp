#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int l[N], r[N], v[N];
int p[N];
int main()
{
    int n, q;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        v[i] = t;
        if (i != 1)
            l[i] = i - 1;
        if (i != n)
            r[i] = i + 1;
        p[t] = i;
    }
    r[0] = 1;
    l[1] = 0;
    r[n]=n+1;
    l[n+1]=n;
    bool re = 0;
    for (int i = 1; i <= q; i++)
    {
        int opt, a, b;
        cin >> opt;
        if (opt == 4)
            re ^= 1;
        if (opt == 1)
        {
            cin >> a >> b; //p[a]-->p[b].l or r
            if (re)        //left
            {
                int t = p[a], s = p[b];
                int lt = l[t], rt = r[t];
                if(v[l[s]]==v[t])   continue;
                l[t] = l[s];
                r[t] = s;
                r[l[s]] = t;
                l[s] = t;
                r[lt] = rt;
                l[rt] = lt;
            }
            else //right
            {
                int t = p[a], s = p[b];
                int lt = l[t], rt = r[t];
                if(v[r[s]]==v[t])   continue;
                l[t] = s;
                r[t] = r[s];
                l[r[s]] = t;
                r[s] = t;
                r[lt] = rt;
                l[rt] = lt;
            }
        }
        if (opt == 2)
        {
            cin >> a >> b;
            if (re) //right
            {
                int t = p[a], s = p[b];
                int lt = l[t], rt = r[t];
                if(v[r[s]]==v[t])   continue;
                l[t] = s;
                r[t] = r[s];
                l[r[s]] = t;
                r[s] = t;
                r[lt] = rt;
                l[rt] = lt;
            }
            else //left
            {
                int t = p[a], s = p[b];
                int lt = l[t], rt = r[t];
                if(v[l[s]]==v[t])   continue;
                l[t] = l[s];
                r[t] = s;
                r[l[s]] = t;
                l[s] = t;
                r[lt] = rt;
                l[rt] = lt;
            }
        }
        if (opt == 3)
        {
            cin>>a>>b;
            swap(p[a], p[b]);
            v[p[a]] = a;
            v[p[b]] = b;
        }
    }
    if (!re)
    {
        int c = 0;
        while (r[c] != 0)
        {
            c = r[c];
            if(v[c]!=0)
            cout << v[c] << ' ';
        }
        cout<<endl;
    }
    else{
        int c=0;
        while(r[c]!=0)
        {
            c=r[c];
        }
        while(l[c]!=0)
        {
            if(v[c]!=0)cout<<v[c]<<' ';c=l[c];
        }
        cout<<v[c]<<' ';
        cout<<endl;
    }
}
/*
5 3
1 2 3 4 5
1 5 4
3 1 5
2 2 3

*/
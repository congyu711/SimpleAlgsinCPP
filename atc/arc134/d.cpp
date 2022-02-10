#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int n;
int a[N];
vector<int> ansl, ansr;
void solve(int l, int rfirst)
{
    if(l>n) return;
    vector<int> lmin;
    int minn = inf;
    for (int i = l; i <= n; i++)
        minn = min(minn, a[i]);
    int ll = minn;
    if(ll>=rfirst)  return;
    for (int i = l; i <= n; i++)
        if (a[i] == minn)
            lmin.push_back(i);
    minn = inf;
    for (auto e : lmin)
        minn = min(minn, a[n + e]);
    if (minn <= ll)
    {
        for (int i = l + n; i <= n * 2; i++)
            if (a[i] == minn)
            {
                ansl.push_back(a[i-n]);
                ansr.push_back(a[i]);
                return;
            }
    }
    else
    {
        for(auto e:lmin)
        {
            ansl.push_back(a[e]);
            ansr.push_back(a[e+n]);
        }
        vector<int> sufmin(n+1);
        sufmin[n]=a[n];
        for(int i=n-1;i>=0;i--) sufmin[i]=min(sufmin[i+1],a[i]);

        l=lmin.back()+1;
        while(l<=n)
        {
            int csufmin=sufmin[l];
            
            while(a[l]!=csufmin)    l++;
            if(csufmin<ansr[0])
            {
                while(sufmin[l]==csufmin)
                {
                    if(a[l]==csufmin)
                        ansl.push_back(a[l]),ansr.push_back(a[l+n]);
                    l++;

                }
            }
            else if(csufmin>ansr[0])    return;
            else    //csufmin==ansr[0]
            {
                if(ansr[1]<=csufmin)    return;
                while(sufmin[l]==csufmin)
                {
                    if(a[l]==csufmin)
                        ansl.push_back(a[l]),ansr.push_back(a[l+n]);
                    l++;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
        cin >> a[i];
    solve(1,inf);
    for(auto e:ansl)    cout<<e<<' ';
    for(auto e:ansr)    cout<<e<<' ';
    cout<<endl;
}
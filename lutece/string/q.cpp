#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e6 + 10;
const LL mod1 = 1e9 + 7;
string txt, pat;
int pi[N*2];
LL ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> txt >> pat;
    int n=pat.length();
    pat=pat+'#'+txt;
    for(int i=1;i<pat.length();i++)
    {
        int k=pi[i-1];
        while(k>0&&pat[i]!=pat[k])  k=pi[k-1];
        if(pat[k]==pat[i])  k++;
        pi[i]=k;
        if(pi[i]==n)    ans++;
    }
    cout << ans << endl;
}
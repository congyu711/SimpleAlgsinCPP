#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
map<string, int> mp;
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    // cout << mp[a] << mp[b] << mp[c] << endl;
    int n1,n2,n3;
    n1=mp[a],n2=mp[b],n3=mp[c];
    if(n2<n1)   n2+=12;
    if(n3<n2)   n3+=12;
    if(n2-n1==4&&n3-n2==3)
    {
        cout<<"Major triad"<<endl;
        return;
    }
    if(n2-n1==3&&n3-n2==4)
    {
        cout<<"Minor triad"<<endl;
        return;
    }
    else
        cout<<"Dissonance"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp["C"] = 1;
    mp["C#"] = 2;
    mp["D"] = 3;
    mp["D#"] = 4;
    mp["E"] = 5;
    mp["F"] = 6;
    mp["F#"] = 7;
    mp["G"] = 8;
    mp["G#"] = 9;
    mp["A"] = 10;
    mp["A#"] = 11;
    mp["B"] = 12;

    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
5
D F# A
E G B
B D# F#
C B C
E D C
*/
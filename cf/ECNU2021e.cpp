//
#include <bits/stdc++.h>
using namespace std;

vector<int> vec[100010];
bool vis[100010];
int a, b;
bool clr[100010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cin >> a >> b;
    queue<int> q;
    q.push(1);
    clr[1] = 1;
    vis[1]=1;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        vis[c]=1;
        for (int i = 0; i < vec[c].size(); i++)
        {
            if(!vis[vec[c][i]])
                q.push(vec[c][i]);
            clr[vec[c][i]] = !clr[c];
        }
    }
    if (clr[a] == clr[b])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

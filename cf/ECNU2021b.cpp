//https://codeforces.com/gym/103048/problem/B
#include <bits/stdc++.h>
using namespace std;
long long int getn(const string &a, int i, int len)
{
    long long int ans = 0;
    for (int j = 0; j < len; j++)
        ans = ans * 10 + (a[i + j] - '0');
    return ans;
}
long long int _pow(int n)
{
    long long int ans = 1;
    for (int i = 0; i < n; i++)
        ans *= 10;
    return ans;
}
void solve()
{
    string s="1516";
    // cin >> s;
    for (int len = 1; len <= s.length(); len++) //长度
    {
        for (int st = 0; st < len; st++) //起点
        {
            long long int c = getn(s, st, len);
            if (st != 0)
            {
                long long int tmp = (c - 1) % (_pow(st));
                if (getn(s, 0, st) != tmp)
                    break;
            }
            int clen = len;
            int i = st + clen;
            for (; i < s.length(); i += clen) //计算每一个数是否符合标准
            {
                if (c % 10 != 9 && (c + 1) != getn(s, i, clen))
                    break;
                if (c % 10 == 9)
                    clen++;
                if ((c + 1) != getn(s, i, clen))
                    break;
                //c=c+1;

            }
            bool ff=0;
            // if(i==s.length())   ff=1;
            if(i>=s.length()) i-=clen;
            if (i+clen>=s.length())
            {
                string arr=to_string(c);
                bool f=0;
                for(int k=0;k<s.length()-i-1;k++)
                {
                    if(arr[k]!=s[i+k+1])f=1;
                }
                if(f==0)
                {
                    cout<<c+1<<endl;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
//不行不行不会写了
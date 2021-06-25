#include <bits/stdc++.h>
//#define mod 1000000007
#define mod 998244353
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define ll long long int
#define pr(a) pair<a, a>
#define ff first
#define ss second
#define pub push_back
#define pob pop_back
#define f(i, a, b) for (int i = a; i <= b; i++)
#define r(i, a, b) for (int i = a; i >= b; i--)
#define ms(a, b) memset(a, b, sizeof(a))
#define line cout << '\n'
#define all(v) v.begin(), v.end()
#define rev(s) reverse(all(s))
using namespace std;
 
void Precompute(vector<ll> &v) {
 
    f(i, 2, 1000000) {
 
        ll j = i;
 
        while(j <= 1000000) {
 
            v[j]++;
 
            j += i;
        }
    }
}
 
ll modInverse(ll x, ll y) {
 
    if (y == 0) {
        
        return 1;
    }
 
    ll p = modInverse(x, y / 2) % mod;
 
    p = (p * p) % mod;
 
    return (y % 2 == 0) ? p : (x * p) % mod;
}
 
ll modExp(ll a, ll n) {
 
    ll ans = 1;
 
    a = a % mod;
 
    while (n > 0) {
 
        if (n % 2) {
 
            ans = (ans * a) % mod;
        }
 
        n /= 2;
        a = (a * a) % mod;
    }
 
    return ans;
}
 
int main() {
 
    
    ofstream of;
    of.open("std.out");
    vector<ll> count(1000001, 1);
 
    Precompute(count);
 
    int tt = 1;
    //cin >> tt;
 
    f(t, 1, tt) {
        
        ll n;
        cin >> n;
        
        ll dp[n + 2];
 
        dp[1] = 1;
 
        dp[2] = 3;
 
        ll sum = dp[1] + dp[2];
 
        f(i, 3, n) {
 
            dp[i] = (sum + count[i]) % mod;
 
            sum = (sum + dp[i]) % mod; 
            of<<dp[i]<<endl;
        }
 

 
        line;
    }
 
    return 0;
}
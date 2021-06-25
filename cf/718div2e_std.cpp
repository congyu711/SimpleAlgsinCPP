// Problem : E. Group Photo
// Contest : Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1517/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <string>
#include <iostream>
#include <algorithm>
#define _N 200005
#define lint long long
#define _MOD 998244353LL
#define out(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << x << '\n'
using namespace std;
 
lint _arr[_N], _sig[_N], _sum[_N];
 
inline void solve() {
	int i, j, k, n, i2, mid;
	lint sum_p, sum_c, ans = 0ll;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> _arr[i];
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	for (i = 1; i <= n; ++i) {
		_sum[i] = _sum[i-1] + _arr[i];
		if (i == 1) _sig[i] = _arr[i];
		else _sig[i] = _sig[i-2] + _arr[i];
	}
	// PPPPP
	ans = 1ll;
	// P CCC PCPC PPP
	for (i = 2; i <= n; ++i) {
		sum_p = _sum[1] + _sum[n] - _sum[i];
		sum_c = _sum[i] - _sum[1];
		if (sum_c >= sum_p) break;
		j = 0;
		k = n - i >> 1;
		while (j <= k) {
			mid = j + k >> 1;
			i2 = i + mid * 2;
			sum_p = _sum[1] + _sum[n] - _sum[i2] + _sig[i2-1] - _sig[i-1];
			sum_c = _sig[i2] - _sig[i] + _sum[i] - _sum[1];
			if (sum_p > sum_c) j = mid + 1;
			else k = mid - 1;
		}
		ans = (ans + j) % _MOD;
	}
	// P CCC PCPC PPP C
	for (i = 2; i + 2 < n; ++i) {
		sum_p = _sum[1] + _sum[n-1] - _sum[i];
		sum_c = _sum[i] - _sum[1] + _arr[n];
		if (sum_c >= sum_p) break;
		j = 0;
		k = n - i - 3 >> 1;
		while (j <= k) {
			mid = j + k >> 1;
			i2 = i + mid * 2;
			sum_p = _sum[1] + _sum[n-1] - _sum[i2] + _sig[i2-1] - _sig[i-1];
			sum_c = _sig[i2] - _sig[i] + _sum[i] - _sum[1] + _arr[n];
			if (sum_p > sum_c) j = mid + 1;
			else k = mid - 1;
		}
		ans = (ans + j) % _MOD;
	}
	// (CCC PCPC) PPP
	for (i = 1; i <= n; ++i) {
		sum_c = _sum[i];
		sum_p = _sum[n] - _sum[i];
		if (sum_c >= sum_p) break;
		j = 0;
		k = n - i >> 1;
		while (j <= k) {
			mid = j + k >> 1;
			i2 = i + mid * 2;
			sum_p = _sum[n] - _sum[i2] + _sig[i2-1] - _sig[i-1];
			sum_c = _sum[i] + _sig[i2] - _sig[i];
			if (sum_p > sum_c) j = mid + 1;
			else k = mid - 1;
		}
		ans = (ans + j) % _MOD;
	}
	// CCC PCPC PPP C
	for (i = 1; i + 2 < n; ++i) {
		sum_c = _sum[i] + _arr[n];
		sum_p = _sum[n-1] - _sum[i];
		if (sum_c >= sum_p) break;
		j = 0;
		k = n - i - 3 >> 1;
		while (j <= k) {
			mid = j + k >> 1;
			i2 = i + mid * 2;
			sum_p = _sum[n-1] - _sum[i2] + _sig[i2-1] - _sig[i-1];
			sum_c = _sum[i] + _sig[i2] - _sig[i] + _arr[n];
			if (sum_p > sum_c) j = mid + 1;
			else k = mid - 1;
		}
		ans = (ans + j) % _MOD;
	}
	// PPP CCC
	for (i = 2; i < n; ++i) {
		sum_p = _sum[i];
		sum_c = _sum[n] - _sum[i];
		if (sum_p > sum_c) ans = (ans + 1) % _MOD;
	}
	cout << ans << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	while (cin >> t)
		while (t--)
			solve();
	return 0;
}
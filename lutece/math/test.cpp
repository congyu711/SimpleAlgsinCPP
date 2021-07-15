#include<bits/stdc++.h>
using namespace std;
const int n = 4;
int a[n] = { 1,2,3,4 };
bitset <n> b;
int sum = 0;
void dfs(int index)
{
	if (index == n)
	{
		for (int i = 0;i < n;i++)
		{
			cout << a[i];
		}
		sum += 1;
		cout << endl;
		return;
	}
	for (int i = 0;i < n;i++)
	{
		if (b[i] == 0)
		{
			b[i] = 1;
			a[index] = i + 1;
			dfs(index + 1);
			b[i] = 0;
		}
	}
}
int main()
{
	dfs(0);
	cout << sum << endl;
	return 0;
}

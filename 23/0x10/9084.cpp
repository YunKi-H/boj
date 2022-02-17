// https://www.acmicpc.net/problem/9084
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int coin[21];
int t, n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> coin[i];
		cin >> m;
		fill(dp, dp + m + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= m; j++)
				if(j - coin[i] >= 0)
					dp[j] += dp[j - coin[i]];
		}
		cout << dp[m] << '\n';
	}
}

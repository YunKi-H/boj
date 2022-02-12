// https://www.acmicpc.net/problem/2193
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[91][2] = {{0, 0}, {0, 1}, {1, 0}, };

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][0] + dp[n][1];
}

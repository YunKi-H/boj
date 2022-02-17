// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000000

int n;
long long dp[101][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fill(dp[1] + 1, dp[1] + 10, 1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			if (dp[i][j] > mod)
				dp[i][j] -= mod;
		}
	}
	for (int i = 1; i <= 9; i++)
		dp[n][0] += dp[n][i];
	cout << dp[n][0] % mod;
}
